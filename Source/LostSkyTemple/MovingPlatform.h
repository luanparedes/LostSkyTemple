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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	int32 NewValue = 120;

	UPROPERTY(EditAnywhere)
	bool isRunning = false;

	UPROPERTY(EditAnywhere)
	float PlayerTall = 1.84;

	UPROPERTY(EditAnywhere)
	float InputFloatA = 0;

	UPROPERTY(EditAnywhere)
	float InputFloatB = 0;

	UPROPERTY(EditAnywhere)
	float APlusBFloat = 0;
};
