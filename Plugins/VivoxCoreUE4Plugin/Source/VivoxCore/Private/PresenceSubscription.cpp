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

#include "PresenceSubscription.h"
#include "VivoxCore.h"
#include "VxcErrors.h"
#include "PresenceLocation.h"

PresenceSubscription::PresenceSubscription(::LoginSession &loginSession, const AccountId &subscribedAccount) : _loginSession(loginSession)
{
    _subscribedAccount = subscribedAccount;
}

PresenceSubscription::~PresenceSubscription()
{
    for(auto item : _locations) {
        delete item.Value;
    }
}

void PresenceSubscription::HandleEvent(const vx_evt_buddy_presence& evt)
{
    FString locationId = evt.encoded_uri_with_tag;
    if(_locations.Contains(locationId)) {
        PresenceLocation *location = static_cast<PresenceLocation *>(_locations[locationId]);
        bool updated = location->UpdateFromEvent(evt);
        if (updated)
            EventAfterLocationUpdated.Broadcast(*location);
    }  else {
        PresenceLocation *location = new PresenceLocation(*this, evt);
        _locations.Add(locationId, location);
        EventAfterLocationAdded.Broadcast(*location);
    }
}
