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

#include "TTSVoiceImpl.h"
#include "VivoxCore.h"

TTSVoiceImpl::TTSVoiceImpl()
{
    _isValid = false;
}

TTSVoiceImpl::TTSVoiceImpl(const TTSVoiceStruct &voiceStruct)
{
    _name = voiceStruct.name;
    _voiceId = voiceStruct.voice_id;
    _isValid = true;
}

TTSVoiceImpl::TTSVoiceImpl(const ITTSVoice &ttsVoice)
{
    _name = ttsVoice.Name();
    _voiceId = ttsVoice.VoiceId();
    _isValid = !_name.IsEmpty();
}

TTSVoiceImpl::~TTSVoiceImpl()
{
}

const FString &TTSVoiceImpl::Name() const
{
    return _name;
}

const TTSVoiceId &TTSVoiceImpl::VoiceId() const
{
    return _voiceId;
}

bool TTSVoiceImpl::IsValid() const
{
    return _isValid;
}

TTSVoiceImpl &TTSVoiceImpl::operator =(const ITTSVoice &ttsVoice)
{
    _name = ttsVoice.Name();
    _voiceId = ttsVoice.VoiceId();
    _isValid = !_name.IsEmpty();
    return *this;
}
