// Fill out your copyright notice in the Description page of Project Settings.

#include "MagicPack.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
AMagicPack::AMagicPack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PackMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");

	auto MeshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));

	if (MeshAsset.Object != nullptr) {
		PackMesh->SetStaticMesh(MeshAsset.Object);
	}
}

// Called when the game starts or when spawned
void AMagicPack::BeginPlay()
{
	Super::BeginPlay();
	PackMesh->SetSimulatePhysics(true);
}

// Called every frame
void AMagicPack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

