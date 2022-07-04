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
#include "Containers/UnrealString.h"
#include "Vxc.h"

typedef vx_tts_voice_id TTSVoiceId;

/**
 * \brief A voice used by the text-to-speech (TTS) subsystem to synthesize speech.
 */
class VIVOXCORE_API ITTSVoice
{
public:
    virtual ~ITTSVoice() = default;

    /**
     * \brief A user-displayable voice name.
     */
    virtual const FString &Name() const = 0;

    /**
     * \brief An internal voice identifier.
     */
    virtual const TTSVoiceId &VoiceId() const = 0;

    /**
     * \brief True if Name and VoiceId are non-default values.
     */
    virtual bool IsValid() const = 0;
};
