// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MagicPack.generated.h"

UCLASS()
class WSIZBB_ZAJ_UNREAL1_API AMagicPack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMagicPack();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Components")
		UStaticMeshComponent* PackMesh;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
