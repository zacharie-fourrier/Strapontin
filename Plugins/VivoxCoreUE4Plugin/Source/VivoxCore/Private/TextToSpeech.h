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

#pragma once

#include "ITextToSpeech.h"
#include "VivoxCoreCommonImpl.h"
#include "TTSMessageImpl.h"

/**
 *
 */
class TextToSpeech : public ITextToSpeech
{
    ClientImpl &_client;
    TMap<FString, ITTSVoice*> _ttsAvailableVoices;
    FString _ttsSDKDefaultVoiceName;
    TTSVoiceImpl _ttsCurrentVoice;
    TMap<TTSDestination, TArray<ITTSMessage *>> _ttsMessages;
public:
    TextToSpeech(ClientImpl &client);
    ~TextToSpeech();

    const TMap<FString, ITTSVoice*> &GetAvailableVoices() override;
    const ITTSVoice &GetCurrentVoice() override;
    bool SetCurrentVoice(const ITTSVoice &newVoice) override;
    VivoxCoreError Speak(const FString &text, const TTSDestination &destination, ITTSMessage **outMessage) override;
    VivoxCoreError SpeakToBuffer(const FString &text, ITTSAudioBuffer **outBuffer) override;
    VivoxCoreError CancelMessage(const ITTSMessage &message) override;
    VivoxCoreError CancelDestination(const TTSDestination &destination) override;
    VivoxCoreError CancelAll() override;
    const TArray<ITTSMessage *> &GetMessages(const TTSDestination &destination) override;

    // Internal
    virtual void HandleEvent(const vx_evt_base_t &evt);
    ITTSMessage *GetITTSMessageFromEvt(const TTSDestination &destination, const TTSUtteranceId &utteranceId);
    void CleanupTTS();
};
