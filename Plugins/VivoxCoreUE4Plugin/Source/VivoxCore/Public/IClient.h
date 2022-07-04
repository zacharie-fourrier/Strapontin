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

/**
 * \brief Provides access to the Vivox voice system.
 */
class VIVOXCORE_API IClient
{
public:
    virtual ~IClient() = default;
    /**
     * \brief Initializes this Client instance.
     * If the client is already initialized, then this does nothing and returns VxErrorAlreadyInitialized.
     * \param sdkConfig The config to initialize with, which allows for the customization of certain aspects of the Vivox SDK.
     * \return VxErrorSuccess under most circumstances. Note that failures to initialize are rare.
     */
    virtual VivoxCoreError Initialize(VivoxConfig sdkConfig = VivoxConfig()) = 0;
    /**
     * \brief Uninitialize this Client instance. If this Client instance is not initialized, then this does nothing.
     */
    virtual void Uninitialize() = 0;

    /**
     * \brief The internal version of the low-level vivoxsdk library.
     */
    static FString InternalVersion();

    /**
     * \brief The internal version of the low-level vivoxsdk library with extended information.
     */
    static FString InternalVersionExtended();

    /**
     * \brief Gets the LoginSession object for the provided accountId, and creates one if necessary.
     * \param loginSessionId The AccountId for this login session.
     * \return The login session for that accountId.
     * \remarks If a new login session is created, then LoginSessions.AfterKeyAdded is raised.</remarks>
     */
    virtual ILoginSession &GetLoginSession(const AccountId &loginSessionId) = 0;

    /**
     * \brief All of the login sessions that are associated with this Client instance.
     */
    virtual const TMap<AccountId, TSharedPtr<ILoginSession>> & LoginSessions() = 0;

    /**
     * \brief The audio input devices that are associated with this Client instance.
     */
    virtual IAudioDevices &AudioInputDevices() = 0;

    /**
     * \brief The audio output devices that are associated with this Client instance.
     */
    virtual IAudioDevices &AudioOutputDevices() = 0;
};
