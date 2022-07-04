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

#include "DirectedTextMessage.h"
#include "VivoxCore.h"

DirectedTextMessage::DirectedTextMessage(::LoginSession &loginSession, const vx_evt_user_to_user_message &evt) : _loginSession(loginSession)
{
    _receivedTime = FDateTime::UtcNow();
    _message = UTF8_TO_TCHAR(evt.message_body);
    _applicationStanzaBody = UTF8_TO_TCHAR(evt.application_stanza_body);
    _applicationStanzaNamespace = UTF8_TO_TCHAR(evt.application_stanza_namespace);
    _language = UTF8_TO_TCHAR(evt.language);
    _sender = AccountId::CreateFromUri(evt.from_uri);
}

DirectedTextMessage::~DirectedTextMessage()
{
}
