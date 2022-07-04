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
#include "IPresenceSubscription.h"
#include "LoginSession.h"

struct vx_evt_buddy_presence;
class LoginSession;

/**
 *
 */
class PresenceSubscription : public IPresenceSubscription
{
    AccountId _subscribedAccount;
    TMap<FString, IPresenceLocation*> _locations;
    ::LoginSession &_loginSession;
public:
    PresenceSubscription(::LoginSession &session,const AccountId &subscribedAccount);
    ~PresenceSubscription();
    const AccountId& SubscribedAccount() const override { return _subscribedAccount; }
    TMap<FString, IPresenceLocation*> Locations() const override { return _locations; }
    ::ILoginSession &LoginSession() override {
        return _loginSession;
    }
    void HandleEvent(const vx_evt_buddy_presence &evt);
};

