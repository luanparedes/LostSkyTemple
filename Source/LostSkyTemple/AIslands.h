#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIslands.generated.h"

UCLASS()
class LOSTSKYTEMPLE_API AAIslands : public AActor
{
	GENERATED_BODY()
	
public:	
	AAIslands();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector IslandPosition = FVector();

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector XYZspeed = FVector();

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MoveDistance = 100;

	UPROPERTY(EditAnywhere, Category="Rotation Platform")
	FRotator IslandRotation = FRotator();

	UPROPERTY(EditAnywhere, Category="Rotation Platform")
	FRotator XYZRotationSpeed = FRotator();

protected:
	virtual void BeginPlay() override;

private:
	FVector StartLocation;
	void GetInitialPositionValues();
	void MoveIsland(float DeltaTime);
	void RotateIsland(float DeltaTime);
};
