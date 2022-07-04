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
#include "ITranscribedMessage.h"
#include "ChannelSession.h"

struct vx_evt_transcribed_message;
/**
 * Transcribed text from a participant in a channel session
 */
class TranscribedMessage : public ITranscribedMessage
{
    FDateTime _receivedTime;
    FString _text;
    AccountId _speaker;
    FString _language;
    ::ChannelSession &_channelSession;
public:
    TranscribedMessage(::ChannelSession &parent, const vx_evt_transcribed_message &evt);
    ~TranscribedMessage();
    const FDateTime& ReceivedTime() const override { return _receivedTime; }
    const FString& Text() const override { return _text; }
    const AccountId& Speaker() const override { return _speaker; }
    const FString& Language() const override { return _language; }
    IChannelSession& ChannelSession() const override { return _channelSession; }
};
