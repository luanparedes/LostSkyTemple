#include "AIslands.h"

// Sets default values
AAIslands::AAIslands()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIslands::BeginPlay()
{
	Super::BeginPlay();

	maxMoveZ += IslandPosition.Z;
	minMoveZ = -minMoveZ - IslandPosition.Z;
}

// Called every frame
void AAIslands::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(IslandPosition.Z >= maxMoveZ)
		isReverse = true;
	else if(IslandPosition.Z <= minMoveZ)
		isReverse = false;

	IslandPosition.X += XYZspeed.X;
	IslandPosition.Y += XYZspeed.Y;

	if(!isReverse)
		IslandPosition.Z += XYZspeed.Z;
	else
		IslandPosition.Z -= XYZspeed.Z;


	SetActorLocation(IslandPosition);
}

