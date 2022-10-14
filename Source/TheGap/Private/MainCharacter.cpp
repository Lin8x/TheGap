// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"

//#include "Components/CapsuleComponent.h"
//#include "../../../../../UnrealEngine/UE_5.0/Engine/Shaders/Private/PathTracing/Material/PathTracingMaterialCommon.ush"
#include "GameFramework/CharacterMovementComponent.h"
//#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;

	// // Get the capsule component
	// CapsuleComponent = this->GetCapsuleComponent();

	//Set the camera component to look through
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FP Camera"));
	FirstPersonCamera->SetupAttachment(GetRootComponent());
	FirstPersonCamera->SetRelativeLocation(FVector(0,0,40));
	//FirstPersonCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

	//Setup springarm for flashlight
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(FirstPersonCamera);
	SpringArm->SetRelativeLocation(FVector(0,0,0));
	SpringArm->bEnableCameraRotationLag = true;
	SpringArm->CameraRotationLagSpeed = 5;
	SpringArm->TargetArmLength = 0;
	//SpringArm->TargetArmLength = 600;

	//Setup Spotlight as flashlight
	Flashlight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Flashlight"));
	Flashlight->SetupAttachment(SpringArm);
	Flashlight->SetRelativeLocation(FVector(0,0,0));
	Flashlight->Intensity = 20000;
	Flashlight->InnerConeAngle = 5;
	Flashlight->OuterConeAngle = 25;
	//FlashlightMaterial = LoadObject<UMaterial>(nullptr, TEXT("/Content/Materials/flashlightbackground_Mat.uasset"), nullptr, LOAD_None, nullptr);
	//auto path = TEXT("/Content/Materials/flashlightbackground_Mat.uasset"); //path to the asset we created in edtior. (Right click -> Miscellaneous -> Data Asset)
	//static ConstructorHelpers::FObjectFinder<UMaterial> DefaultMasterAsset(path);
	//FlashlightMaterial = DefaultMasterAsset.Object;
	Flashlight->LightFunctionMaterial = FlashlightMaterial;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("TESTING CHARACTER WORKS!"));
	//UE_LOG("Hello");

	//The player's default speed. This is multiplied to when sprinting or crouching.
	DefaultSpeed = 300;
	this->GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed;
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
// "An InputComponent is a component that defines how to handle input data.
// An InputComponent can be attached to an actor that wants to receive input."
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("I_Sprint",IE_Pressed, this, &AMainCharacter::TurnSprintOn);
	PlayerInputComponent->BindAction("I_Sprint",IE_Released, this, &AMainCharacter::TurnSprintOff);
	
	//PlayerInput->BindAxis("NameOfInput", Object Being Moved, FunctionNameInCodeToRun);\
	//FunctionNameInCodeToRun must be specified in header
	PlayerInputComponent->BindAxis("I_MoveLeftRight", this, &AMainCharacter::MoveLeftRight);
	PlayerInputComponent->BindAxis("I_MoveUpDown", this, &AMainCharacter::MoveUpDown);
	PlayerInputComponent->BindAxis("I_LookLeftRight", this, &AMainCharacter::LookLeftRight);
	PlayerInputComponent->BindAxis("I_LookUpDown", this, &AMainCharacter::LookUpDown);
}

void AMainCharacter::MoveUpDown(float Value)
{
	//Direction must use the UKismetMathLibrary in order to get the
	//Forward Vector of a rotator made via the Controller's Yaw
	//FVector const Direction = UKismetMathLibrary::GetForwardVector(FRotator(0, Controller->GetControlRotation().Yaw, 0));
	//FVector const Direction = CorrectRotation.GetFo;

	//Getting the Forward Direction of the Controller's Yaw (IE Forward/Back) based on the Controller's Rotation
	//Then adding movement input based on that direction of forward
	//"Value" is the scale based on the input axis
	//"const" means that the value is not allowed to change in the function body
	//AddMovementInput(Direction, Value);
	AddMovementInput(GetActorForwardVector(), Value);
}

void AMainCharacter::MoveLeftRight(float Value)
{
	//Direction must use the UKismetMathLibrary in order to get the
	//Forward Vector of a rotator made via the Controller's Yaw
	//FVector const Direction = UKismetMathLibrary::GetRightVector(FRotator(0, Controller->GetControlRotation().Yaw, 0));
	//FVector const Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);

	//Getting the Right Direction of the Controller's Yaw (IE Left/Right) based on the Controller's Rotation
	//Then adding movement input based on that direction of forward
	//"Value" is the scale based on the input axis
	//"const" means that the value is not allowed to change in the function body
	//AddMovementInput(Direction,  Value/1.5);
	AddMovementInput(GetActorRightVector(), Value);
}

void AMainCharacter::TurnSprintOn()
{
	this->GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed * 1.5;
}

void AMainCharacter::TurnSprintOff()
{
	this->GetCharacterMovement()->MaxWalkSpeed = DefaultSpeed;
}

void AMainCharacter::LookLeftRight(float Value)
{
	AddActorLocalRotation(FRotator(0, Value, 0));
}

void AMainCharacter::LookUpDown(float Value)
{
	//AddActorLocalRotation(FRotator(Value, 0, 0));
	float temp = FirstPersonCamera->GetRelativeRotation().Pitch + Value;

	if(temp < 90 && temp > -90)
	{
		FirstPersonCamera->AddLocalRotation(FRotator(Value, 0, 0));
	}
}



// FVector UKismetMathLibrary::GetForwardVector(FRotator InRot)
// {
// 	return FRotationMatrix(InRot).GetScaledAxis( EAxis::X );
// }

// void AMainCharacter::LookUpDown(float Value)
// {
// 	
// }
//
// void AMainCharacter::LookLeftRight(float Value)
// {
// 	
// }



