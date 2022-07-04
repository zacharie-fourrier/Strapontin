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

#include "TTSMessageImpl.h"
#include "VivoxCore.h"

TTSMessageImpl::TTSMessageImpl()
{
    _isValid = false;
}

TTSMessageImpl::TTSMessageImpl(const TTSVoiceImpl &voice, const FString &text, const TTSDestination &destination, const TTSUtteranceId &utteranceId, const TTSMessageState &state)
{
    _voice = voice;
    _text = text;
    _destination = destination;
    _utteranceId = utteranceId;
    _state = state;
    _isValid = true;
}

TTSMessageImpl::~TTSMessageImpl()
{
}

const ITTSVoice &TTSMessageImpl::Voice() const
{
    return _voice;
}

const FString &TTSMessageImpl::Text() const
{
    return _text;
}

const TTSDestination &TTSMessageImpl::Destination() const
{
    return _destination;
}

const TTSUtteranceId &TTSMessageImpl::UtteranceId() const
{
    return _utteranceId;
}

const TTSMessageState &TTSMessageImpl::State() const
{
    return _state;
}

bool TTSMessageImpl::IsValid() const
{
    return _isValid && !_text.IsEmpty();
}

void TTSMessageImpl::SetPlaying()
{
    _state = TTSMessageState::Playing;
}
