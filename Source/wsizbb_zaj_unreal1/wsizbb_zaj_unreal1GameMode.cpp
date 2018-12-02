// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "wsizbb_zaj_unreal1GameMode.h"
#include "wsizbb_zaj_unreal1Character.h"
#include "UObject/ConstructorHelpers.h"

Awsizbb_zaj_unreal1GameMode::Awsizbb_zaj_unreal1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
