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
#include "ITTSAudioBuffer.h"
#include "ClientImpl.h"

typedef vx_tts_utterance_t TTSUtteranceStruct;
typedef vx_tts_utterance_impl_t TTSUtteranceImpl;

/**
 *
 */
class TTSAudioBufferImpl : public ITTSAudioBuffer
{
    TTSManagerId _managerId;
    TTSUtteranceStruct *_utteranceStruct;

public:
    TTSAudioBufferImpl();
    TTSAudioBufferImpl(const TTSManagerId &managerId, TTSUtteranceStruct *utterance);
    ~TTSAudioBufferImpl();

    const short *SpeechBuffer() const override;
    const int &SampleRate() const override;
    const int &NumFrames() const override;
    const int &NumChannels() const override;
    bool IsEmpty() const override;
};
