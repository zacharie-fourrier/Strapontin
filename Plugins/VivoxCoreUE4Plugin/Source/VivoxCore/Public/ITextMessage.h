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
 * \brief A text message.
 */
class VIVOXCORE_API ITextMessage
{
public:
    /**
     * \brief Destructor
     */
    virtual ~ITextMessage() = default;
    /**
     * \brief The time that the message was received in UTC.
     */
    virtual const FDateTime &ReceivedTime() const = 0;
    /**
     * \brief The message.
     */
    virtual const FString &Message() const = 0;
    /**
     * \brief The sender.
     */
    virtual const AccountId &Sender() const = 0;
    /**
     * \brief The language of the message. This conforms to BCP 47 (https://tools.ietf.org/html/bcp47).
     */
    virtual const FString &Language() const = 0;
    /**
     * \brief An optional name space for application-specific data.
     */
    virtual const FString &ApplicationStanzaNamespace() const = 0;
    /**
     * \brief Optional application-specific data.
     */
    virtual const FString &ApplicationStanzaBody() const = 0;
};
