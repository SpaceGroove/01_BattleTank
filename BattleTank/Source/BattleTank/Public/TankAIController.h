// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;	

	virtual void Tick(float DeltaTime) override;

UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 7500;

private:
	//how close can the ai tank get to the player
	

};
