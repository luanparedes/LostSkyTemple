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

	float DistanceMoved = FVector::Dist(StartLocation, IslandPosition);

	// This if statement is what do the magic to move back in the same that it goes forward.
	if(DistanceMoved > MoveDistance)
	{
		StartLocation = StartLocation + XYZspeed.GetSafeNormal() * MoveDistance;
		SetActorLocation(StartLocation);
		XYZspeed = -XYZspeed;
	}
		
}

void AAIslands::GetInitialPositionValues(){
	StartLocation = GetActorLocation();
	IslandPosition = GetActorLocation();

	FString log_text = "\nIsland name: " + this->GetName() + 
					   "\nX position: " + FString::SanitizeFloat(GetActorLocation().X) +
					   "\nY position: " + FString::SanitizeFloat(GetActorLocation().Y) +
					   "\nZ position: " + FString::SanitizeFloat(GetActorLocation().Z);

	UE_LOG(LogTemp, Display, TEXT("\n%s"), *log_text);
}