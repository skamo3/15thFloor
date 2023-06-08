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
	
	FVector GlobalTargetLocation;
	FVector GlobalStartLocation;


public:

	UPROPERTY(EditAnywhere, Category = "MoveVariable")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = true))
	FVector TargetLocation;

	AMovingPlatform();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

};
