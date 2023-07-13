// Fill out your copyright notice in the Description page of Project Settings.


#include "JordiGameInstance.h"

#include "Engine/Engine.h"


UJordiGameInstance::UJordiGameInstance(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{

}

void UJordiGameInstance::Init()
{
	Super::Init();

}

void UJordiGameInstance::Host()
{
	UEngine* Engine = GetEngine();
	check(Engine);

	Engine->AddOnScreenDebugMessage(-1, 1.5, FColor::Blue, TEXT("Host exec command called"));

	UWorld* World = GetWorld();
	check(World);


}


void UJordiGameInstance::Join(const FString &Address)
{
	UEngine* Engine = GetEngine();
	check(Engine);

	Engine->AddOnScreenDebugMessage(-1, 3, FColor::Blue, FString::Printf(TEXT("Joining %s"), *Address));
}