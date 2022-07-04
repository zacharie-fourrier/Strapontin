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

using System.IO;
using UnrealBuildTool;

public class VivoxCoreLibrary : ModuleRules
{
    public VivoxCoreLibrary(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;
        UnrealTargetPlatform parsedPlatform;

        if (UnrealTargetPlatform.TryParse("Win64", out parsedPlatform) && Target.Platform == parsedPlatform)
        {
            // Add the Win64 specific Include and Library paths
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Windows", "include"));
            string VivoxLibraryPath = Path.Combine(ModuleDirectory, "Windows", "Release", "x64");

            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "vivoxsdk.lib"));

            // Delay-load the DLL, so we can load it from the right place
            PublicDelayLoadDLLs.Add("vivoxsdk.dll");
            RuntimeDependencies.Add(Path.Combine(VivoxLibraryPath, "vivoxsdk.dll"));
        }
        else if (UnrealTargetPlatform.TryParse("XboxOne", out parsedPlatform) && Target.Platform == parsedPlatform)
        {
            // Add the XboxOne specific Include and Library paths
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "XB1", "include"));
            string VivoxLibraryPath = Path.Combine(ModuleDirectory, "XB1", "Release");

            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "vivoxsdk.lib"));
        }
        else if (UnrealTargetPlatform.TryParse("PS4", out parsedPlatform) && Target.Platform == parsedPlatform)
        {
            // Add the PS4 specific Include and Library paths
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "PlayStation4", "include"));
            string VivoxLibraryPath = Path.Combine(ModuleDirectory, "PlayStation4", "Release");

            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "libvivoxsdk.a"));
#if UE_4_24_OR_LATER
            PublicSystemLibraries.Add("SceSha1");
            PublicSystemLibraries.Add("SceAudioIn_stub_weak");
            PublicSystemLibraries.Add("SceHmac");
#else
            PublicAdditionalLibraries.Add("SceSha1");
            PublicAdditionalLibraries.Add("SceAudioIn_stub_weak");
            PublicAdditionalLibraries.Add("SceHmac");
#endif
        }
        else if (UnrealTargetPlatform.TryParse("Mac", out parsedPlatform) && Target.Platform == parsedPlatform)
        {
            // Add the Mac specific Include and Library paths
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Mac", "include"));
            string VivoxLibraryPath = Path.Combine(ModuleDirectory, "Mac", "Release");
            string EnginePluginPath = Path.Combine(Path.GetFullPath(Target.RelativeEnginePath), "Plugins", "VivoxCore", "Source", "ThirdParty", "VivoxCoreLibrary", "Mac", "Release");
            string ortpLib = "libortp.dylib";
            string sdkLib = "libvivoxsdk.dylib";

            // Delay-load the DLLs, so we can load them from the right place
            PublicDelayLoadDLLs.Add(Path.Combine(EnginePluginPath, ortpLib));
            PublicDelayLoadDLLs.Add(Path.Combine(EnginePluginPath, sdkLib));
            RuntimeDependencies.Add(Path.Combine(EnginePluginPath, ortpLib), Path.Combine(VivoxLibraryPath, ortpLib), StagedFileType.NonUFS);
            RuntimeDependencies.Add(Path.Combine(EnginePluginPath, sdkLib), Path.Combine(VivoxLibraryPath, sdkLib), StagedFileType.NonUFS);
        }
        else if (UnrealTargetPlatform.TryParse("Android", out parsedPlatform) && Target.Platform == parsedPlatform)
        {
            // Add the Android specific Include and Library paths
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Android", "include"));
            string VivoxLibraryPath = Path.Combine(ModuleDirectory, "Android", "Release");

            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "arm64-v8a", "libvivox-sdk.so"));
            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "armeabi-v7a", "libvivox-sdk.so"));
            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "x86", "libvivox-sdk.so"));
            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "x86_64", "libvivox-sdk.so"));

            PublicDependencyModuleNames.AddRange(new string[] { "Launch" });
            string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", Path.Combine(PluginPath, "VivoxCoreSDK_UPL.xml"));
        }
        else if (UnrealTargetPlatform.TryParse("IOS", out parsedPlatform) && Target.Platform == parsedPlatform)
        {
            // Add the IOS specific Include and Library paths
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "IOS", "include"));
            string VivoxLibraryPath = Path.Combine(ModuleDirectory, "IOS", "Release");

            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "libvivoxsdk.a"));
            PublicFrameworks.Add( "CFNetwork" );
            PublicFrameworks.Add( "AVFoundation");
        }
        else if (UnrealTargetPlatform.TryParse("Switch", out parsedPlatform) && Target.Platform == parsedPlatform)
        {
            // Add the Switch specific Include and Library paths
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "NX", "include"));
            string VivoxLibraryPath = Path.Combine(ModuleDirectory, "NX", "Release");

            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "libvivoxsdk.a"));
#if UE_4_24_OR_LATER
            PublicSystemLibraries.Add("curl");
            PublicSystemLibraries.Add("z");
#else
            PublicAdditionalLibraries.Add("curl");
            PublicAdditionalLibraries.Add("z");
#endif
        }
        else if (UnrealTargetPlatform.TryParse("XSX", out parsedPlatform) && Target.Platform == parsedPlatform)
        {
            // Add the XSX specific Include and Library paths
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Scarlett", "include"));
            string VivoxLibraryPath = Path.Combine(ModuleDirectory, "Scarlett", "Release");

            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "vivoxsdk.lib"));
        }
        else if (UnrealTargetPlatform.TryParse("XboxOneGDK", out parsedPlatform) && Target.Platform == parsedPlatform)
        {
            // Add the XboxOneGDK specific Include and Library paths
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "XB1GDK", "include"));
            string VivoxLibraryPath = Path.Combine(ModuleDirectory, "XB1GDK", "Release");

            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "vivoxsdk.lib"));
        }
        else if (UnrealTargetPlatform.TryParse("PS5", out parsedPlatform) && Target.Platform == parsedPlatform)
        {
            // Add the PS5 specific Include and Library paths
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "PlayStation5", "include"));
            string VivoxLibraryPath = Path.Combine(ModuleDirectory, "PlayStation5", "Release");

            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "libvivoxsdk.a"));

#if UE_4_24_OR_LATER
            PublicSystemLibraries.Add("SceSha1");
            PublicSystemLibraries.Add("SceHmac");
#else
            PublicAdditionalLibraries.Add("SceSha1");
            PublicAdditionalLibraries.Add("SceHmac");
#endif
        }
        else if (UnrealTargetPlatform.TryParse("Stadia", out parsedPlatform) && Target.Platform == parsedPlatform)
        {
            // Add the Stadia specific Include and Library paths
            PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "GoogleStadia", "include"));
            string VivoxLibraryPath = Path.Combine(ModuleDirectory, "GoogleStadia", "Release");

            PublicAdditionalLibraries.Add(Path.Combine(VivoxLibraryPath, "libvivoxsdk.so"));
            RuntimeDependencies.Add(Path.Combine(VivoxLibraryPath, "libvivoxsdk.so"));
        }
    }
}
