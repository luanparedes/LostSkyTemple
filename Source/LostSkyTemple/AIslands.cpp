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

	GetInitialPositionValues();
}

// Called every frame
void AAIslands::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	IslandPosition = GetActorLocation();
	IslandPosition.X += XYZspeed.X;
	IslandPosition.Y += XYZspeed.Y;
	IslandPosition.Z += XYZspeed.Z;

	SetActorLocation(IslandPosition);
}

void AAIslands::GetInitialPositionValues(){
	IslandPosition = GetActorLocation();
}