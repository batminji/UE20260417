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

	if(IsLocalPlayerController())
	{
		if(ULocalPlayer* LocalPlayer = GetLocalPlayer())
		{
			if (UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
			{
				if (InputMappingContext)
				{
					InputSystem->AddMappingContext(InputMappingContext, 0);
				}
			}
		}
	}
}
