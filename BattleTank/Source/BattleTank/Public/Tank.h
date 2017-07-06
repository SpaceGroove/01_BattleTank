// Copyright Joshua Bernall, All rights reserved.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

		

private:

	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
		int32 CurrentHealth;

	virtual void BeginPlay() override;

public:

	FTankDelegate OnDeath;

	// Returns Current Health as a percentage of starting health, between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	//called by the engine when actor damage is dealt
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
};