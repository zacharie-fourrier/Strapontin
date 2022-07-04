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
#if PLATFORM_IOS
#include <AVFoundation/AVFoundation.h>
#ifdef __cplusplus
extern "C" {
#endif

void PrepareForVivox ();

#ifdef __cplusplus
}

void PrepareForVivox() {
    // Important: must set PlayAndRecord category for simultaneous input/output
    // Default to speaker will play from speakers instead of the receiver (ear speaker) when headphones are not used.
    [AVAudioSession.sharedInstance
     setCategory:AVAudioSessionCategoryPlayback
     mode:AVAudioSessionModeDefault
     options:0
     error:nil];
    // 44,100 sample rate must be used for iOS
    [AVAudioSession.sharedInstance setPreferredSampleRate:44100 error:nil];
}
#endif
#endif
