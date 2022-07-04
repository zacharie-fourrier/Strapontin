/* Copyright (c) 2014-2018 by Mercer Road Corp
 *
 * Permission to use, copy, modify or distribute this software in binary or source form
 * for any purpose is allowed only under explicit prior consent in writing from Mercer Road Corp
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND MERCER ROAD CORP DISCLAIMS
 * ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL MERCER ROAD CORP
 * BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
 * ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 */

#include "TextToSpeech.h"
#include "ClientImpl.h"
#include "VivoxNativeSdk.h"

TextToSpeech::TextToSpeech(ClientImpl &client) : _client(client)
{
}

TextToSpeech::~TextToSpeech()
{
    CleanupTTS();
}

void TextToSpeech::HandleEvent(const vx_evt_base_t& evt)
{
    if (evt.type == evt_tts_injection_started) {
        const vx_evt_tts_injection_started_t &tevt = reinterpret_cast<const vx_evt_tts_injection_started_t &>(evt);
        ITTSMessage *matchingMessage = GetITTSMessageFromEvt((TTSDestination)tevt.tts_destination, tevt.utterance_id);
        if (nullptr != matchingMessage) {
            ((TTSMessageImpl*)matchingMessage)->SetPlaying();
            EventPlaybackStarted.Broadcast(tevt.num_consumers, *matchingMessage, tevt.utterance_duration);
        }
    } else if (evt.type == evt_tts_injection_ended) {
        const vx_evt_tts_injection_ended_t &tevt = reinterpret_cast<const vx_evt_tts_injection_ended_t &>(evt);
        ITTSMessage *matchingMessage = GetITTSMessageFromEvt((TTSDestination)tevt.tts_destination, tevt.utterance_id);
        if (nullptr != matchingMessage) {
            ITTSMessage *completedMessage = new TTSMessageImpl(*(TTSMessageImpl*)matchingMessage);
            _ttsMessages[(TTSDestination)tevt.tts_destination].RemoveSingle(matchingMessage);
            EventPlaybackCompleted.Broadcast(tevt.num_consumers, *completedMessage);
        }
    } else if (evt.type == evt_tts_injection_failed) {
        const vx_evt_tts_injection_failed_t &tevt = reinterpret_cast<const vx_evt_tts_injection_failed_t &>(evt);
        ITTSMessage *matchingMessage = GetITTSMessageFromEvt((TTSDestination)tevt.tts_destination, tevt.utterance_id);
        if (nullptr != matchingMessage) {
            ITTSMessage *completedMessage = new TTSMessageImpl(*(TTSMessageImpl*)matchingMessage);
            _ttsMessages[(TTSDestination)tevt.tts_destination].RemoveSingle(matchingMessage);
            EventPlaybackFailed.Broadcast(tevt.status, *completedMessage);
        }
    }
}

const TMap<FString, ITTSVoice*> &TextToSpeech::GetAvailableVoices()
{
    // We can cache the available voices the first time we retrieve them since they won't change.
    // If they're already cached, or we can't initialize tts, return whatever we have.
    if (_ttsAvailableVoices.Num() > 0 || !_client.TTSInitialize())
        return _ttsAvailableVoices;

    int numVoices;
    vx_tts_voice_t *voices;
    VivoxCoreError status = VivoxNativeSdk::Get().TTSGetVoices(_client.GetTTSManagerId(), &numVoices, &voices);
    // If the call failed or there really aren't any voices, return. This doesn't cache anything, so it can be retried again.
    if (status != VxErrorSuccess || 0 == numVoices)
        return _ttsAvailableVoices;

    // We consider the first available voice returned the SDK default, to be used if no global or user default voice is chosen.
    if (numVoices > 0)
        _ttsSDKDefaultVoiceName = voices[0].name;
    // If there's at least one available voice, cache all available voices and return them.
    for (int i = 0; i < numVoices; ++i)
        _ttsAvailableVoices.Add(voices[i].name, new TTSVoiceImpl(voices[i]));
    return _ttsAvailableVoices;
}

const ITTSVoice &TextToSpeech::GetCurrentVoice()
{
    // If the current voice has already been set, or hasn't and can't be, return whatever it is.
    if (_ttsCurrentVoice.IsValid() || GetAvailableVoices().Num() == 0)
        return _ttsCurrentVoice;

    // If it hasn't been set and can be, set it to the SDK default.
    _ttsCurrentVoice = **_ttsAvailableVoices.Find(_ttsSDKDefaultVoiceName);

    return _ttsCurrentVoice;
}

