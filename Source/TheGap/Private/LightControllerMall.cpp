// Fill out your copyright notice in the Description page of Project Settings.


#include "LightControllerMall.h"

// Sets default values
ALightControllerMall::ALightControllerMall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALightControllerMall::BeginPlay()
{
	Super::BeginPlay();
	
	MainCharacter->Flashlight->Intensity = (MainCharacter->Flashlight->Intensity) / 2;
	MainCharacter->Flashlight->AttenuationRadius = (MainCharacter->Flashlight->AttenuationRadius / 2);
	
}

// Called every frame
void ALightControllerMall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}