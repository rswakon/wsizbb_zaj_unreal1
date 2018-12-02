// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PackSpawner.generated.h"

UCLASS()
class WSIZBB_ZAJ_UNREAL1_API APackSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APackSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, Category = "Spawning")
		TSubclassOf<class AMagicPack> ItemToSpawn;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// This function spawn pill
	void SpawnPack();
private:
	// This is the Spawning Volume as a Box Component
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* SpawningVolume;
};
