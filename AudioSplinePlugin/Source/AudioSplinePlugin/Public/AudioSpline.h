// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AudioSpline.generated.h"


class UAudioComponent;
class USplineComponent;
class USceneComponent;
class USphereComponent;


UCLASS()
class AUDIOSPLINEPLUGIN_API AAudioSpline : public AActor
{
	GENERATED_BODY()

public:
	AAudioSpline();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Settings")
		virtual float GetFrequency() const;

	UFUNCTION(BlueprintCallable, Category = "Settings")
		virtual void SetFrequency(const float NewFrequency);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Settings")
		virtual bool GetActive() const;

	UFUNCTION(BlueprintCallable, Category = "Settings")
		virtual void SetActive(const bool IsActive);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Settings")
		virtual bool GetUseTick() const;

	UFUNCTION(BlueprintCallable, Category = "Settings")
		virtual void SetUseTick(const bool UseTick);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Settings")
		virtual bool GetUseSphereCollision() const;

	UFUNCTION(BlueprintCallable, Category = "Settings")
		virtual void SetUseSphereCollision(const bool UseSphereCollision);

	UFUNCTION(BlueprintCallable, Category = "Settings")
		void ToggleIsActive();

	UFUNCTION(BlueprintCallable, Category = "Settings")
		void ToggleUseTick();

	UFUNCTION(BlueprintCallable, Category = "Settings")
		void ToggleUseSphereCollision();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		bool bAutoStart = false;

protected:
	virtual void BeginPlay() override;

	virtual void StartTimer();

	virtual void SplineUpdate();

	FTimerHandle MemberTimerHandle;

	FVector NewLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		AActor* ActorToFollow = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		float Frequency = 0.1f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Settings")
		bool bUseTick = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Settings")
		bool bIsActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
		bool bUseSphereCollision = true;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Component")
		USphereComponent* SphereComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Component")
		USceneComponent* SceneComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Component")
		UAudioComponent* AudioComponent = nullptr;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Component")
		USplineComponent* SplineComponent = nullptr;

	UFUNCTION(Category = "Collision")
		virtual void OnOverlapBegin(
			UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

	UFUNCTION(Category = "Collision")
		virtual void OnOverlapEnd(
			UPrimitiveComponent* OverlappedComp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

};
