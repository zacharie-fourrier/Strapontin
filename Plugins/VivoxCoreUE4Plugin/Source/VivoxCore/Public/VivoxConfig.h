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
#include "VivoxCoreCommon.h"
#include "Vxc.h"

 // Note: Added this for Core 5.3.0+ to preserve backward compatibility
 // until the eventual deprecatation of this codec enum for a wrapped vx_codec.
enum media_codec_type {
    media_codec_type_none = 0,
    media_codec_type_siren14 = 1,
    media_codec_type_pcmu = 2,
    media_codec_type_nm = 3,
    media_codec_type_speex = 4,
    media_codec_type_siren7 = 5,
    media_codec_type_opus = 6
};

class VIVOXCORE_API VivoxConfig
{
    vx_sdk_config_t config;
    static void LoggingCallback(void *callback_handle, vx_log_level logLevel, const char *source, const char *message);
    static void* VivoxMalloc(size_t bytes);
    static void VivoxFree(void* ptr);
    static void* VivoxRealloc(void* ptr, size_t bytes);
    static void* VivoxCalloc(size_t num, size_t bytes);
    static void* VivoxMallocAligned(size_t alignment, size_t bytes);
    static void VivoxFreeAligned(void* ptr);
public:
    VivoxConfig();
    ~VivoxConfig() {}

    /**
    * \brief Retrieve the underlying Vivox config.
    */
    vx_sdk_config_t ToVx_Sdk_Config() { return config; }
    /**
    * \brief The log level of the SDK.
    * Severity level of logs: -1 = no logging, 0 = errors only, 1 = warnings, 2 = info, 3 = debug, 4 = trace, 5 = log all.
    */
    vx_log_level LogLevel() const { return config.initial_log_level; }
    /**
    * \brief The default codec mask.
    * Caution: Altering this value can result in unexpected behavior.
    * Codec type none = 0, codec type siren14 = 1, codec type pcmu = 2, codec type nm = 3,
    * codec type speex = 4, codec type siren7 = 5, codec type opus = 6
    * For more information, see the Vivox Developer Documentation.
    */
    media_codec_type DefaultCodecsMask() const {
        switch (vx_codec(config.default_codecs_mask))
        {
        case vx_codec_pcmu:
            return media_codec_type_pcmu;
        case vx_codec_siren7:
            return media_codec_type_siren7;
        case vx_codec_siren14:
            return media_codec_type_siren14;
        case vx_codec_opus8:
        case vx_codec_opus40:
        case vx_codec_opus57:
        case vx_codec_opus72:
            return media_codec_type_opus;
        default:
            return media_codec_type(config.default_codecs_mask);
        }
    }

    /**
    * \brief The render source maximum queue depth.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    int RenderSourceQueueDepthMax() const { return config.render_source_queue_depth_max; }
    /**
    * \brief The render source initial buffer count.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    int RenderSourceInitialBufferCount() const { return config.render_source_initial_buffer_count; }
    /**
    * \brief The upstream jitter frame count.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    int UpstreamJitterFrameCount() const { return config.upstream_jitter_frame_count; }
    /**
    * \brief The maximum number of logins allowed for a user.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    int MaxLoginsPerUser() const { return config.max_logins_per_user; }
    /**
    * \brief The number of 20 millisecond buffers for the capture device.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation. 
    */
    int CaptureDeviceBufferSizeIntervals() const { return config.capture_device_buffer_size_intervals; }
    /**
    * \brief The number of 20 millisecond buffers for the render device.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    int RenderDeviceBufferSizeIntervals() const { return config.render_device_buffer_size_intervals; }
    /**
    * \brief The number of milliseconds to wait before disconnecting audio due to RTP timeout at initial call time. A zero or a negative value turns off the guard (this is not recommended).
    */
    int NeverRtpTimeoutMs() const { return config.never_rtp_timeout_ms; }
    /**
    * \brief The number of milliseconds to wait before disconnecting audio due to RTP timeout after the call has been established. A zero or a negative value turns off the guard (this is not recommended).
    */
    int LostRtpTimeoutMs() const { return config.lost_rtp_timeout_ms; }
    /**
    * \brief A processor affinity mask for SDK threads.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation. 
    */
    long long ProcessorAffinityMask() const { return config.processor_affinity_mask; }
    /**
    * \brief The status of device polling.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    bool DisableDevicePolling() const { return (bool)config.disable_device_polling; }
    /**
    * \brief The status of capturing silence.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    bool ForceCaptureSilence() const { return (bool)config.force_capture_silence; }
    /**
    * \brief The status of the advanced automatic settings of audio levels.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    bool EnableAdvancedAutoLevels() const { return (bool)config.enable_advanced_auto_levels; }
    /**
    * \brief Enable persistent connections (Windows only). The default is 0, or 1 if the environment variable "VIVOX_ENABLE_PERSISTENT_HTTP" is set.
    * Note that the use of proxies could interfere with any behavior controlled by this setting.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    bool EnablePersistentHTTP() const { return (bool)config.enable_persistent_http; }
    /**
    * \brief The status of audio ducking (iOS and Xbox One only).
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    bool DisableAudioDucking() const { return (bool)config.disable_audio_ducking; }
    /**
    * \brief The status of fast network change detection. This is disabled by default.
    */
    bool EnableFastNetworkChangeDetection() const { return (bool)config.enable_fast_network_change_detection; }
    /**
    * \brief Use operating system-configured proxy settings (Windows only). The default is 0, or 1 if the environment variable "VIVOX_USE_OS_PROXY_SETTINGS" is set.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    bool UseOSProxySettings() const { return (bool)config.use_os_proxy_settings; }
    /**
    * \brief Allow shared capture devices (shared in the Vivox context only).
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    bool AllowSharedCaptureDevices() const { return (bool)config.allow_shared_capture_devices; }
    /**
    * \brief For most platforms, the default is true.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    bool EnableDTX() const { return (bool)config.enable_dtx; }


    /**
    * \brief Set the log level of the Vivox SDK.
    * Severity level of logs: -1 = no logging, 0 = errors only, 1 = warnings, 2 = info, 3 = debug, 4 = trace, 5 = log all.
    */
    void SetLogLevel(vx_log_level logLevel);

