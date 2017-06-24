// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto AITank = Cast<ATank>(GetPawn());
	if (!AITank) { return; }

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{
		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check that radius is in fact in CM
		
		// Aim towards player
		AITank->AimAt(PlayerTank->GetActorLocation());

		// Fire at player
		AITank->Fire(); // TODO limit fire rate
	}
}
