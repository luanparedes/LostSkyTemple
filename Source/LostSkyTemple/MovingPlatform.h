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
	FVector MyVector = FVector();

	UPROPERTY(EditAnywhere)
	int32 Yspeed = 0;

	UPROPERTY(EditAnywhere)
	int32 Xspeed = 0;

	UPROPERTY(EditAnywhere)
	int32 Zspeed = 0;
};
