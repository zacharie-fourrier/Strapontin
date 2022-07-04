// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class MaterWelonV2 : ModuleRules
{
	public MaterWelonV2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		if (Target.Type != TargetRules.TargetType.Server && Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicDefinitions.Add("WITH_VIVOXCORE=1");
			PrivateDependencyModuleNames.AddRange(new string[] { "VivoxCore" });
		}
		else
		{
			PublicDefinitions.Add("WITH_VIVOXCORE=0");
		}

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
