// Fill out your copyright notice in the Description page of Project Settings.


#include "SpecialLight.h"

// Sets default values
ASpecialLight::ASpecialLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//LightTopCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube Mesh"));
	//LightLitCube = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube Mesh"));

}

// Called when the game starts or when spawned
void ASpecialLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpecialLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

