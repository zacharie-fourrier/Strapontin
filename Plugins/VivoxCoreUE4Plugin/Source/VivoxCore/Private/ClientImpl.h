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
#include "IClient.h"
#include "AudioDevicesImpl.h"

struct vx_evt_base;
typedef vx_tts_manager_id TTSManagerId;

class ClientImpl : public IClient
{
public:
    DECLARE_MULTICAST_DELEGATE_TwoParams(FDelegateBeginGetConnectorHandleCompleted, VivoxCoreError, const FString &)
    typedef FDelegateBeginGetConnectorHandleCompleted::FDelegate FOnBeginGetConnectorHandleCompletedDelegate;
private:
    bool _initialized;
    TMap<AccountId, TSharedPtr<ILoginSession> > _loginSessions;
    AudioDevicesImpl _audioInputDevices;
    AudioDevicesImpl _audioOutputDevices;
    FString _connectorHandle;
    TArray<FOnBeginGetConnectorHandleCompletedDelegate> _pendingConnects;
    bool _ttsIsInitialized;
    TTSManagerId _ttsManagerId;
    void Cleanup();
public:
    ClientImpl();
    ~ClientImpl();

    void Tick(float DeltaTime);

    // IClient
    VivoxCoreError Initialize(VivoxConfig config) override;
    void Uninitialize() override;
    ILoginSession &GetLoginSession(const AccountId &loginSessionId) override;
    const TMap<AccountId, TSharedPtr<ILoginSession>> & LoginSessions() override;
    IAudioDevices& AudioInputDevices() override;
    IAudioDevices& AudioOutputDevices() override;

    // internal
    VivoxCoreError BeginGetConnectorHandle(const FString &server, FOnBeginGetConnectorHandleCompletedDelegate theDelegate);
    bool IsConnected() { return !_connectorHandle.IsEmpty(); }
    const TTSManagerId &GetTTSManagerId() { return _ttsManagerId; }
    bool TTSInitialize();
    void TTSShutdown();
};
