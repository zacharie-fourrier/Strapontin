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
#include "VivoxCoreCommon.h"
#include "ITTSMessage.h"

/**
 * \brief An interface for events and methods related to text-to-speech (TTS).
 */
class VIVOXCORE_API ITextToSpeech
{
public:
    DECLARE_EVENT_ThreeParams(ITextToSpeech, PlaybackStarted, unsigned int, const ITTSMessage &, double);
    DECLARE_EVENT_TwoParams(ITextToSpeech, PlaybackCompleted, unsigned int, const ITTSMessage &);
    DECLARE_EVENT_TwoParams(ITextToSpeech, PlaybackFailed, VivoxCoreError, const ITTSMessage &);
public:
    /**
     * \brief Destructor
     */
    virtual ~ITextToSpeech() = default;

    /**
     * \brief All voices available to the text-to-speech subsystem for speech synthesis, indexed by name.
     */
    virtual const TMap<FString, ITTSVoice*> &GetAvailableVoices() = 0;

    /**
     * \brief The voice used by text-to-speech methods called from this ILoginSession.
     * \return The voice previously set with SetCurrentVoice(), or the SDK default voice if never set.
     */
    virtual const ITTSVoice &GetCurrentVoice() = 0;

    /**
     * \brief Set the voice used by text-to-speech methods called from this ILoginSession.
     * \param newVoice A valid ITTSVoice obtained from GetAvailableVoices() to use as this user's voice.
     * \return True if a new value is set, false if a voice is not available (for example, if a voice is loaded from saved settings).
     */
    virtual bool SetCurrentVoice(const ITTSVoice &newVoice) = 0;

    /**
     * \brief Inject a new text-to-speech (TTS) message into the specified destination.
     * \param text The text to be converted into speech.
     * \param destination Determines the output stream and mechanism for TTS injection.
     * \param outMessage [out, optional] An object that holds properties related to this TTS message.
     * \remarks For information on how the ITTSVoice used for speech synthesis is selected, see GetCurrentVoice().
     */
    virtual VivoxCoreError Speak(const FString &text, const TTSDestination &destination, ITTSMessage **outMessage = nullptr) = 0;

    /**
     * \brief Inject a new text-to-speech message into an audio buffer for direct use.
     * \param text The text to be converted into speech.
     * \param outBuffer [out] An object that contains raw audio data and metadata, such as buffer length and audio format properties.
     * \remarks For information on how the ITTSVoice used for speech synthesis is selected, see GetCurrentVoice().
     */
    virtual VivoxCoreError SpeakToBuffer(const FString &text, ITTSAudioBuffer **outBuffer) = 0;

    /**
     * \brief Cancel a single currently playing or enqueued text-to-speech message.
     * \param message The ITTSMessage to cancel.
     * \remarks In destinations with queues, canceling an ongoing message automatically triggers the playback of the next message.
     * Canceling an enqueued message shifts all later messages up one place in the queue.
     */
    virtual VivoxCoreError CancelMessage(const ITTSMessage &message) = 0;

    /**
     * \brief Cancel all text-to-speech messages in a destination (ongoing and enqueued).
     * \param destination The TTSDestination to clear of messages.
     * \remarks The TTSDestinations QueuedRemoteTransmission and QueuedRemoteTransmissionWithLocalPlayback
     * share a queue, but are not the same destination. Canceling all messages in one of these destinations
     * automatically triggers the playback of the next message from the other destination in the shared queue.
     */
    virtual VivoxCoreError CancelDestination(const TTSDestination &destination) = 0;

    /**
     * \brief Cancel all text-to-speech messages (ongoing and enqueued) from all destinations.
     */
    virtual VivoxCoreError CancelAll() = 0;

    /**
     * \brief Retrieve ongoing or enqueued text-to-speech (TTS) messages that were previously created by using Speak().
     * \param destination The TTSDestination to retrieve messages for.
     * \return An array of all TTS messages that are playing or enqueued in the specified destination.
     */
    virtual const TArray<ITTSMessage *> &GetMessages(const TTSDestination &destination) = 0;

    /**
     * \brief An event that indicates a text-to-speech (TTS) message has finished preparing for playback and is starting to play.
     * \param numConsumers The number of active sessions (for remote playback destinations), local players (for local playback destinations),
     * or both, that the TTS message is playing into.
     * \param message The ITTSMessage that corresponds to this speech.
     * \param messageDuration The duration of the synthesized voice clip in seconds.
     */
    PlaybackStarted EventPlaybackStarted;

    /**
     * \brief An event that indicates a text-to-speech (TTS) message has finished playback.
     * \param numConsumers The number of active sessions (for remote playback destinations), local players (for local playback destinations),
     * or both, that the TTS message is playing into.
     * \param message The ITTSMessage that corresponds to this speech.
     * \remarks This event is raised regardless of whether playback is stopped early by using the various Cancel*() methods,
     * is replaced by a new message (TTSDestination.ScreenReader only), or if the voice clip has reached its natural end.
     * When this event is received, the correponding ITTSMessage can no longer be obtained by using GetMessages().
     */
    PlaybackCompleted EventPlaybackCompleted;

    /**
     * \brief An event that indicates playback of a text-to-speech message has failed.
     * \param status The error code of the failure.
     * \param message The ITTSMessage that corresponds to this speech.
     * \remarks When this event is received, the correponding ITTSMessage can no longer be obtained by using GetMessages().
     */
    PlaybackFailed EventPlaybackFailed;
};
