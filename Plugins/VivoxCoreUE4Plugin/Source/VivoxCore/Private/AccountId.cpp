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

#include "AccountId.h"
#include "VivoxCore.h"
#include "VivoxCoreCommonImpl.h"
#include "Internationalization/Regex.h"

AccountId AccountId::CreateFromUri(const FString& uri, const TOptional<FString>& displayName)
{
    if (uri.IsEmpty())
        return AccountId();

    const FRegexPattern regex("sip:\\.([^.]+)\\.([^@]+)\\.@([^@]+)");
    FRegexMatcher matcher(regex, uri);
    AccountId id;
    bool found = matcher.FindNext();
    ensure(found);
    if(found) {
        id._issuer = matcher.GetCaptureGroup(1);
        id._name = matcher.GetCaptureGroup(2);
        id._domain = matcher.GetCaptureGroup(3);
        if (displayName.IsSet())
            id._displayName = displayName.GetValue();
        ensure(id.IsValid());
        return id; // may be invalid
    }
    return AccountId();
}

FString AccountId::AccountNameFromUri(const FString &uri)
{
    return CreateFromUri(uri).Name();
}

AccountId::AccountId()
{
}

AccountId::AccountId(const FString& issuer, const FString& name, const FString& domain, const TOptional<FString>& displayName, const TOptional<TArray<FString>>& spokenLanguages)
{
    ensure(!issuer.IsEmpty());
    ensure(!name.IsEmpty());
    ensure(!domain.IsEmpty());

    _issuer = issuer;
    _name = name;
    _domain = domain;
    if (displayName.IsSet())
        _displayName = displayName.GetValue();
    if (spokenLanguages.IsSet()) {
        _spokenLanguages = spokenLanguages.GetValue();
        for (int32 Index = 0; Index != _spokenLanguages.Num(); ++Index)
            _spokenLanguages[Index].RemoveSpacesInline();
    }
}

AccountId::~AccountId()
{
}

const FString& AccountId::Issuer() const
{
    return _issuer;
}

const FString& AccountId::Name() const
{
    return _name;
}

const FString& AccountId::Domain() const
{
    return _domain;
}

const FString& AccountId::DisplayName() const
{
    return _displayName;
}

const TArray<FString>& AccountId::SpokenLanguages() const
{
    return _spokenLanguages;
}

bool AccountId::IsEmpty() const
{
    return _issuer.IsEmpty() && _name.IsEmpty() && _domain.IsEmpty();
}

FString AccountId::ToString() const
{
    if (IsEmpty()) return FString();
    return "sip:." + _issuer + "." + _name + ".@" + _domain;
}

bool AccountId::operator==(const AccountId& RHS) const
{
    return _issuer == RHS._issuer && _name == RHS._name && _domain == RHS._domain;
}

bool AccountId::IsNullOrEmpty(AccountId* id)
{
    return id == nullptr || id->IsEmpty();
}

uint32 GetTypeHash(const AccountId& id)
{
    uint32 hc = GetTypeHash(id.Name());
    hc *= 397;
    hc ^= GetTypeHash(id.Issuer());
    hc *= 397;
    hc ^= GetTypeHash(id.Domain());
    return hc;
}

bool AccountId::IsValid() const
{
    // FTCHARToUTF8::Length() returns the number of bytes for the encoded string,
    // excluding the null terminator. This accounts for mixed multi-byte characters.
    int32 displayNameByteCount = ((FTCHARToUTF8)*_displayName).Length();

    if (_issuer.IsEmpty()
     || _domain.IsEmpty()
     || _name.Len() + _issuer.Len() > 124
     || displayNameByteCount > 63)
    {
        return false;
    }
    FString ValidCharacters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890=+-_.!~()%";
    int32 loc;
    auto ConstItrN = _name.CreateConstIterator();
    while (_name.IsValidIndex(ConstItrN.GetIndex()))
        if (!ValidCharacters.FindChar(_name[ConstItrN++.GetIndex()], loc))
            return false;

    // no spokenLanguages validation.
    return true;
}
