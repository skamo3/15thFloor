// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"
#include "Blueprint/UserWidget.h"
#include "JordiMainMenuWidget.h"

AMainMenuGameMode::AMainMenuGameMode()
{
}

void AMainMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Test the GameMode Begin Play"));

	if (MenuClass)
	{
		Menu = CreateWidget<UJordiMainMenuWidget>(GetWorld(), MenuClass);
		if (Menu)
		{
			UE_LOG(LogTemp, Warning, TEXT("Menu is here"));

			Menu->SetUp();
		}
	}
	

	
}
