// Fill out your copyright notice in the Description page of Project Settings.


#include "PlanePawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/ArrowComponent.h"
#include "RotateStaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlanePawn::APlanePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ArrowComponent->SetupAttachment(RootComponent);

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
	FloatingPawnMovement->MaxSpeed = MaxSpeed;

	Left = CreateDefaultSubobject<URotateStaticMeshComponent>(TEXT("Left"));
	Left->SetupAttachment(StaticMeshComponent);

	Right = CreateDefaultSubobject<URotateStaticMeshComponent>(TEXT("Right"));
	Right->SetupAttachment(StaticMeshComponent);
}

void APlanePawn::Rotate(const FInputActionValue& Value)
{
	AddActorLocalRotation(FRotator(
		Value.Get<FVector2D>().Y * RotateSpeed * UGameplayStatics::GetWorldDeltaSeconds(GetWorld()),
		0.0f,
		Value.Get<FVector2D>().X * RotateSpeed * UGameplayStatics::GetWorldDeltaSeconds(GetWorld())
	));
}

void APlanePawn::Fire()
{
	if (RocketClass)
	{
		GetWorld()->SpawnActor<AActor>(RocketClass, ArrowComponent->K2_GetComponentToWorld());
	}
}

void APlanePawn::Boost()
{
	BoostSpeed = 1.0f;
}

void APlanePawn::UnBoost()
{
	BoostSpeed = 0.5f;
}

// Called when the game starts or when spawned
void APlanePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlanePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddMovementInput(GetActorForwardVector(), BoostSpeed);
}

// Called to bind functionality to input
void APlanePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EIC && IA_Rotate && IA_Fire && IA_Boost)
	{
		EIC->BindAction(IA_Rotate, ETriggerEvent::Triggered, this, &APlanePawn::Rotate);
		EIC->BindAction(IA_Fire, ETriggerEvent::Started, this, &APlanePawn::Fire);
		EIC->BindAction(IA_Boost, ETriggerEvent::Started, this, &APlanePawn::Boost);
		EIC->BindAction(IA_Boost, ETriggerEvent::Completed, this, &APlanePawn::UnBoost);
	}
}

