// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class FIFTIETHFLOOR_API AMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
private:

	UPROPERTY(EditDefaultsOnly, Category = "Menu")
	TSubclassOf<class UUserWidget> MenuClass;

	class UJordiMainMenuWidget* Menu;


public:

	AMainMenuGameMode();

	virtual void BeginPlay() override;

};
