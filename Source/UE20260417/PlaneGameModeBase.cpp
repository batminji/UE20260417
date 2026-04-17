// Fill out your copyright notice in the Description page of Project Settings.


#include "PlaneGameModeBase.h"
#include "PlaneController.h"
#include "PlanePawn.h"

APlaneGameModeBase::APlaneGameModeBase()
{
	DefaultPawnClass = APlanePawn::StaticClass();
	PlayerControllerClass = APlaneController::StaticClass();
}