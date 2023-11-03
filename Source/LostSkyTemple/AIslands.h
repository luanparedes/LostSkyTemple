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

protected:
	virtual void BeginPlay() override;

private:
	void GetInitialPositionValues();
};
