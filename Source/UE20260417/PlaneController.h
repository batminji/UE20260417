// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlaneController.generated.h"

class UInputMappingContext;

UCLASS()
class UE20260417_API APlaneController : public APlayerController
{
	GENERATED_BODY()

public:
	APlaneController();

	virtual void OnPossess(APawn* InPawn) override;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> InputMappingContext;
	
};
