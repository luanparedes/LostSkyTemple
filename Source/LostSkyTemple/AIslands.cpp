#include "AIslands.h"

AAIslands::AAIslands()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AAIslands::BeginPlay()
{
	Super::BeginPlay();

	GetInitialPositionValues();
}

void AAIslands::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveIsland(DeltaTime);
	RotateIsland(DeltaTime);	
}

void AAIslands::GetInitialPositionValues(){
	StartLocation = GetActorLocation();
	IslandPosition = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("\n%s"), *FullLogMessage());
}

void AAIslands::MoveIsland(float DeltaTime)
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

void AAIslands::RotateIsland(float DeltaTime)
{
	FString islandString = GetName();
	UE_LOG(LogTemp, Display, TEXT("Island %s rotation"), *islandString);

	IslandRotation = GetActorRotation();

	IslandRotation += XYZRotationSpeed * DeltaTime;

	SetActorRotation(IslandRotation);
}

//A const method, it doesn't allow to modify some class property inside this method
FString AAIslands::FullLogMessage() const
{
	FString log_text = "\nIsland name: " + this->GetName() + 
					"\nX position: " + FString::SanitizeFloat(GetActorLocation().X) +
					"\nY position: " + FString::SanitizeFloat(GetActorLocation().Y) +
					"\nZ position: " + FString::SanitizeFloat(GetActorLocation().Z);

	return log_text;
}