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
 * \brief Presence information for a user signed in at a particular location.
 */
class VIVOXCORE_API IPresenceLocation
{
public:
    /**
     * \brief Destructor
     */
    virtual ~IPresenceLocation() = default;
    /**
     * \brief The unique identifier for this account's specific login session.
     */
    virtual const FString &LocationId() const = 0;

    /**
     * \brief The presence for this account at this location.
     */
    virtual const Presence &CurrentPresence() const = 0;

    /**
     * \brief The subscription that owns this presence location. This does not change and does not raise a PropertyChangedEvent.
     */
    virtual IPresenceSubscription &Subscription() const = 0;
};
