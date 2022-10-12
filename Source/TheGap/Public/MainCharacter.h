// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "MainCharacter.generated.h"

UCLASS(BlueprintType)
class THEGAP_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	//"The UPROPERTY macro makes our variables visible to Unreal Engine.
	//This way, values set in these variables will not be reset when we
	//launch the game or reload our level or project in a future work session.
	//We have also added the EditAnywhere keyword, which will allow us to set
	//CameraOne and CameraTwo in the Unreal Editor."
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, AdvancedDisplay)
	float Speed;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,AdvancedDisplay)
	float DefaultSpeed;

	//UPROPERTY(EditAnywhere)
	//UCapsuleComponent* CapsuleComponent;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Camera Spring")
	// USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Player Camera")
	UCameraComponent* FirstPersonCamera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//Must setup any function that is part of the Header file into the CPP file
	//UFUNCTION("SpecialTraits")
	//variable NameOfFunction();

	//UFUNCTION(Keywords)
	//These keywords make the Blueprint system aware of the function so that it shows
	//in the context menu or Palette and can be added to a graph and executed - or, in
	//the case of events, so that they can be overridden and executed.

	//Moves the Character Left & Right
	//Value is the scale
	UFUNCTION(BlueprintCallable, Category="Custom Movement")
	void MoveLeftRight(UPARAM(DisplayName="Value (Axis Scale)") float Value);

	//Moves the Character Foward & Back
	//Value is the scale
	UFUNCTION(BlueprintCallable, Category="Custom Movement")
	void MoveUpDown(UPARAM(DisplayName="Value (Axis Scale)") float Value);

	//Changes rotation of the Camera Left & Right
	//Value is the scale
	UFUNCTION(BlueprintCallable, Category="Custom Movement")
	void LookLeftRight(UPARAM(DisplayName="Value (Axis Scale)") float Value);

	//Changes rotation of the Camera Foward & Back
	//Value is the scale
	UFUNCTION(BlueprintCallable, Category="Custom Movement")
	void LookUpDown(UPARAM(DisplayName="Value (Axis Scale)") float Value);

	// //Changes where the character is facing Up & Down
	// //Value is the scale
	// UFUNCTION(BlueprintCallable, Category="Custom Movement")
	// void LookLeftRight(UPARAM(DisplayName="Value (MouseX Axis Scale)") float Value);
	//
	// //Changes where the character is facing Up & Down
	// //Value is the scale
	// UFUNCTION(BlueprintCallable, Category="Custom Movement")
	// void LookUpDown(UPARAM(DisplayName="Value (MouseY Axis Scale)") float Value);

	//Allows the user to sprint
	UFUNCTION(BlueprintCallable, Category="Custom Movement")
	void TurnSprintOn();

	UFUNCTION(BlueprintCallable, Category="Custom Movement")
	void TurnSprintOff();
};
