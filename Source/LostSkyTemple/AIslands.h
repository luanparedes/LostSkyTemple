// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIslands.generated.h"

UCLASS()
class LOSTSKYTEMPLE_API AAIslands : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAIslands();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector IslandPosition = FVector();

	UPROPERTY(EditAnywhere)
	FVector XYZspeed = FVector();

	UPROPERTY(EditAnywhere)
	float maxMoveZ = 0;

	UPROPERTY(EditAnywhere)
	float minMoveZ = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	bool isReverse = false;
};
