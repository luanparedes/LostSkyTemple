#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	GetInitialPositionValues();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::GetInitialPositionValues()
{
	StartLocation = GetActorLocation();
	IslandPosition = GetActorLocation();
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	IslandPosition = GetActorLocation();
	IslandPosition += XYZspeed * DeltaTime;

	SetActorLocation(IslandPosition);

	float DistanceMoved = FVector::Dist(StartLocation, IslandPosition);

	if(DistanceMoved > MoveDistance)
	{
		StartLocation = StartLocation + XYZspeed.GetSafeNormal() * MoveDistance;
		SetActorLocation(StartLocation);
		XYZspeed = -XYZspeed;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FString island = GetName();
	UE_LOG(LogTemp, Display, TEXT("Called method RotatePlatform from %s island."), *island);
}