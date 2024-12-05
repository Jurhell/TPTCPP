// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

class UStaticMeshComponent;
class UCurveFloat;
class UBoxComponent;

UCLASS() // Always above Unreal class
class TPTCPP_API AMovingPlatform : public AActor
{
	GENERATED_BODY() // Always first in Unreal class or struct
		// UPROPERTY is similar to SerializeField, makes variable appear in blueprint
		// UFUNCTION is the same but for functions
		// USTRUCT is like UCLASS but for structs
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* Trigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MovingPlatform, meta = (AllowPrivateAccess = "true", MakeEditorWidget))
	FVector EndPosition = FVector(100.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MovingPlatform, meta = (AllowPrivateAccess = "true"))
	UCurveFloat* MovementCurve;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MovingPlatform, meta = (AllowPrivateAccess = "true"))
	bool bIsMovingForward = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MovingPlatform, meta = (AllowPrivateAccess = "true"))
	float Progress;

public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
	void OnTriggerOverlapBegin(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnTriggerOverlapEnd(class UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void Forward();
	void Reverse();
};
