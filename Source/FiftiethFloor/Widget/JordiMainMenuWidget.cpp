// Fill out your copyright notice in the Description page of Project Settings.


#include "JordiMainMenuWidget.h"
#include "Components/Button.h"

void UJordiMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	OpenServerButton->OnClicked.AddDynamic(this, &UJordiMainMenuWidget::OnClickedOpenServerButton);

	JoinServerButton->OnClicked.AddDynamic(this, &UJordiMainMenuWidget::OnClickedJoinServerButton);

	OptionButton->OnClicked.AddDynamic(this, &UJordiMainMenuWidget::OnClickedOptionButton);

	ExitButton->OnClicked.AddDynamic(this, &UJordiMainMenuWidget::OnClickedExitButton);
}

void UJordiMainMenuWidget::NativeDestruct()
{
	this->TearDown();
}

void UJordiMainMenuWidget::OnClickedOpenServerButton()
{
	UE_LOG(LogTemp, Warning, TEXT("Click Open Server"));

}

void UJordiMainMenuWidget::OnClickedJoinServerButton()
{
	UE_LOG(LogTemp, Warning, TEXT("Click Join Server"));

}

void UJordiMainMenuWidget::OnClickedOptionButton()
{
	UE_LOG(LogTemp, Warning, TEXT("Click Option Button"));

}

void UJordiMainMenuWidget::OnClickedExitButton()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		PlayerController->ConsoleCommand("quit");
	}
}

void UJordiMainMenuWidget::SetUp()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	check(World);
	UE_LOG(LogTemp, Warning, TEXT("World is fine"));

	APlayerController* PlayerController = World->GetFirstPlayerController();

	if (PlayerController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Get PlayerController Success"));
		FInputModeUIOnly InputModeData;
		this->bIsFocusable = true;
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		PlayerController->SetInputMode(InputModeData);

		PlayerController->bShowMouseCursor = true;
	}
	
}

void UJordiMainMenuWidget::TearDown()
{

	this->RemoveFromViewport();

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	check(PlayerController);

	FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}


