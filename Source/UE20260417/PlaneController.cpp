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
			if (Context.IsValid())
			{
				InputSystem->AddMappingContext(Context.LoadSynchronous(), 0);
				// InputSystem->AddMappingContext(Context.LoadAsync(), 0);
				// LoadAsync의 경우 로드가 완료된 후에 AddMappingContext가 호출되도록 델리게이트를 설정해야 합니다.
			}
		}
	}
}
