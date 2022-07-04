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

#include "PresenceLocation.h"
#include "VivoxCore.h"
#include "VxcEvents.h"
#include "PresenceSubscription.h"

PresenceLocation::PresenceLocation(PresenceSubscription &subscription, const vx_evt_buddy_presence &evt) : _subscription(subscription)
{
    _currentPresence = Presence(static_cast<PresenceStatus>(evt.presence), evt.custom_message);
    _locationId = evt.encoded_uri_with_tag;
}

PresenceLocation::~PresenceLocation()
{
}

bool PresenceLocation::UpdateFromEvent(const vx_evt_buddy_presence& evt)
{
    Presence p(static_cast<PresenceStatus>(evt.presence), evt.custom_message);
    if (p != _currentPresence) {
        _currentPresence = p;
        return true;
    }
    return false;
}
