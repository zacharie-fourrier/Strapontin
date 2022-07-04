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
#include "IDirectedTextMessage.h"
#include "LoginSession.h"

struct vx_evt_user_to_user_message;
/**
 * A text message from one user to another user
 */
class DirectedTextMessage : public IDirectedTextMessage
{
    FDateTime _receivedTime;
    FString _message;
    AccountId _sender;
    FString _language;
    FString _applicationStanzaNamespace;
    FString _applicationStanzaBody;
    ::LoginSession &_loginSession;
public:
    DirectedTextMessage(::LoginSession &loginSession, const vx_evt_user_to_user_message &evt);
    ~DirectedTextMessage();
    const FDateTime& ReceivedTime() const override { return _receivedTime; }
    const FString& Message() const override { return _message; }
    const AccountId& Sender() const override { return _sender; }
    const FString& Language() const override { return _language; }
    const FString& ApplicationStanzaNamespace() const override { return _applicationStanzaNamespace; }
    const FString& ApplicationStanzaBody() const override { return _applicationStanzaBody; }
    ILoginSession& LoginSession() override { return _loginSession; }
};
