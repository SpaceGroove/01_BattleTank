// Copyright Joshua Bernall, All rights reserved.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankAimingComponent;
class UTankTurret;
class AProjectile;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:

	UPROPERTY(BlueprintReadOnly)
	UTankAimingComponent* TankAimingComponent = nullptr;

	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;

public:	

/*
 
 	// Called to bind functionality to input
 	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
*/

	void AimAt(FVector HitLocation);


	UFUNCTION(BlueprintCallable, Category = "Firing")
		void Fire();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;
	
// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; // TODO Remove

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;

	double LastFireTime = 0;
};