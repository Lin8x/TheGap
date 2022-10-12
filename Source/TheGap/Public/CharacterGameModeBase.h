// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CharacterGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class THEGAP_API ACharacterGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	//This function declaration allows you to override StartPlay so that you can
	//print a log message to the screen when gameplay begins.
	virtual void StartPlay() override;
	
};
