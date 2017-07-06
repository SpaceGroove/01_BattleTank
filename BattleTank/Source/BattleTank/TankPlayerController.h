// Copyright Joshua Bernall, All rights reserved.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //must be the last include


class UTankAimingComponent;

/**
 * Responsible for helping the player aim
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
		
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

UFUNCTION()
		void OnTankDeath();

protected:


	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:
	
	virtual void SetPawn(APawn* InPawn) override;

	

	//start the tank moving the barrel so that the shot would hit where
	//the cross hair intersects the world
	void AimTowardsCrosshair();

	// return an OUT parameter, true if hit landscape
	bool bGetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.f;
};
