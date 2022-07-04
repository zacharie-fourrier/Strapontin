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

#include "CoreMinimal.h"

typedef int32 VivoxCoreError;
#define APP_UNIQUE_3_LETTERS_USER_AGENT_ID_STRING "UNR"

#ifndef VxErrorSuccess
// We need these for use in Unreal applications, but we cannot include VxcErrors.h
// without pulling in extra code that we do not want, so we must capture specific content
// without causing macro redefinitions.

// Error code definitions (V4) for V5 macro compatibility only
#define VX_E_NO_MESSAGE_AVAILABLE                           -1
#define VX_E_SUCCESS                                        0
#define VX_E_NO_EXIST                                       1001
#define VX_E_FAILED                                         1004
#define VX_E_INVALID_ARGUMENT                               1008
#define VX_E_NOT_INITIALIZED                                1012
#define VX_E_NOT_IMPL                                       1017
#define VX_E_INVALID_SESSION_STATE                          1019
#define VX_E_FILE_OPEN_FAILED                               1043  // The file could not be opened - does not exist, locked, or insufficient privilege
#define VX_E_RTP_TIMEOUT                                    1058
#define VX_E_FAILED_TO_CONNECT_TO_VOICE_SERVICE             1072
#define VX_E_FAILED_TO_SEND_REQUEST_TO_VOICE_SERVICE        1073
#define VX_E_ALREADY_INITIALIZED                            1085
#define VX_E_NOT_UNINITIALIZED_YET                          1086
#define VX_E_CALL_TERMINATED_NO_RTP_RXED                    1095
#define VX_E_SIP_BACKEND_REQUIRED                           1105
#define VX_E_DEPRECATED                                     1106
#define VX_E_FAILED_TO_CONNECT_TO_SERVER    10007

// Error code definitions (V5)
#define VxErrorNoMessageAvailable VX_E_NO_MESSAGE_AVAILABLE  // Old value is -1 (not changed)
#define VxErrorSuccess VX_E_SUCCESS  // Old value is 0 (not changed)
#define VxErrorAsyncOperationCanceled 5001
#define VxErrorCaptureDeviceInUse 5002
#define VxErrorConnectionTerminated 5003
#define VxErrorFileOpenFailed VX_E_FILE_OPEN_FAILED  // Old value is 5004
#define VxErrorHandleReserved 5005
#define VxErrorHandleTaken 5006
#define VxErrorInternalError VX_E_FAILED  // Old value is 5007
#define VxErrorInvalidArgument VX_E_INVALID_ARGUMENT  // Old value is 5008
#define VxErrorInvalidFormat 5009
#define VxErrorInvalidOperation 5010
#define VxErrorInvalidState VX_E_INVALID_SESSION_STATE  // Old value is 5011
#define VxErrorInvalidValueTypeXmlQuery 5012
#define VxErrorNoMatchingXmlAttributeFound 5013
#define VxErrorNoMatchingXmlNodeFound 5014
#define VxErrorNoMemory 5015
#define VxErrorNoMoreData 5016
#define VxErrorNoXLSPConfigured 5017
#define VxErrorNotSupported 5018
#define VxErrorPortNotAvailable 5019
#define VxErrorRtpTimeout VX_E_RTP_TIMEOUT  // Old value is 5020
#define VxErrorUnableToOpenCaptureDevice 5021
#define VxErrorXLSPConnectFailed 5022
#define VxErrorXmppBackEndRequired 5023
#define VxErrorPreloginDownloadFailed 5024
#define VxErrorNotLoggedIn 5025
#define VxErrorPresenceMustBeEnabled 5026
#define VxErrorConnectorLimitExceeded 5027
#define VxErrorTargetObjectNotRelated 5028
#define VxErrorTargetObjectDoesNotExist VX_E_NO_EXIST  // Old value is 5029
#define VxErrorMaxLoginsPerUserExceeded 5030
#define VxErrorRequestCanceled 5031
#define VxErrorBuddyDoesNotExist 5032
#define VxErrorChannelUriRequired 5033
#define VxErrorTargetObjectAlreadyExists 5034
#define VxErrorInvalidCaptureDeviceForRequestedOperation 5035
#define VxErrorInvalidCaptureDeviceSpecifier 5036
#define VxErrorInvalidRenderDeviceSpecifier 5037
#define VxErrorDeviceLimitReached 5038
#define VxErrorInvalidEventType 5039
#define VxErrorNotInitialized VX_E_NOT_INITIALIZED  // Old value is 5040
#define VxErrorAlreadyInitialized VX_E_ALREADY_INITIALIZED  // Old value is 5041
#define VxErrorNotImplemented VX_E_NOT_IMPL  // Old value is 5042
#define VxErrorTimeout 5043
#define VxNoAuthenticationStanzaReceived 5044
#define VxFailedToConnectToXmppServer 5045
#define VxSSLNegotiationToXmppServerFailed 5046
#define VxErrorUserOffLineOrDoesNotExist 5047
#define VxErrorCaptureDeviceInvalidated 5048
#define VxErrorMaxEtherChannelLimitReached 5049
#define VxErrorHostUnknown 5050
#define VxErrorChannelUriTooLong 5051
#define VxErrorUserUriTooLong 5052
#define VxErrorNotUninitializedYet VX_E_NOT_UNINITIALIZED_YET  // Old value is 5075
#define VxErrorCallTerminatedKick 5099
#define VxErrorCallTerminatedByServer 5100
#define VxErrorServerRtpTimeout VX_E_CALL_TERMINATED_NO_RTP_RXED  // Old value is 5101
#define VxErrorDeprecated VX_E_DEPRECATED