bool TextToSpeech::SetCurrentVoice(const ITTSVoice &newVoice)
{
    // Check if an ITTSVoice with this name is available and return the one in the map (in case VoiceId has changed).
    // Guards against stale value loaded from saved settings, especially when using external TTS voices (e.g. from OS)
    // Must first access via GetAvailableVoices() instead of _ttsAvailableVoices in case it's uninitialized.
    if (GetAvailableVoices().Contains(newVoice.Name()))
    {
        _ttsCurrentVoice = **_ttsAvailableVoices.Find(newVoice.Name());
        return true;
    }
    return false;
}

VivoxCoreError TextToSpeech::Speak(const FString &text, const TTSDestination &destination, ITTSMessage **outMessage)
{
    _client.TTSInitialize();

    // outMessage is an optional [out] paramater for ITextToSpeech::Speak(), but we still need a message
    // from VivoxNativeSdk::TTSSpeak() for internal use. We'll set *outMessage at the end if it's passed in.
    ITTSMessage *outInternal = nullptr;
    VivoxCoreError status = VivoxNativeSdk::Get().TTSSpeak(_client.GetTTSManagerId(), GetCurrentVoice(), text, destination, &outInternal);
    if (outInternal && outInternal->IsValid())
    {
        TArray<ITTSMessage *> *destArray = _ttsMessages.Find(destination);
        if (destArray)
        {
            destArray->Add(outInternal);
        }
        else
        {
            TArray<ITTSMessage *> newArray;
            newArray.Add(outInternal);
            _ttsMessages.Add(destination, newArray);
        }
    }

    if (outMessage != nullptr)
        *outMessage = outInternal;

    return status;
}

VivoxCoreError TextToSpeech::SpeakToBuffer(const FString &text, ITTSAudioBuffer **outBuffer)
{
    _client.TTSInitialize();
    VivoxCoreError status = VivoxNativeSdk::Get().TTSSpeakToBuffer(_client.GetTTSManagerId(), GetCurrentVoice(), text, outBuffer);
    return status;
}

VivoxCoreError TextToSpeech::CancelMessage(const ITTSMessage &message)
{
    _client.TTSInitialize();
    VivoxCoreError status = VivoxNativeSdk::Get().TTSCancelMessage(_client.GetTTSManagerId(), message);
    // Playing messages will get removed when their evt_tts_injection_ended event is raised.
    if (message.State() == TTSMessageState::Enqueued && VxErrorSuccess == status)
        _ttsMessages[message.Destination()].RemoveSingle((ITTSMessage *)&message);
    return status;
}

VivoxCoreError TextToSpeech::CancelDestination(const TTSDestination &destination)
{
    _client.TTSInitialize();
    VivoxCoreError status = VivoxNativeSdk::Get().TTSCancelDestination(_client.GetTTSManagerId(), destination);
    if (VxErrorSuccess == status)
    {
        // Playing messages will get removed when their evt_tts_injection_ended event is raised.
        _ttsMessages[destination].RemoveAll([](ITTSMessage *Message) {
            return Message->State() == TTSMessageState::Enqueued;
        });
    }
    return status;
}

VivoxCoreError TextToSpeech::CancelAll()
{
    _client.TTSInitialize();
    VivoxCoreError status = VivoxNativeSdk::Get().TTSCancelAll(_client.GetTTSManagerId());
    if (VxErrorSuccess == status)
    {
        // Playing messages will get removed when their evt_tts_injection_ended event is raised.
        for (auto &Elem : _ttsMessages)
        {
            Elem.Value.RemoveAll([](ITTSMessage *Message) {
                return Message->State() == TTSMessageState::Enqueued;
            });
        }
    }
    return status;
}

const TArray<ITTSMessage *> &TextToSpeech::GetMessages(const TTSDestination &destination)
{
    const TArray<ITTSMessage *> *destArray = _ttsMessages.Find(destination);
    if (destArray)
        return *destArray;
    else
    {
        TArray<ITTSMessage *> newArray;
        _ttsMessages.Add(destination, newArray);
        return _ttsMessages[destination];
    }
}

ITTSMessage *TextToSpeech::GetITTSMessageFromEvt(const TTSDestination &destination, const TTSUtteranceId &utteranceId)
{
    const TArray<ITTSMessage *> *destArray = _ttsMessages.Find(destination);
    if (destArray)
    {
        // If this destination array exists and a message
        // matching utteranceId is found, return it.
        for (auto &elem : *destArray)
            if (elem->UtteranceId() == utteranceId)
                return elem;
    }
    // Otherwise return nullptr.
    return nullptr;
}

void TextToSpeech::CleanupTTS()
{
    _ttsAvailableVoices.Empty();
    _ttsSDKDefaultVoiceName = "";
    _ttsCurrentVoice = TTSVoiceImpl();
    _ttsMessages.Empty();
}