    /**
    * \brief Set the codec mask that is used to initialize the connector's configured_codecs.
    * Caution: Altering this value can change the quality of the voice experience.
    * codec type none = 0, codec type siren14 = 1, codec type pcmu = 2, codec type nm = 3,
    * codec type speex = 4, codec type siren7 = 5, codec type opus = 6
    * For more information, see the Vivox Developer Documentation.
    */
    void SetDefaultCodecsMask(media_codec_type codecType);

    /**
    * \brief Set the render source maximum queue depth.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetRenderSourceQueueDepthMax(int queueDepthMax);

    /**
    * \brief Set the render source initial buffer count.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetRenderSourceInitialBufferCount(int initialBufferCount);

    /**
    * \brief Set the upstream jitter frame count.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetUpstreamJitterFrameCount(int upstreamJitterFrameCount);

    /**
    * \brief Set the maximum number of logins that a user can have.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetMaxLoginsPerUser(int maxLoginsPerUser);

    /**
    * \brief Set the number of 20 millisecond buffers for the capture device.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetCaptureDeviceBufferSizeIntervals(int captureDeviceBufferSizeIntervals);

    /**
    * \brief Set the number of 20 millisecond buffers for the render device.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetRenderDeviceBufferSizeIntervals(int renderDeviceBufferSizeIntervals);

    /**
    * \brief Set the number of milliseconds to wait before disconnecting audio due to RTP timeout at initial call time. A zero or a negative value turns off the guard (this is not recommended).
    */
    void SetNeverRtpTimeoutMs(int neverRtpTimeoutMs);

    /**
    * \brief Set the number of milliseconds to wait before disconnecting audio due to RTP timeout after the call has been established. A zero or a negative value turns off the guard (this is not recommended).
    */
    void SetLostRtpTimeoutMs(int lostRtpTimeoutMs);

    /**
    * \brief A processor affinity mask for SDK threads.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetProcessorAffinityMask(long long processorAffinityMask);

    /**
    * \brief Set whether to disable audio device polling by using a timer.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetDisableDevicePolling(bool disableDevicePolling);

    /**
    * \brief Set whether to force capturing silence. This is for diagnostic purposes only.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetForceCaptureSilence(bool forceCaptureSilence);

    /**
    * \brief Set whether to enable the advanced automatic settings of audio levels.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetEnableAdvancedAutoLevels(bool enableAdvancedAutoLevels);

    /**
    * \brief Enable persistent connections (Windows only). The default is 0, or 1 if the environment variable "VIVOX_ENABLE_PERSISTENT_HTTP" is set.
    * Note that the use of proxies may interfere with behavior controlled by this setting.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetEnablePersistentHTTP(bool enablePersistentHTTP);

    /**
    * \brief Set whether to disable audio ducking (iOS and Xbox One only).
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetDisableAudioDucking(bool disableAudioDucking);

    /**
    * \brief Set whether to enable fast network change detection. This is disabled by default.
    */
    void SetEnableFastNetworkChangeDetection(bool enableFastNetworkChangeDetection);

    /**
    * \brief Use operating system-configured proxy settings (Windows only). The default is 0, or 1 if the environment variable "VIVOX_USE_OS_PROXY_SETTINGS" is set.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetUseOSProxySettings(bool useOSProxySettings);

    /**
    * \brief Allow shared capture devices (shared in the Vivox context only).
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetAllowSharedCaptureDevices(bool allowSharedCaptureDevices);

    /**
    * \brief For most platforms, this defaults to true.
    * Caution: Altering this value could result in unexpected behavior.
    * For more information, see the Vivox Developer Documentation.
    */
    void SetEnableDTX(bool enableDTX);
};