// 20xxx-20xxx - Reserved for 3-digit XMPP error codes returned from server
#define VxXmppErrorCodesRangeStart 20000
#define VxUnknownXmppError 20000
#define VxAccessTokenAlreadyUsed 20120
#define VxAccessTokenExpired 20121
#define VxAccessTokenInvalidSignature 20122
#define VxAccessTokenClaimsMismatch 20123
#define VxAccessTokenMalformed 20124
#define VxAccessTokenInternalError 20125
#define VxAccessTokenServiceUnavailable 20127
#define VxAccessTokenIssuerMismatch 20128
#define VxXmppErrorBadRequest 20400
#define VxXmppInternalServerError 20500
#define VxXmppServerErrorServiceUnavailable 20502
#define VxXmppErrorServiceUnavailable 20503
#define VxXmppErrorCodesRangeEnd 20999

// 21000+ - Internal XMPP error codes
#define VxErrorXmppServerResponseMalformed 21000
#define VxErrorXmppServerResponseBadSdp 21001
#define VxErrorXmppServerResponseInviteMissing 21002
#define VxErrorXmppServerResponseChanAddMissing 21003

#define VxNetworkNameResolutionFailed 10006
#define VxNetworkUnableToConnectToServer 10007
#define VxNetworkHttpTimeout 10028
#define VxNetworkHttpInvalidUrl 10003
#define VxNetworkHttpInvalidCertificate 10077
#define VxNetworkHttpConnectionReset 10056
#define VxNetworkHttpInvalidServerResponse 10052
#define VxNetworkHttpGeneralConnectionFailure 10100

// Compatibility
#define VX_E_XMPP_BACKEND_REQUIRED VxErrorXmppBackEndRequired
#define VxErrorSipBackEndRequired VX_E_SIP_BACKEND_REQUIRED

// Text-to-speech (TTS)
#define VxErrorTTSInvalidEngineType tts_error_invalid_engine_type
#define VxErrorTTSEngineAllocationFailed tts_error_engine_allocation_failed
#define VxErrorTTSNotSupported tts_error_not_supported
#define VxErrorTTSMaxCharactersExceeded tts_error_max_characters_exceeded
#define VxErrorTTSUtteranceBelowMinDuration tts_error_utterance_below_min_duration
#define VxStatusTTSInputTextWasEnqueued tts_status_input_text_was_enqueued
#define VxErrorTTSSdkNotInitialized tts_error_sdk_not_initialized
#define VxErrorTTSDestinationQueueIsFull tts_error_destination_queue_is_full
#define VxStatusTTSEnqueueNotNecessary tts_status_enqueue_not_necessary
#define VxErrorTTSUtteranceNotFound tts_error_utterance_not_found
#define VxErrorTTSManagerNotFound tts_error_manager_not_found
#define VxErrorTTSInvalidArgument tts_error_invalid_argument
#define VxErrorTTSInternal tts_error_internal

#endif

#include "VivoxConfig.h"
#include "AccountId.h"
#include "ChannelId.h"
#include "Presence.h"
#include "ConnectionState.h"
#include "Channel3DProperties.h"
class AccountId;
class ChannelId;
class IAudioDevice;
class IAudioDevices;
class IChannelSession;
class IChannelConnectionState;
class IChannelTextMessage;
class ITranscribedMessage;
class Channel3DProperties;
class IDirectedTextMessage;
class IClient;
class ILoginSession;
class IParticipant;
class IParticipantProperties;
class IPresenceLocation;
class IPresenceSubscription;
class ITextMessage;
class ITTSAudioBuffer;
class ITTSMessage;
class ITTSVoice;
class Presence;
