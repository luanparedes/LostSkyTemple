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

	UPROPERTY(EditAnywhere)
	FVector XYZspeed = FVector();

	UPROPERTY(EditAnywhere)
	float maxMoveZ = 0;

	UPROPERTY(EditAnywhere)
	float minMoveZ = 0;

	UPROPERTY(EditAnywhere)
	float maxMoveX = 0;

	UPROPERTY(EditAnywhere)
	float minMoveX = 0;

	UPROPERTY(EditAnywhere)
	float maxMoveY = 0;

	UPROPERTY(EditAnywhere)
	float minMoveY = 0;

protected:
	virtual void BeginPlay() override;

private:
	bool isReverseX;
	bool isReverseY;
	bool isReverseZ;

	void getInitialPositionValues();
};
