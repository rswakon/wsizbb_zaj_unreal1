// Fill out your copyright notice in the Description page of Project Settings.

#include "PackSpawner.h"
#include "wsizbb_zaj_unreal1.h"
#include "wsizbb_zaj_unreal1Character.h"
#include "Components/BoxComponent.h"
#include "Classes/Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "wsizbb_zaj_unreal1GameMode.h"
#include "MagicPack.h"
// Sets default values
APackSpawner::APackSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawningVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnVolumeBox"));
	RootComponent = SpawningVolume;
	// This establishes the item to spawn is a magic pill
	ItemToSpawn = AMagicPack::StaticClass();
}

// Called when the game starts or when spawned
void APackSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnPack();
}

// Called every frame
void APackSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APackSpawner::SpawnPack()
{
	if (ItemToSpawn != NULL)
	{
		UWorld * const World = GetWorld();
		if (World)
		{
			FVector Origin = SpawningVolume->Bounds.Origin;
			FVector Extent = SpawningVolume->Bounds.BoxExtent;
			FVector spawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extent);
			FRotator SpawnRotation;
			SpawnRotation.Pitch = FMath::FRand() * 360.0f;
			SpawnRotation.Roll = FMath::FRand() * 360.0f;
			SpawnRotation.Yaw = FMath::FRand() * 360.0f;
			AMagicPack * SpawnedPack = World->SpawnActor<AMagicPack>(ItemToSpawn, spawnLocation, SpawnRotation);
		}
	}
}