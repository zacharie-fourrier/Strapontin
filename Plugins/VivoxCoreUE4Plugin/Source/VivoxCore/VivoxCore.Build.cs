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

using UnrealBuildTool;

public class VivoxCore : ModuleRules
{
	public VivoxCore(ReadOnlyTargetRules Target) : base(Target)
	{

		PublicIncludePaths.AddRange(
			new string[] {
				string.Format("{0}/Public", ModuleDirectory),
			}
			);


		PrivateIncludePaths.AddRange(
			new string[] {
                string.Format("{0}/Private", ModuleDirectory),
			}
			);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "CoreUObject",
                "VivoxCoreLibrary",
				"Projects",
                "Engine",
			}
			);


		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				// ... add private dependencies that you statically link with here ...
			}
			);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
            }
			);

        if (Target.Platform == UnrealTargetPlatform.Win64)
        {
            string vivoxSdkDll = string.Format("{0}\\..\\ThirdParty\\VivoxCoreLibrary\\Windows\\Release\\x64\\vivoxsdk.dll", ModuleDirectory);
            if (!System.IO.File.Exists(vivoxSdkDll))
            {
                System.Diagnostics.Debug.WriteLine(string.Format("Warning: {0} does not exist", vivoxSdkDll));
            }
            RuntimeDependencies.Add(vivoxSdkDll);
        }

        // Build
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
    }
}
