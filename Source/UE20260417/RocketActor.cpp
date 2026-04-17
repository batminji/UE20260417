// Fill out your copyright notice in the Description page of Project Settings.


#include "RocketActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ARocketActor::ARocketActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComponent"));
	RootComponent = BoxComponent;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->MaxSpeed = 2000.0f;
	ProjectileMovementComponent->InitialSpeed = 2000.0f;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;

}

void ARocketActor::ProcessActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && OtherActor != this)
	{
		Destroy();
	}
}

// Called when the game starts or when spawned
void ARocketActor::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(5.0f);

	OnActorBeginOverlap.AddDynamic(this, &ARocketActor::ProcessActorBeginOverlap);
}

// Called every frame
void ARocketActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

