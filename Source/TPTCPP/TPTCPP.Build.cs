// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TPTCPP : ModuleRules
{
	public TPTCPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
