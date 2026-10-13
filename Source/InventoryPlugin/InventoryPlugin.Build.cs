// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class InventoryPlugin : ModuleRules
{
	public InventoryPlugin(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"InventoryPlugin",
			"InventoryPlugin/Variant_Platforming",
			"InventoryPlugin/Variant_Platforming/Animation",
			"InventoryPlugin/Variant_Combat",
			"InventoryPlugin/Variant_Combat/AI",
			"InventoryPlugin/Variant_Combat/Animation",
			"InventoryPlugin/Variant_Combat/Gameplay",
			"InventoryPlugin/Variant_Combat/Interfaces",
			"InventoryPlugin/Variant_Combat/UI",
			"InventoryPlugin/Variant_SideScrolling",
			"InventoryPlugin/Variant_SideScrolling/AI",
			"InventoryPlugin/Variant_SideScrolling/Gameplay",
			"InventoryPlugin/Variant_SideScrolling/Interfaces",
			"InventoryPlugin/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
