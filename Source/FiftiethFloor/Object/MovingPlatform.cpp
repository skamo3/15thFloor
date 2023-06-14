// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	SetMobility(EComponentMobility::Movable);

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();


	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}
	
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);

}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


	if (HasAuthority())
	{
		FVector currentLocation = GetActorLocation();
		float MoveLengthSize = (GlobalTargetLocation - GlobalStartLocation).Size();
		float LeftLengthSize = (currentLocation - GlobalStartLocation).Size();

		if (LeftLengthSize >= MoveLengthSize)
		{
			FVector temp = GlobalStartLocation;
			GlobalStartLocation = GlobalTargetLocation;
			GlobalTargetLocation = temp;
		}

		FVector direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		currentLocation += MoveSpeed * DeltaSeconds * direction;
		SetActorLocation(currentLocation);
	}
	
}
