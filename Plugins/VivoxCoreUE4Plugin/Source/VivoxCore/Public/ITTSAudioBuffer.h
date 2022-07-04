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

/**
  * \brief Text-to-speech that is synthesized into an audio buffer for direct use.
  */
class VIVOXCORE_API ITTSAudioBuffer
{
public:
    virtual ~ITTSAudioBuffer() = default;

    /**
     * \brief The PCM buffer of the synthesized speech.
     */
    virtual const short *SpeechBuffer() const = 0;

    /**
     * \brief The sample rate of audio in the buffer.
     */
    virtual const int &SampleRate() const = 0;

    /**
     * \brief The number of frames of audio in the buffer.
     */
    virtual const int &NumFrames() const = 0;

    /**
     * \brief The number of channels that the audio in the buffer consists of.
     */
    virtual const int &NumChannels() const = 0;

    /**
     * \brief True if the speech buffer is not empty.
     */
    virtual bool IsEmpty() const = 0;
};
