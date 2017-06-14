// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"))
		
		if (!GetControlledTank())
		{
			UE_LOG(LogTemp, Error, TEXT("PlayerController not possesing a tank"))
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("PlayerController possesing %s"), *GetControlledTank()->GetName())
		}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

