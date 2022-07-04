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

/**
 * \brief Transcribed text from a participant in a channel session.
 */
class VIVOXCORE_API ITranscribedMessage
{
public:
    /**
     * \brief Destructor
     */
    virtual ~ITranscribedMessage() = default;
    /**
     * \brief The time that the transcription was received in UTC.
     */
    virtual const FDateTime &ReceivedTime() const = 0;
    /**
     * \brief The transcribed text.
     */
    virtual const FString &Text() const = 0;
    /**
     * \brief The speaker.
     */
    virtual const AccountId &Speaker() const = 0;
    /**
     * \brief The language of the transcribed text. This conforms to BCP 47 (https://tools.ietf.org/html/bcp47).
     */
    virtual const FString &Language() const = 0;
    /**
     * \brief The ChannelSession in which this message was originally spoken.
     */
    virtual IChannelSession &ChannelSession() const = 0;
};
