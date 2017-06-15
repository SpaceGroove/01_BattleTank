// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	//start the tank moving the barrel so that the shot would hit where
	//the crosshair intersects the world
	void AimTowardsCrosshair();

	// return an OUT parameter, true if hit landscape
	bool bGetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;

	
	

};
