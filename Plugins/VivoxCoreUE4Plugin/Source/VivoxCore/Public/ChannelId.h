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
#include "Engine/Blueprint.h"
#include "Containers/UnrealString.h"
#include "Channel3DProperties.h"

/**
 * \brief The type of channel.
 */
UENUM(BlueprintType)
enum class ChannelType : uint8
{
    /**
     * \brief A typical conferencing channel.
     */
    NonPositional,
    /**
     * \brief A conferencing channel where user voices are rendered with 3D positional effects.
     */
    Positional,
    /**
     * \brief A conferencing channel where the user's text and audio is echoed back to that user.
     */
    Echo
};

/**
 * \brief The unique identifier for a channel. Channels are created and destroyed automatically on demand.
 */
class VIVOXCORE_API ChannelId
{
    FString _domain;
    FString _name;
    FString _issuer;
    ChannelType _type;
    Channel3DProperties _properties;
public:
    /**
     * \brief Internal use only.
     */
    static ChannelId CreateFromUri(const FString &uri);

    /**
     * \brief Constructor
     */
    ChannelId();
    /**
     * \brief Constructor
     * \param issuer The issuer that is responsible for authenticating this channel.
     * \param name The name you assigned to the channel.
     * \param domain The Vivox domain that provides service for this channel, for example: mt1s.vivox.com.
     * \param type The type of channel, each with built-in characteristics (for example, 3D positional effects).
     * \param properties The 3D properties of the channel. Note: This is optional, and is only used for positional channels.
     * \remarks Name must not exceed 200 characters, and can only use the letters A-Z and a-z, the numbers 0-9, and the special characters =+-_.!~()%
     */
    ChannelId(const FString &issuer, const FString &name, const FString &domain, ChannelType type = ChannelType::NonPositional, Channel3DProperties properties = Channel3DProperties());
    /**
     * \brief Destructor
     */
    ~ChannelId();

    /**
     * \brief The issuer that is responsible for authenticating this channel.
     */
    const FString &Issuer() const;
    /**
     * \brief The name you assigned to the channel.
     */
    const FString &Name() const;
    /**
     * \brief The Vivox domain that provides service for this channel.
     */
    const FString &Domain() const;
    /**
     * \brief The type of channel.
     */
    ChannelType Type() const;
    /**
     * \brief The 3D properties of the channel.
     */
    Channel3DProperties Properties() const;
    /**
     * \brief True if Issuer, Name, and Domain are all empty, and Type is NonPositional.
     */
    bool IsEmpty() const;

    /**
     * \brief True if Issuer and Domain are non-empty, and Name and Properties meet restrictions.
     */
    bool IsValid() const;

    /**
     * \brief Internal use only.
     */
    FString ToString() const;

    /** \brief Equality operator */
    bool operator ==(const ChannelId &RHS) const;
    /** \brief InEquality operator */
    bool operator !=(const ChannelId &RHS) const { return !operator ==(RHS); }

    /**
     * \brief True if the ID is null or empty.
     */
    static bool IsNullOrEmpty(ChannelId *id);
};

/**
 * \brief A standard Unreal Engine hash function that allows ChannelId to be used as a key in UE4 collections.
 * \param id The channel ID.
 * \return The hash.
 */
uint32 VIVOXCORE_API GetTypeHash(const ChannelId &id);
