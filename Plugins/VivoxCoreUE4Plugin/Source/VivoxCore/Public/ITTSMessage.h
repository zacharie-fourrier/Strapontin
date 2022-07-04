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
#include "Engine/Blueprint.h"
#include "Containers/UnrealString.h"
#include "ITTSVoice.h"

/**
 * \brief A unified selection of output stream and mechanism for text-to-speech (TTS) injection.
 */
UENUM(BlueprintType)
enum class TTSDestination : uint8
{
    /**
     * \brief Do not use. This is only defined to work around a bug in UnrealBuildTool.
     */
    Default = 0,
    /**
     * \brief Immediately send to participants in connected sessions. Mixes new messages with any other ongoing messages.
     */
    RemoteTransmission = tts_dest_remote_transmission,
    /**
     * \brief Immediately play back locally on a render device (for example, speaker hardware). Mixes new messages with any other ongoing messages.
     */
    LocalPlayback = tts_dest_local_playback,
    /**
     * \brief Immediately play back locally on a render device and send to participants in connected sessions. Mixes new messages with any other ongoing messages.
     */
    RemoteTransmissionWithLocalPlayback = tts_dest_remote_transmission_with_local_playback,
    /**
     * \brief Send to participants in connected sessions, or enqueue if there is already an ongoing message playing in this destination.
     */
    QueuedRemoteTransmission = tts_dest_queued_remote_transmission,
    /**
     * \brief Play back locally on a render device (for example, speaker hardware), or enqueue if there is already an ongoing message playing in this destination.
     */
    QueuedLocalPlayback = tts_dest_queued_local_playback,
    /**
     * \brief Play back locally on a render device and send to participants in connected sessions. Enqueue if there is already an ongoing message playing in this destination.
     */
    QueuedRemoteTransmissionWithLocalPlayback = tts_dest_queued_remote_transmission_with_local_playback,
    /**
     * \brief Immediately play back locally on a render device (for example, speaker hardware). Replaces the currently playing message in this destination.
     */
    ScreenReader = tts_dest_screen_reader
};

/**
 * \brief The state of the TTSMessage.
 */
UENUM(BlueprintType)
enum class TTSMessageState : uint8
{
    /**
     * \brief The message is currently being played in its destination.
     */
    Playing,
    /**
     * \brief The message is waiting to be played in its destination.
     */
    Enqueued
};

typedef vx_tts_utterance_id TTSUtteranceId;

/**
  * \brief A spoken message in the text-to-speech subsystem.
  */
class VIVOXCORE_API ITTSMessage
{
public:
    virtual ~ITTSMessage() = default;

    /**
     * \brief The voice used to synthesize this message.
     */
    virtual const ITTSVoice &Voice() const = 0;

    /**
     * \brief The text to be synthesized into speech.
     */
    virtual const FString &Text() const = 0;

    /**
     * \brief The destination of this message.
     */
    virtual const TTSDestination &Destination() const = 0;

    /**
     * \brief An internal utterance identifier.
     */
    virtual const TTSUtteranceId &UtteranceId() const = 0;

    /**
     * \brief The Playing/Enqueued state of the message.
     */
    virtual const TTSMessageState &State() const = 0;

    /**
     * \brief True if created by using a non-default constructor and Text is not empty.
     */
    virtual bool IsValid() const = 0;
};
