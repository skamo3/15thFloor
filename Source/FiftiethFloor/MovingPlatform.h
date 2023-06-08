// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class FIFTIETHFLOOR_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, Category = "MoveVariable")
	float MoveSpeedX;

	UPROPERTY(EditAnywhere, Category = "MoveVariable")
		float MoveSpeedY;

	UPROPERTY(EditAnywhere, Category = "MoveVariable")
		float MoveSpeedZ;

public:
	AMovingPlatform();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

};
