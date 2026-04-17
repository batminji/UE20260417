// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "RotateStaticMeshComponent.generated.h"

UCLASS()
class UE20260417_API URotateStaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	URotateStaticMeshComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationSpeed = 720.0f;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
