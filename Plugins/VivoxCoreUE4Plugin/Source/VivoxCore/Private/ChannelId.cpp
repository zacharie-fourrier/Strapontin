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

#include "ChannelId.h"
#include "VivoxCore.h"
#include "Internationalization/Regex.h"

FString GetUriDesignator(ChannelType value)
{
    switch (value)
    {
    case ChannelType::Echo:
        return "e";
    case ChannelType::NonPositional:
        return "g";
    case ChannelType::Positional:
        return "d";
    }
    ensure("Invalid ChannelType" && false);
    return FString();
}

ChannelId ChannelId::CreateFromUri(const FString& uri)
{
    if (uri.IsEmpty())
        return ChannelId();
    const FRegexPattern regex("sip:confctl-(e|g|d)-([^.]+).([^!@]+)([^@]+)?@([^@]+)");
    FRegexMatcher matcher(regex, uri);
    ChannelId id;
    bool found = matcher.FindNext();
    ensure(found);
    if (found) {
        FString type = matcher.GetCaptureGroup(1);
        id._issuer = matcher.GetCaptureGroup(2);
        id._name = matcher.GetCaptureGroup(3);
        id._domain = matcher.GetCaptureGroup(5);
        if (type == "g")
            id._type = ChannelType::NonPositional;
        else if (type == "e")
            id._type = ChannelType::Echo;
        else if (type == "d")
        {
            id._type = ChannelType::Positional;
            id._properties = Channel3DProperties::CreateFromString(matcher.GetCaptureGroup(4));
        }
        else
        {
            ensure("Invalid Channel Type String" && false);
        }
        ensure(id.IsValid());
        return id; // may be invalid
    }
    return ChannelId();
}

ChannelId::ChannelId()
{
    _type = ChannelType::NonPositional;
}

ChannelId::ChannelId(const FString& issuer, const FString& name, const FString& domain, ChannelType type, Channel3DProperties properties)
{
    ensure(!issuer.IsEmpty());
    ensure(!name.IsEmpty());
    ensure(!domain.IsEmpty());
    _issuer = issuer;
    _name = name;
    _domain = domain;
    _type = type;
    _properties = properties;
}

ChannelId::~ChannelId()
{
}

const FString& ChannelId::Issuer() const
{
    return _issuer;
}

const FString& ChannelId::Name() const
{
    return _name;
}

const FString& ChannelId::Domain() const
{
    return _domain;
}

ChannelType ChannelId::Type() const
{
    return _type;
}

Channel3DProperties ChannelId::Properties() const
{
    return _properties;
}

bool ChannelId::IsEmpty() const
{
    return _name.IsEmpty() && _domain.IsEmpty() && _issuer.IsEmpty() && _type == ChannelType::NonPositional;
}

FString ChannelId::ToString() const
{
    if (IsEmpty())
        return FString();
    FString prefix;
    FString props;
    switch (_type) {
    case ChannelType::Echo:
        prefix = "sip:confctl-e-"; break;
    case ChannelType::NonPositional:
        prefix = "sip:confctl-g-"; break;
    case ChannelType::Positional:
        prefix = "sip:confctl-d-";
        props = _properties.ToString();
        break;
    }
    ensure(!prefix.IsEmpty());
    return prefix + _issuer + "." + _name + (props.IsEmpty() ? "" : "!"+props) + "@" + _domain;
}

bool ChannelId::IsNullOrEmpty(ChannelId* id)
{
    return id == nullptr || id->IsEmpty();
}

bool ChannelId::operator==(const ChannelId& RHS) const
{
    return _type == RHS._type &&
        _name == RHS._name &&
        _issuer == RHS._issuer &&
        _domain == RHS._domain;
}

uint32 GetTypeHash(const ChannelId& id)
{
    uint32 hc = GetTypeHash(id.Name());
    hc *= 397;
    hc ^= GetTypeHash(id.Issuer());
    hc *= 397;
    hc ^= GetTypeHash(id.Domain());
    hc *= 397;
    hc ^= GetTypeHash(static_cast<uint32>(id.Type()));
    return hc;
}

bool ChannelId::IsValid() const
{
    if (_issuer.IsEmpty()
     || _domain.IsEmpty()
     || _name.Len() > 200
     || (_type == ChannelType::Positional && !_properties.IsValid()))
    {
        return false;
    }
    FString ValidCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890=+-_.!~()%";
    int32 loc;
    auto ConstItr = _name.CreateConstIterator();
    while (_name.IsValidIndex(ConstItr.GetIndex()))
        if (!ValidCharacters.FindChar(_name[ConstItr++.GetIndex()], loc))
            return false;

    return true;
}
