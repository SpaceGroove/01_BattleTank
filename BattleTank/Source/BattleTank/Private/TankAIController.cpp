// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	
	auto PlayerTank = GetPlayerTank();
		if (!PlayerTank)
		{
			UE_LOG(LogTemp, Error, TEXT("TankAIController not detecting PlayerController"))
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("TankAIController detecting PlayerController on %s"), *GetPlayerTank()->GetName())	
		}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!GetPlayerTank()) { return; }
	AimAtPlayerTank();
}

ATank* ATankAIController::GetAIControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::AimAtPlayerTank()
{
	if (!GetAIControlledTank()) { return; }
	GetAIControlledTank()->AimAt(GetPlayerTank()->GetTargetLocation());
}


