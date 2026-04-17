// Fill out your copyright notice in the Description page of Project Settings.


#include "PlaneController.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"

APlaneController::APlaneController()
{
}

void APlaneController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (!IsLocalPlayerController())
	{
		return;
	}

	ULocalPlayer* LocalPlayer = GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (InputSystem)
	{
		for (const auto& Context : InputMappingContext)
		{
			InputSystem->AddMappingContext(Context, 0);
		}
	}
}
