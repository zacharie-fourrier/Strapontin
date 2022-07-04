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
#include "VivoxCoreCommon.h"

/**
* \brief The online status of the user.
*/
UENUM(BlueprintType)
enum class PresenceStatus : uint8
{
    /**
    * \brief Not available (offline).
    */
    Unavailable,
    /**
    * \brief Generally available.
    */
    Available,
    /**
    * \brief Available to chat.
    */
    Chat,
    /**
    * \brief Do Not Disturb.
    */
    DoNotDisturb,
    /**
    * \brief Away.
    */
    Away,
    /**
    * \brief Away for an extended period of time.
    */
    ExtendedAway
};

/**
 * \brief The presence information for a user at a location.
 */
class VIVOXCORE_API Presence
{
    PresenceStatus _currentStatus;
    FString _message;
public:
    /**
     * \brief Constructor
     */
    explicit Presence(PresenceStatus status = PresenceStatus::Unavailable, const FString &message = FString());

    /**
     * \brief The online status of the user.
     */
    PresenceStatus CurrentStatus() const;
    /**
     * \brief An optional message published by that user.
     */
    const FString &Message() const;
    /** \brief Equality operator */
    bool operator ==(const Presence &RHS) const;
    /** \brief Inequality operator */
    bool operator !=(const Presence &RHS) const;
};
