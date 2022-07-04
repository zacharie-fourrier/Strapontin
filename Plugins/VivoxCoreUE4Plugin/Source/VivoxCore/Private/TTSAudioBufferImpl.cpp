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

#include "TTSAudioBufferImpl.h"
#include "VivoxCore.h"

TTSAudioBufferImpl::TTSAudioBufferImpl()
{
    _utteranceStruct = nullptr;
}

TTSAudioBufferImpl::TTSAudioBufferImpl(const TTSManagerId &managerId, TTSUtteranceStruct *utterance)
{
    _managerId = managerId;
    _utteranceStruct = utterance;
}

TTSAudioBufferImpl::~TTSAudioBufferImpl()
{
    vx_tts_destroy_utterance(_managerId, _utteranceStruct);
}

const short *TTSAudioBufferImpl::SpeechBuffer() const
{
    return _utteranceStruct->speech_buffer;
}

const int &TTSAudioBufferImpl::SampleRate() const
{
    return _utteranceStruct->sample_rate;
}

const int &TTSAudioBufferImpl::NumFrames() const
{
    return _utteranceStruct->num_frames;
}

const int &TTSAudioBufferImpl::NumChannels() const
{
    return _utteranceStruct->num_channels;
}

bool TTSAudioBufferImpl::IsEmpty() const
{
    return !(_utteranceStruct && _utteranceStruct->num_frames > 0);
}
