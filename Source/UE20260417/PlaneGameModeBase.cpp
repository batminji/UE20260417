// Fill out your copyright notice in the Description page of Project Settings.


#include "PlaneGameModeBase.h"
#include "PlaneController.h"
#include "PlanePawn.h"

APlaneGameModeBase::APlaneGameModeBase()
{
	DefaultPawnClass = APlanePawn::StaticClass();
	PlayerControllerClass = APlaneController::StaticClass();

	for (TFieldIterator<FProperty> Iter(GetClass()); Iter; ++Iter)
	{
		auto Value = *Iter;
		UE_LOG(LogTemp, Warning, TEXT("Property Name: %s"), *Value->GetName());

		if(Value->GetName() == TEXT("TestValue"))
		{
			float* SampleTestValue = Value->ContainerPtrToValuePtr<float>(this);
			*SampleTestValue = -11111.0f;
		}
	}
}

void APlaneGameModeBase::TestReflection()
{
	UE_LOG(LogTemp, Warning, TEXT("TestValue: %f"), TestValue);
}
