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

#include "ClientImpl.h"
#include "VivoxCore.h"
#include "Vxc.h"
#include "LoginSession.h"
#include "VivoxNativeSdk.h"
#include "VxcEvents.h"
#include "VxcResponses.h"
#include "VxcErrors.h"

ClientImpl::ClientImpl() :
_audioInputDevices(AudioDeviceType::Input),
_audioOutputDevices(AudioDeviceType::Output)
{
    _initialized = false;
    _ttsIsInitialized = false;
}


ClientImpl::~ClientImpl()
{
    if (_initialized) {
        Cleanup();
        _initialized = false;
        vx_uninitialize();
    }
}

void ClientImpl::Cleanup()
{
    TTSShutdown();
    _loginSessions.Empty();
}

void ClientImpl::Tick(float DeltaTime)
{
    if (_initialized) {
        VivoxNativeSdk::Get().Tick();
    }
}

VivoxCoreError ClientImpl::Initialize(VivoxConfig config)
{
    if (_initialized) return VxErrorAlreadyInitialized;

    vx_sdk_config_t vxConfig = config.ToVx_Sdk_Config();
    int status = vx_initialize3(&vxConfig, sizeof(vxConfig));
    ensure(status == 0);
    if (status != 0) return status;

    _audioInputDevices.Initialize();
    _audioOutputDevices.Initialize();
    _audioInputDevices.Refresh();
    _audioOutputDevices.Refresh();

    _initialized = true;
    return VxErrorSuccess;
}

void ClientImpl::Uninitialize()
{
    _pendingConnects.Empty();
    _connectorHandle.Empty();
    if (!_initialized) return;
    vx_uninitialize();
    _initialized = false;
}

ILoginSession &ClientImpl::GetLoginSession(const AccountId &loginSessionId)
{
    ensure(!loginSessionId.IsEmpty());
    TSharedPtr<ILoginSession> returnValue;
    if(!_loginSessions.Contains(loginSessionId))
    {
        returnValue = TSharedPtr<ILoginSession>(new LoginSession(*this, loginSessionId));
        _loginSessions.Add(loginSessionId, returnValue);
    } else
    {
        returnValue = *_loginSessions.Find(loginSessionId);
    }
    return *returnValue;
}

const TMap<AccountId, TSharedPtr<ILoginSession>>& ClientImpl::LoginSessions()
{
    return _loginSessions;
}

IAudioDevices& ClientImpl::AudioInputDevices()
{
    return _audioInputDevices;
}

IAudioDevices& ClientImpl::AudioOutputDevices()
{
    return _audioOutputDevices;
}

bool ClientImpl::TTSInitialize()
{
    if (!_ttsIsInitialized)
    {
        // NB: once there's more than one tts_engine type available we'll need to make a public TTSInitialize() method.
        vx_tts_status status = vx_tts_initialize(tts_engine_vivox_default, &_ttsManagerId);
        if (tts_status_success == status)
            _ttsIsInitialized = true;
    }
    return _ttsIsInitialized;
}

void ClientImpl::TTSShutdown()
{
    if (_ttsIsInitialized)
    {
        vx_tts_shutdown(&_ttsManagerId);
        for (auto& elem : _loginSessions)
        {
            ((TextToSpeech&)elem.Value->TTS()).CleanupTTS();
        }
        _ttsIsInitialized = false;
    }
}

VivoxCoreError ClientImpl::BeginGetConnectorHandle(const FString& server, FOnBeginGetConnectorHandleCompletedDelegate theDelegate)
{
    ensure(!server.IsEmpty());
    if(!_connectorHandle.IsEmpty())
    {
        theDelegate.ExecuteIfBound(VxErrorSuccess, _connectorHandle);
        return VxErrorSuccess;
    }
    _pendingConnects.Add(theDelegate);
    if (_pendingConnects.Num() == 1) {
        VivoxNativeSdk::FOnRequestCompletedDelegate innerDelegate;
        innerDelegate.BindLambda([this](const vx_resp_base_t &resp)
        {
            if (resp.return_code == 0) {
                vx_req_connector_create_t *req = reinterpret_cast<vx_req_connector_create *>(resp.request);
                _connectorHandle = req->connector_handle;
            }
            for (auto item : _pendingConnects) {
                item.ExecuteIfBound(resp.status_code, _connectorHandle);
            }
        });
        return VivoxNativeSdk::Get().ConnectorCreate(server, innerDelegate);
    }
    return VxErrorSuccess;
}
