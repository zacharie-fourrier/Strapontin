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
#include "Tickable.h"
#include "Modules/ModuleManager.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "VivoxCoreCommon.h"

#include "IClient.h"
#include "IAudioDevice.h"
#include "IAudioDevices.h"
#include "IChannelSession.h"
#include "IChannelConnectionState.h"
#include "IChannelTextMessage.h"
#include "ITranscribedMessage.h"
#include "IDirectedTextMessage.h"
#include "ILoginSession.h"
#include "IParticipant.h"
#include "IPresenceLocation.h"
#include "IPresenceSubscription.h"
#include "ITTSAudioBuffer.h"
#include "Presence.h"

class ClientImpl;

/**
 * \brief An Unreal Engine 4 plugin for Vivox voice.
 */
class VIVOXCORE_API FVivoxCoreModule : public FTickableGameObject, public FSelfRegisteringExec, public IModuleInterface, public IModularFeature
{
public:

    /**
     * \brief Constructor
     */
    FVivoxCoreModule();

    /** \brief IModuleInterface implementation  - called on Modules startup */
    void StartupModule() override;
    /** \brief IModuleInterface implementation  - called on Module shutdon */
    void ShutdownModule() override;

    /* @cond */
    /** FTickableGameObject implementation */
    bool IsTickable() const override { return true; }
    bool IsTickableInEditor() const override { return true; }
    bool IsTickableWhenPaused() const override { return true; }

    TStatId GetStatId() const override
    {
        return TStatId();
    }

    void Tick(float DeltaTime) override;

    /* FSelfRegisteringExec implementation */
    /**
    * Exec handler
    *
    * \param	Inworld	World context
    * \param	Cmd		Command to parse
    * \param	Ar		Output device to log to
    *
    * \return	True if the command was handled, false otherwise.
    */
    virtual bool Exec(UWorld* Inworld, const TCHAR* Cmd, FOutputDevice& Ar) override;

    void OnWorldCreated(UWorld* World, const UWorld::InitializationValues IVS);
    void OnWorldDestroyed(UWorld* World);
    /* @endcond */

    /**
     * \brief The voice client.
     * \return The voice client.
     */
    IClient &VoiceClient() const;

    /**
     * \brief Get a random account identifier. For internal testing purposes only.
     */
    static AccountId GetRandomAccountId(const FString &issuer, const FString &domain, const FString &prefix);
    /**
    * \brief Get a random channel identifier. For internal testing purposes only.
    */
    static ChannelId GetRandomChannelId(const FString &issuer, const FString &domain, const FString &prefix, ChannelType type);
    /**
     ** \brief Get the UTF-8 string for a specific error code in US English.
     */
    static const char *ErrorToString(VivoxCoreError error);
private:
#if PLATFORM_WINDOWS || PLATFORM_MAC
    void *LoadALibrary(const TCHAR *libraryName);
#endif // PLATFORM_WINDOWS || PLATFORM_MAC

    /** Handle to the test dll we will load */
    void* _oRTPHandle;
    void* _vivoxSdkHandle;
    mutable ClientImpl *_voiceClient;
};
