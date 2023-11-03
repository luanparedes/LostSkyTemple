// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class LOSTSKYTEMPLE_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector IslandPosition = FVector();

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector XYZspeed = FVector();

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MoveDistance = 100;

protected:
	virtual void BeginPlay() override;

private:
	FVector StartLocation;
	void GetInitialPositionValues();
};
