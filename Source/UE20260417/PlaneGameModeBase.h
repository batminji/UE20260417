// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PlaneGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class UE20260417_API APlaneGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	APlaneGameModeBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Test")
	float TestValue;

	void TestReflection();
};
