// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class wsizbb_zaj_unreal1EditorTarget : TargetRules
{
	public wsizbb_zaj_unreal1EditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("wsizbb_zaj_unreal1");
	}
}
