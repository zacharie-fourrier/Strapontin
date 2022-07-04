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
 * A subscription to another user for online status.
 */
class VIVOXCORE_API IPresenceSubscription
{
public:
    DECLARE_EVENT_OneParam(IPresenceSubscription, AfterLocationAdded, const IPresenceLocation &)
    DECLARE_EVENT_OneParam(IPresenceSubscription, AfterLocationUpdated, const IPresenceLocation &)
    DECLARE_EVENT_OneParam(IPresenceSubscription, BeforeLocationRemoved, const IPresenceLocation &)

public:
    virtual ~IPresenceSubscription() = default;
    /**
     * The account that this subscription pertains to.
     */
    virtual const AccountId &SubscribedAccount() const = 0;

    /**
     * The login session that owns this subscription.
     */
    virtual ILoginSession &LoginSession() = 0;
    /**
     * If the account associated with this subscription is signed in, then the Locations map has an entry for the location of each login session for that user.
     */
    virtual TMap<FString, IPresenceLocation *> Locations() const = 0;
    /**
    * This event is raised after a device has been added to the Locations() collection.
    */
    AfterLocationAdded EventAfterLocationAdded;

    /**
    * This event is raised after a device has been added to the Locations() collection.
    */
    AfterLocationUpdated EventAfterLocationUpdated;

    /**
    * This event is raised before a device is removed from the Locations() collection.
    */
    BeforeLocationRemoved EventBeforeLocationRemoved;
};
