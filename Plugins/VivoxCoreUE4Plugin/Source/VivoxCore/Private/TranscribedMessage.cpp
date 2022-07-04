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

#include "TranscribedMessage.h"
#include "VivoxCore.h"
#include "VxcEvents.h"

TranscribedMessage::TranscribedMessage(::ChannelSession &parent, const vx_evt_transcribed_message &evt) : _channelSession(parent)
{
    _receivedTime = FDateTime::UtcNow();
    _language = evt.language ? UTF8_TO_TCHAR(evt.language) : UTF8_TO_TCHAR("en");
    _text = UTF8_TO_TCHAR(evt.text);
    _speaker = AccountId::CreateFromUri(evt.participant_uri);
}

TranscribedMessage::~TranscribedMessage()
{
}
