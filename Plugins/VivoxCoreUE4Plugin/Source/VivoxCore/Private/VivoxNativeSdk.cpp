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

#include "VivoxNativeSdk.h"
#include "VivoxCore.h"
#include "VivoxCoreCommonImpl.h"
#include "VxcErrors.h"
#include "ILoginSession.h"
#include "TTSAudioBufferImpl.h"

VivoxNativeSdk *VivoxNativeSdk::_instance;

char *vx_fstrdup(const FString &str)
{
    if (str.IsEmpty())
        return nullptr;
    return vx_strdup(TCHAR_TO_UTF8(*str));
}

VivoxNativeSdk::VivoxNativeSdk()
{
}

VivoxNativeSdk::~VivoxNativeSdk()
{
}

VivoxNativeSdk &VivoxNativeSdk::Get()
{
    if (_instance != nullptr)
        return *_instance;
    _instance = new VivoxNativeSdk();
    return *_instance;
}

static FString ToXml(vx_req_base_t *req)
{
    char *xml = nullptr;
    vx_request_to_xml(req, &xml);
    FString tmp = UTF8_TO_TCHAR(xml);
    vx_free(xml);
    return tmp;
}

VivoxCoreError VivoxNativeSdk::IssueRequest(vx_req_base_t* request, FOnRequestCompletedDelegate theDelegate)
{
    if (request->type == req_session_set_3d_position) {
        UE_LOG(VivoxCore, VeryVerbose, TEXT("%s"), *ToXml(request));
    } else {
        UE_LOG(VivoxCore, Log, TEXT("%s"), *ToXml(request));
    }
    FOnRequestCompletedDelegate *newDelegate = new FOnRequestCompletedDelegate(theDelegate);
    request->vcookie = static_cast<void *>(newDelegate);
    int count = 0;
    int status = vx_issue_request3(request, &count);
    if(status != 0)
    {
        UE_LOG(VivoxCore, Error, TEXT("vx_issue_request3() failed for %hs - %d:%hs"), vx_get_request_type_string(request->type), status, vx_get_error_string(status));
        return status;
    }
    if(count > 10)
    {
        UE_LOG(VivoxCore, Error, TEXT("vx_issue_request3() %d requests outstanding for %hs"), count, vx_get_request_type_string(request->type));
    }
    return status;
}

