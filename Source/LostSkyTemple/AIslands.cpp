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

	getInitialPositionValues();
}

// Called every frame
void AAIslands::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(IslandPosition.X >= maxMoveX)
		isReverseX = true;
	else if(IslandPosition.X <= minMoveX)
		isReverseX = false;

	if(IslandPosition.Y >= maxMoveY)
		isReverseY = true;
	else if(IslandPosition.Y <= minMoveY)
		isReverseY = false;

	if(IslandPosition.Z >= maxMoveZ)
		isReverseZ = true;
	else if(IslandPosition.Z <= minMoveZ)
		isReverseZ = false; 

	
	if(!isReverseX)
		IslandPosition.X += XYZspeed.X;
	else
		IslandPosition.X -= XYZspeed.X;

	if(!isReverseY)
		IslandPosition.Y += XYZspeed.Y;
	else
		IslandPosition.Y -= XYZspeed.Y;

	if(!isReverseZ)
		IslandPosition.Z += XYZspeed.Z;
	else
		IslandPosition.Z -= XYZspeed.Z;

	SetActorLocation(IslandPosition);

	// Island moves forward
		// Get island location
		// Move using a limit
	
	// Island moves backward
		// Get Island location
		// Move using a limit
}

void AAIslands::getInitialPositionValues(){
	maxMoveX += IslandPosition.X;
	minMoveX = IslandPosition.X - minMoveX;

	maxMoveY += IslandPosition.Y;
	minMoveY = IslandPosition.Y - minMoveY;

	maxMoveZ += IslandPosition.Z;
	minMoveZ = IslandPosition.Z - minMoveZ;
}