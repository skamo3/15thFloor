// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "JordiMainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class FIFTIETHFLOOR_API UJordiMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

private:

	UPROPERTY(meta = (BindWidget))
	class UButton* OpenServerButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* JoinServerButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* OptionButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* ExitButton;



protected:
	virtual void NativeConstruct() override;
	//virtual void Initialize() override;

	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnClickedOpenServerButton();

	UFUNCTION()
	void OnClickedJoinServerButton();

	UFUNCTION()
	void OnClickedOptionButton();

	UFUNCTION()
	void OnClickedExitButton();


public:

	void SetUp();

	void TearDown();
	
};