VivoxCoreError VivoxNativeSdk::SetInputDeviceMuted(bool value, FOnRequestCompletedDelegate theDelegate)
{
    vx_req_connector_mute_local_mic_t *req;
    vx_req_connector_mute_local_mic_create(&req);
    req->mute_level = value ? 1 : 0;
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::SetOutputDeviceMuted(bool value, FOnRequestCompletedDelegate theDelegate)
{
    vx_req_connector_mute_local_speaker_t *req;
    vx_req_connector_mute_local_speaker_create(&req);
    req->mute_level = value ? 1 : 0;
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::RefreshAudioInputDevices(FOnRequestCompletedDelegate theDelegate)
{
    vx_req_aux_get_capture_devices *req;
    vx_req_aux_get_capture_devices_create(&req);
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::RefreshAudioOutputDevices(FOnRequestCompletedDelegate theDelegate)
{
    vx_req_aux_get_render_devices *req;
    vx_req_aux_get_render_devices_create(&req);
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::Login(const FString & connectorHandle,
    const AccountId & account,
    const FString & accessToken,
    int participantPropertyFrequency,
    bool enablePresence,
    SubscriptionMode subscriptionMode,
    const TSet<AccountId>& presenceSubscriptions,
    const TSet<AccountId>& blockedPresenceSubscriptions,
    const TSet<AccountId>& allowedPresenceSubscriptions,
    FOnRequestCompletedDelegate theDelegate)
{
    ensure(!connectorHandle.IsEmpty());
    ensure(account.IsValid());
    ensure(!accessToken.IsEmpty());
    vx_req_account_anonymous_login *req;
    vx_req_account_anonymous_login_create(&req);
    req->connector_handle = vx_strdup(TCHAR_TO_UTF8(*connectorHandle));
    req->access_token = vx_strdup(TCHAR_TO_UTF8(*accessToken));
    req->account_handle = vx_strdup(TCHAR_TO_UTF8(*account.ToString()));

    FString name = "." + account.Issuer() + "." + account.Name() + ".";
    req->acct_name = vx_strdup(TCHAR_TO_UTF8(*name));
    req->displayname = vx_strdup(TCHAR_TO_UTF8(*account.DisplayName()));
    req->languages = vx_strdup(TCHAR_TO_UTF8(*FString::Join(account.SpokenLanguages(), TEXT(","))));
    req->participant_property_frequency = participantPropertyFrequency;
    req->enable_buddies_and_presence = enablePresence ? 1 : 0;
    if (req->enable_buddies_and_presence) {
        switch (subscriptionMode)
        {
        case SubscriptionMode::Accept:
            req->buddy_management_mode = mode_auto_accept;
            break;
        case SubscriptionMode::Block:
            req->buddy_management_mode = mode_block;
            break;
        case SubscriptionMode::Defer:
        default:
            req->buddy_management_mode = mode_application;
        }

        if (presenceSubscriptions.Num())
        {
            req->initial_buddy_uris = static_cast<char **>(vx_calloc(presenceSubscriptions.Num() + 1, sizeof(char *)));
            int i = 0;
            for (auto item : presenceSubscriptions)
            {
                req->initial_buddy_uris[i++] = vx_strdup(TCHAR_TO_UTF8(*item.ToString()));
            }
        }
        if (blockedPresenceSubscriptions.Num())
        {
            req->initial_blocked_uris = static_cast<char **>(vx_calloc(blockedPresenceSubscriptions.Num() + 1, sizeof(char *)));
            int i = 0;
            for (auto item : blockedPresenceSubscriptions)
            {
                req->initial_blocked_uris[i++] = vx_strdup(TCHAR_TO_UTF8(*item.ToString()));
            }
        }

        if (allowedPresenceSubscriptions.Num())
        {
            req->initial_allowed_uris = static_cast<char **>(vx_calloc(allowedPresenceSubscriptions.Num() + 1, sizeof(char *)));
            int i = 0;
            for (auto item : allowedPresenceSubscriptions)
            {
                req->initial_allowed_uris[i++] = vx_strdup(TCHAR_TO_UTF8(*item.ToString()));
            }
        }
    }

    return IssueRequest(&req->base, theDelegate);
}

void VivoxNativeSdk::Logout(const FString& accountHandle)
{
    ensure(!accountHandle.IsEmpty());
    vx_req_account_logout_t *req;
    vx_req_account_logout_create(&req);
    req->account_handle = vx_strdup(TCHAR_TO_UTF8(*accountHandle));
    IssueRequest(&req->base, FOnRequestCompletedDelegate());
}

vx_message_base_t* VivoxNativeSdk::Read()
{
    vx_message_base_t *message = nullptr;
    vx_get_message(&message);
    return message;
}

vx_evt_base_t* VivoxNativeSdk::ToEvent(vx_message_base_t* message)
{
    if (message == nullptr) return nullptr;
    if (message->type == msg_event) return reinterpret_cast<vx_evt_base_t *>(message);
    return nullptr;
}

vx_resp_base_t* VivoxNativeSdk::ToResponse(vx_message_base_t* message)
{
    if (message == nullptr) return nullptr;
    if (message->type == msg_response) return reinterpret_cast<vx_resp_base_t *>(message);
    return nullptr;
}

static FString ToXml(vx_resp_base *resp)
{
    char *xml = nullptr;
    vx_response_to_xml(resp, &xml);
    FString tmp = UTF8_TO_TCHAR(xml);
    vx_free(xml);
    return tmp;
}
static FString ToXml(vx_evt_base *evt)
{
    char *xml = nullptr;
    vx_event_to_xml(evt, &xml);
    FString tmp = UTF8_TO_TCHAR(xml);
    vx_free(xml);
    return tmp;
}

void VivoxNativeSdk::Tick()
{
    for (;;) {
        vx_message_base_t *msg = VivoxNativeSdk::Read();
        if (msg == nullptr)
            break;
        vx_evt_base_t *event = VivoxNativeSdk::ToEvent(msg);
        if(event != nullptr)
        {
            if (event->type == evt_participant_updated) {
                UE_LOG(VivoxCore, VeryVerbose, TEXT("%s"), *ToXml(event));
            } else {
                UE_LOG(VivoxCore, Log, TEXT("%s"), *ToXml(event));
            }
            EventSdkEventRaised.Broadcast(*event);
        } else
        {
            vx_resp_base_t *resp = VivoxNativeSdk::ToResponse(msg);
            UE_LOG(VivoxCore, Log, TEXT("%s"), *ToXml(resp));
            if(resp->return_code != 0)
            {
                UE_LOG(VivoxCore, Warning, TEXT("%hs failed for %d:%hs"), vx_get_request_type_string(resp->request->type), resp->status_code, vx_get_error_string(resp->status_code));
            }
            if(resp->request->vcookie != nullptr)
            {
                FOnRequestCompletedDelegate *theDelegate = reinterpret_cast<FOnRequestCompletedDelegate *>(resp->request->vcookie);
                theDelegate->ExecuteIfBound(*resp);
                delete theDelegate;
            } else
            {
                UE_LOG(VivoxCore, Warning, TEXT("Request without completion handler"));
            }
        }
        vx_destroy_message(msg);
    }
}

VivoxCoreError VivoxNativeSdk::AddSession(
    const FString &accountHandle,
    const FString &groupHandle,
    const FString &sessionHandle,
    const FString &accessToken,
    const ChannelId &channel,
    bool audio,
    bool text,
    FOnRequestCompletedDelegate theDelegate)
{
    ensure(!accountHandle.IsEmpty());
    ensure(!groupHandle.IsEmpty());
    ensure(!sessionHandle.IsEmpty());
    ensure(!accessToken.IsEmpty());
    ensure(channel.IsValid());
    ensure(audio || text);

    vx_req_sessiongroup_add_session *req;
    vx_req_sessiongroup_add_session_create(&req);
    req->access_token = vx_fstrdup(accessToken);
    req->account_handle = vx_fstrdup(accountHandle);
    req->connect_audio = audio ? 1 : 0;
    req->connect_text = text ? 1 : 0;
    req->session_handle = vx_fstrdup(sessionHandle);
    req->sessiongroup_handle = vx_fstrdup(groupHandle);
    req->uri = vx_fstrdup(channel.ToString());
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::AddBlockRule(const FString& accountHandle, const AccountId& account, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!accountHandle.IsEmpty());
    ensure(account.IsValid());
    vx_req_account_create_block_rule_t *req;
    vx_req_account_create_block_rule_create(&req);
    req->account_handle = vx_fstrdup(accountHandle);
    req->presence_only = 0;
    req->block_mask = vx_fstrdup(account.ToString());
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::DeleteBlockRule(const FString& accountHandle, const AccountId& account, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!accountHandle.IsEmpty());
    ensure(account.IsValid());
    vx_req_account_delete_block_rule_t *req;
    vx_req_account_delete_block_rule_create(&req);
    req->account_handle = vx_fstrdup(accountHandle);
    req->block_mask = vx_fstrdup(account.ToString());
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::AddAcceptRule(const FString& accountHandle, const AccountId& account, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!accountHandle.IsEmpty());
    ensure(account.IsValid());
    vx_req_account_create_auto_accept_rule_t *req;
    vx_req_account_create_auto_accept_rule_create(&req);
    req->account_handle = vx_fstrdup(accountHandle);
    req->auto_accept_mask = vx_fstrdup(account.ToString());
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::DeleteAcceptRule(const FString& accountHandle, const AccountId& account, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!accountHandle.IsEmpty());
    ensure(account.IsValid());
    vx_req_account_delete_auto_accept_rule_t *req;
    vx_req_account_delete_auto_accept_rule_create(&req);
    req->account_handle = vx_fstrdup(accountHandle);
    req->auto_accept_mask = vx_fstrdup(account.ToString());
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::AddPresenceSubscription(const FString& accountHandle, const AccountId& account, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!accountHandle.IsEmpty());
    ensure(account.IsValid());
    vx_req_account_buddy_set_t *req;
    vx_req_account_buddy_set_create(&req);
    req->account_handle = vx_fstrdup(accountHandle);
    req->buddy_uri = vx_fstrdup(account.ToString());
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::DeletePresenceSubscription(const FString& accountHandle, const AccountId& account, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!accountHandle.IsEmpty());
    ensure(account.IsValid());
    vx_req_account_buddy_delete_t *req;
    vx_req_account_buddy_delete_create(&req);
    req->account_handle = vx_fstrdup(accountHandle);
    req->buddy_uri = vx_fstrdup(account.ToString());
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::SendSubscriptionReply(const FString& accountHandle, const AccountId& account, const vx_rule_type ruleType, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!accountHandle.IsEmpty());
    ensure(account.IsValid());
    vx_req_account_send_subscription_reply_t *req;
    vx_req_account_send_subscription_reply_create(&req);
    req->account_handle = vx_fstrdup(accountHandle);
    req->buddy_uri = vx_fstrdup(account.ToString());
    req->rule_type = ruleType;
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::SendUserToUserMessage(const FString& accountHandle, const AccountId& dest, const FString& language, const FString& message, const FString& applicationStanzaNamespace, const FString& applicationStanzaBody, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!accountHandle.IsEmpty());
    ensure(dest.IsValid());
    vx_req_account_send_message_t *req;
    vx_req_account_send_message_create(&req);
    req->language = vx_fstrdup(language);
    req->account_handle = vx_fstrdup(accountHandle);
    req->application_stanza_body = vx_fstrdup(applicationStanzaBody);
    req->application_stanza_namespace = vx_fstrdup(applicationStanzaNamespace);
    req->message_body = vx_fstrdup(message);
    req->user_uri = vx_fstrdup(dest.ToString());
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::SetLoginProperties(const FString &accountHandle, int participantPropertyFrequency)
{
    ensure(!accountHandle.IsEmpty());
    vx_req_account_set_login_properties_t *req;
    vx_req_account_set_login_properties_create(&req);
    req->account_handle = vx_fstrdup(accountHandle);
    req->participant_property_frequency = participantPropertyFrequency;
    return IssueRequest(&req->base, FOnRequestCompletedDelegate());
}

VivoxCoreError VivoxNativeSdk::SetNoSessionTransmitting(const FString& groupId)
{
    ensure(!groupId.IsEmpty());
    vx_req_sessiongroup_set_tx_no_session_t *req;
    vx_req_sessiongroup_set_tx_no_session_create(&req);
    req->sessiongroup_handle = vx_strdup(TCHAR_TO_UTF8(*groupId));
    return IssueRequest(&req->base, FOnRequestCompletedDelegate());
}

VivoxCoreError VivoxNativeSdk::SetAllSessionsTransmitting(const FString& groupId)
{
    ensure(!groupId.IsEmpty());
    vx_req_sessiongroup_set_tx_all_sessions_t *req;
    vx_req_sessiongroup_set_tx_all_sessions_create(&req);
    req->sessiongroup_handle = vx_strdup(TCHAR_TO_UTF8(*groupId));
    return IssueRequest(&req->base, FOnRequestCompletedDelegate());
}

VivoxCoreError VivoxNativeSdk::SetTransmittingSession(const FString& sessionId)
{
    ensure(!sessionId.IsEmpty());
    vx_req_sessiongroup_set_tx_session_t *req;
    vx_req_sessiongroup_set_tx_session_create(&req);
    req->session_handle = vx_strdup(TCHAR_TO_UTF8(*sessionId));
    return IssueRequest(&req->base, FOnRequestCompletedDelegate());
}

VivoxCoreError VivoxNativeSdk::RemoveSession(const FString& groupId, const FString& sessionId, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!groupId.IsEmpty());
    ensure(!sessionId.IsEmpty());
    vx_req_sessiongroup_remove_session *req;
    vx_req_sessiongroup_remove_session_create(&req);
    req->sessiongroup_handle = vx_strdup(TCHAR_TO_UTF8(*groupId));
    req->session_handle = vx_strdup(TCHAR_TO_UTF8(*sessionId));
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::SetAudioInputVolumeAdjustment(int32_t volume)
{
    if (volume < -50 || volume > 50)
        return VxErrorInvalidArgument;
    vx_req_aux_set_mic_level_t *req;
    vx_req_aux_set_mic_level_create(&req);
    req->level = static_cast<int>(volume) + 50;
    return IssueRequest(&req->base, FOnRequestCompletedDelegate());
}

VivoxCoreError VivoxNativeSdk::SetAudioOutputVolumeAdjustment(int32_t volume)
{
    if (volume < -50 || volume > 50)
        return VxErrorInvalidArgument;
    vx_req_aux_set_speaker_level_t *req;
    vx_req_aux_set_speaker_level_create(&req);
    req->level = static_cast<int>(volume) + 50;
    return IssueRequest(&req->base, FOnRequestCompletedDelegate());
}

VivoxCoreError VivoxNativeSdk::SetActiveAudioInputDevice(const FString& deviceId, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!deviceId.IsEmpty());
    vx_req_aux_set_capture_device_t*req;
    vx_req_aux_set_capture_device_create(&req);
    req->capture_device_specifier = vx_strdup(TCHAR_TO_UTF8(*deviceId));
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::SetActiveAudioOutputDevice(const FString& deviceId, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!deviceId.IsEmpty());
    vx_req_aux_set_render_device_t*req;
    vx_req_aux_set_render_device_create(&req);
    req->render_device_specifier = vx_strdup(TCHAR_TO_UTF8(*deviceId));
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::ConnectorCreate(const FString& server, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!server.IsEmpty());
    vx_req_connector_create *req;
    vx_req_connector_create_create(&req);
    req->connector_handle = vx_strdup(TCHAR_TO_UTF8(*server));
    req->acct_mgmt_server = vx_strdup(TCHAR_TO_UTF8(*server));
    return IssueRequest(&req->base, theDelegate);
}

AccountId  VivoxNativeSdk::GetRandomAccountId(const FString &issuer, const FString &domain, const FString &prefix)
{
    char *tmp = vx_get_random_user_id(TCHAR_TO_UTF8(*prefix));
    // strip off the trailing dot
    tmp[strlen(tmp) - 1] = 0;
    // strip off the leading dot
    AccountId id(issuer, tmp+1, domain);
    vx_free(tmp);
    return id;
}
ChannelId  VivoxNativeSdk::GetRandomChannelId(const FString &issuer, const FString &domain, const FString &prefix, ChannelType type)
{
    char *tmp = vx_get_random_user_id(TCHAR_TO_UTF8(*prefix));
    // strip off the trailing dot
    tmp[strlen(tmp) - 1] = 0;
    // strip off the leading dot
    ChannelId id(issuer, tmp+1, domain, type);
    vx_free(tmp);
    return id;
}
FString VivoxNativeSdk::GetLoginToken(const AccountId &account, const FString &key, const FTimespan &expiration)
{
    static long long sequence = 0;
    char *token = vx_debug_generate_token(TCHAR_TO_UTF8(*account.Issuer()), (FDateTime::UtcNow() + expiration).ToUnixTimestamp(), "login", sequence++, nullptr, TCHAR_TO_UTF8(*account.ToString()), nullptr, reinterpret_cast<unsigned char *>(TCHAR_TO_UTF8(*key)), key.Len());
    FString tmp = token;
    vx_free(token);
    return tmp;
}
FString VivoxNativeSdk::GetJoinToken(const AccountId &account, const ChannelId &channel, const FString &key, const FTimespan &expiration)
{
    static long long sequence = 0;
    char *token = vx_debug_generate_token(TCHAR_TO_UTF8(*account.Issuer()), (FDateTime::UtcNow() + expiration).ToUnixTimestamp(), "join", sequence++, nullptr, TCHAR_TO_UTF8(*account.ToString()), TCHAR_TO_UTF8(*channel.ToString()), reinterpret_cast<unsigned char *>(TCHAR_TO_UTF8(*key)), key.Len());
    FString tmp = token;
    vx_free(token);
    return tmp;
}
FString VivoxNativeSdk::GetMuteForAllToken(const AccountId &account, const ChannelId &channel, const AccountId &subject, const FString &key, const FTimespan &expiration)
{
    static long long sequence = 0;
    char *token = vx_debug_generate_token(TCHAR_TO_UTF8(*account.Issuer()), (FDateTime::UtcNow() + expiration).ToUnixTimestamp(), "mute", sequence++, TCHAR_TO_UTF8(*subject.ToString()), TCHAR_TO_UTF8(*account.ToString()), TCHAR_TO_UTF8(*channel.ToString()), reinterpret_cast<unsigned char *>(TCHAR_TO_UTF8(*key)), key.Len());
    FString tmp = token;
    vx_free(token);
    return tmp;
}
FString VivoxNativeSdk::GetTranscriptionToken(const AccountId &account, const ChannelId &channel, const FString &key, const FTimespan &expiration)
{
    static long long sequence = 0;
    char *token = vx_debug_generate_token(TCHAR_TO_UTF8(*account.Issuer()), (FDateTime::UtcNow() + expiration).ToUnixTimestamp(), "trxn", sequence++, nullptr, TCHAR_TO_UTF8(*account.ToString()), TCHAR_TO_UTF8(*channel.ToString()), reinterpret_cast<unsigned char *>(TCHAR_TO_UTF8(*key)), key.Len());
    FString tmp = token;
    vx_free(token);
    return tmp;
}

VivoxCoreError VivoxNativeSdk::ConnectMedia(const FString &sessionHandle, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!sessionHandle.IsEmpty());
    vx_req_session_media_connect_t *req;
    vx_req_session_media_connect_create(&req);
    req->session_handle = vx_fstrdup(sessionHandle);
    return IssueRequest(&req->base, theDelegate);
}
VivoxCoreError VivoxNativeSdk::DisconnectMedia(const FString &sessionHandle, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!sessionHandle.IsEmpty());
    vx_req_session_media_disconnect_t *req;
    vx_req_session_media_disconnect_create(&req);
    req->session_handle = vx_fstrdup(sessionHandle);
    return IssueRequest(&req->base, theDelegate);
}
VivoxCoreError VivoxNativeSdk::ConnectText(const FString &sessionHandle, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!sessionHandle.IsEmpty());
    vx_req_session_text_connect_t *req;
    vx_req_session_text_connect_create(&req);
    req->session_handle = vx_fstrdup(sessionHandle);
    return IssueRequest(&req->base, theDelegate);
}
VivoxCoreError VivoxNativeSdk::DisconnectText(const FString &sessionHandle, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!sessionHandle.IsEmpty());
    vx_req_session_text_disconnect_t *req;
    vx_req_session_text_disconnect_create(&req);
    req->session_handle = vx_fstrdup(sessionHandle);
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::SendMessage(const FString& sessionHandle,
    const FString& language,
    const FString& message,
    const FString& applicationStanzaNamespace,
    const FString& applicationStanzaBody,
    FOnRequestCompletedDelegate theDelegate)
{
    ensure(!sessionHandle.IsEmpty());
    vx_req_session_send_message_t *req;
    vx_req_session_send_message_create(&req);
    req->session_handle = vx_fstrdup(sessionHandle);
    req->application_stanza_body = vx_fstrdup(applicationStanzaBody);
    req->application_stanza_namespace = vx_fstrdup(applicationStanzaNamespace);
    req->language = vx_fstrdup(language);
    req->message_body = vx_fstrdup(message);
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::ControlCommunications(const FString& accountHandle, vx_control_communications_operation operation, const FString& user_uris, vx_mute_scope scope, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!accountHandle.IsEmpty());
    vx_req_account_control_communications_t *req;
    vx_req_account_control_communications_create(&req);
    req->account_handle = vx_fstrdup(accountHandle);
    req->operation = operation;
    req->user_uris = vx_fstrdup(user_uris);
    req->scope = scope;
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::SetParticipantVolume(const FString& sessionHandle, const FString& participantUri, int volume, FOnRequestCompletedDelegate theDelegate)
{
    if (volume < -50 || volume > 50)
        return VxErrorInvalidArgument;
    vx_req_session_set_participant_volume_for_me_t *req;
    vx_req_session_set_participant_volume_for_me_create(&req);
    req->session_handle = vx_fstrdup(sessionHandle);
    req->participant_uri = vx_fstrdup(participantUri);
    req->volume = volume + 50;
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::SetParticipantMuted(const FString& sessionHandle, const FString& participantUri, bool muted, FOnRequestCompletedDelegate theDelegate)
{
    vx_req_session_set_participant_mute_for_me_t *req;
    vx_req_session_set_participant_mute_for_me_create(&req);
    req->session_handle = vx_fstrdup(sessionHandle);
    req->participant_uri = vx_fstrdup(participantUri);
    req->mute = muted ? 1 : 0;
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::SetParticipantMutedForAll(const FString& accountHandle, const FString& channelUri, const FString& participantUri, bool muted, const FString &accessToken, FOnRequestCompletedDelegate theDelegate)
{
    vx_req_channel_mute_user_t *req;
    vx_req_channel_mute_user_create(&req);
    req->account_handle = vx_fstrdup(accountHandle);
    req->channel_uri = vx_fstrdup(channelUri);
    req->participant_uri = vx_fstrdup(participantUri);
    req->set_muted = muted ? 1 : 0;
    req->access_token = vx_strdup(TCHAR_TO_UTF8(*accessToken));
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::SetPresence(const FString& accountHandle, const FString& message, vx_buddy_presence_state state, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!accountHandle.IsEmpty());

    vx_req_account_set_presence_t *req;
    vx_req_account_set_presence_create(&req);
    req->account_handle = vx_fstrdup(accountHandle);
    req->custom_message = vx_fstrdup(message);
    req->presence = state;
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::Set3DPosition(const FString& sessionHandle,
    const FVector &speakerPosition,
    const FVector &listenerPosition,
    const FVector &listenerForwardVector,
    const FVector &listenerUpVector)
{
    ensure(!sessionHandle.IsEmpty());
    vx_req_session_set_3d_position_t *req;
	vx_req_session_set_3d_position_create(&req);
	req->session_handle = vx_fstrdup(sessionHandle);
	req->speaker_position[0] = speakerPosition.Y;
	req->speaker_position[1] = speakerPosition.Z;
	req->speaker_position[2] = -speakerPosition.X;
	req->listener_position[0] = listenerPosition.Y;
	req->listener_position[1] = listenerPosition.Z;
	req->listener_position[2] = -listenerPosition.X;
	req->listener_at_orientation[0] = listenerForwardVector.Y;
	req->listener_at_orientation[1] = listenerForwardVector.Z;
	req->listener_at_orientation[2] = -listenerForwardVector.X;
	req->listener_up_orientation[0] = listenerUpVector.Y;
	req->listener_up_orientation[1] = listenerUpVector.Z;
	req->listener_up_orientation[2] = -listenerUpVector.X;
	req->req_disposition_type = req_disposition_no_reply_required;
    return IssueRequest(&req->base, FOnRequestCompletedDelegate());
}

VivoxCoreError VivoxNativeSdk::StartAudioInjection(const FString &groupHandle, const FString &filePath, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!groupHandle.IsEmpty());
    vx_req_sessiongroup_control_audio_injection_t *req;
    vx_req_sessiongroup_control_audio_injection_create(&req);
    req->audio_injection_control_type = vx_sessiongroup_audio_injection_control_type::vx_sessiongroup_audio_injection_control_start;
    req->sessiongroup_handle = vx_fstrdup(groupHandle);
    req->filename = vx_fstrdup(filePath);
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::StopAudioInjection(const FString &groupHandle)
{
    ensure(!groupHandle.IsEmpty());
    vx_req_sessiongroup_control_audio_injection_t *req;
    vx_req_sessiongroup_control_audio_injection_create(&req);
    req->audio_injection_control_type = vx_sessiongroup_audio_injection_control_type::vx_sessiongroup_audio_injection_control_stop;
    req->sessiongroup_handle = vx_fstrdup(groupHandle);
    return IssueRequest(&req->base, FOnRequestCompletedDelegate());
}

VivoxCoreError VivoxNativeSdk::SetTranscription(bool value, const FString &sessionHandle, const FString &accessToken, FOnRequestCompletedDelegate theDelegate)
{
    ensure(!sessionHandle.IsEmpty());
    vx_req_session_transcription_control_t *req;
    vx_req_session_transcription_control_create(&req);
    req->enable = value;
    req->session_handle = vx_fstrdup(sessionHandle);
    req->access_token = vx_fstrdup(accessToken);
    return IssueRequest(&req->base, theDelegate);
}

VivoxCoreError VivoxNativeSdk::TTSGetVoices(const vx_tts_manager_id &managerId, int *numVoices, vx_tts_voice_t **voices)
{
    vx_tts_status status = vx_tts_get_voices(managerId, numVoices, voices);
    if (tts_status_success != status)
        *voices = nullptr;

    return (VivoxCoreError)status;
}

VivoxCoreError VivoxNativeSdk::TTSSpeak(const vx_tts_manager_id &managerId, const ITTSVoice &voice, const FString &text, const TTSDestination &destination, ITTSMessage **outMessage)
{
    vx_tts_utterance_id utteranceId;
    vx_tts_status status = vx_tts_speak(managerId, voice.VoiceId(), vx_fstrdup(text), (vx_tts_destination)destination, &utteranceId);
    if (tts_status_success == status || tts_status_input_text_was_enqueued == status)
        *outMessage = new TTSMessageImpl(TTSVoiceImpl(voice), text, destination, utteranceId, tts_status_input_text_was_enqueued == status ? TTSMessageState::Enqueued : TTSMessageState::Playing);
    else
        *outMessage = nullptr;

    return (VivoxCoreError)status;
}

VivoxCoreError VivoxNativeSdk::TTSSpeakToBuffer(const vx_tts_manager_id &managerId, const ITTSVoice &voice, const FString &text, ITTSAudioBuffer **outBuffer)
{
    vx_tts_utterance *utterance;
    vx_tts_status status = vx_tts_speak_to_buffer(managerId, voice.VoiceId(), vx_fstrdup(text), &utterance);
    if (tts_status_success == status)
        *outBuffer = new TTSAudioBufferImpl(managerId, utterance);
    else
        *outBuffer = nullptr;

    return (VivoxCoreError)status;
}

VivoxCoreError VivoxNativeSdk::TTSCancelMessage(const vx_tts_manager_id &managerId, const ITTSMessage &message)
{
    vx_tts_status status = vx_tts_cancel_utterance(managerId, message.UtteranceId());
    return (VivoxCoreError)status;
}

VivoxCoreError VivoxNativeSdk::TTSCancelDestination(const vx_tts_manager_id &managerId, const TTSDestination &destination)
{
    vx_tts_status status = vx_tts_cancel_all_in_dest(managerId, (vx_tts_destination)destination);
    return (VivoxCoreError)status;
}

VivoxCoreError VivoxNativeSdk::TTSCancelAll(const vx_tts_manager_id &managerId)
{
    vx_tts_status status = vx_tts_cancel_all(managerId);
    return (VivoxCoreError)status;
}
