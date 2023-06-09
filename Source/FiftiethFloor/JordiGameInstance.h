// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "JordiGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FIFTIETHFLOOR_API UJordiGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UJordiGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init() override;

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString &Address);
};
