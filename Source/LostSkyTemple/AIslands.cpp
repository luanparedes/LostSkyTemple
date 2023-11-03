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
	
	// Getting actor location
	IslandPosition = GetActorLocation();

	// Setting actor movement velocity using DeltaTime that made equally works for every cpu.
	IslandPosition += XYZspeed * DeltaTime;

	// And setting the actor new location.
	SetActorLocation(IslandPosition);

	DistanceMoved = FVector::Dist(StartLocation, IslandPosition);
}

void AAIslands::GetInitialPositionValues(){
	StartLocation = GetActorLocation();
	IslandPosition = GetActorLocation();
}