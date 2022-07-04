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
#include "IParticipantProperties.h"

/**
 * \brief A participant in a channel.
 *
 * \remarks The key for this interface is an account name returned by AccountId::Name().
 */
class VIVOXCORE_API IParticipant : public IParticipantProperties
{
public:
    /**
     * \brief Identifies the participant's specific sign in location.
     * \remarks Rarely used. In most implementations, use IParticipant::Account() as a unique identifier for participants in a channel instead of ParticipantId().
     * ParticipantId() is not the same as Account, but is the same as IPresenceLocation::LocationId(). The Account() of each participant is unique. 
     * Accounts cannot be connected to a ChannelSession from multiple locations (the location for the latest ChannelSession connection overrides locations from earlier ChannelSession connections).
     * This will match a particular presence location when a user is signed in from more than one location.
     */
    virtual const FString &ParticipantId() const = 0;

    /**
     * \brief The ChannelSession that owns this participant.
     */
    virtual IChannelSession &ParentChannelSession() const = 0;

    /**
     * \brief The AccountId associated with this participant.
     */
    virtual const AccountId &Account() const = 0;
};
