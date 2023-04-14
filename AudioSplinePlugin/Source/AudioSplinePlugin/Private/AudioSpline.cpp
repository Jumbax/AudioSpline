// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioSpline.h"
#include "Components/AudioComponent.h"
#include "Components/SceneComponent.h"
#include "Components/SphereComponent.h"
#include "Components/SplineComponent.h"


AAudioSpline::AAudioSpline()
{
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	RootComponent = SceneComponent;
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->SetupAttachment(SceneComponent);
	SplineComponent = CreateDefaultSubobject<USplineComponent>("SplineComponent");
	SplineComponent->SetupAttachment(SceneComponent);
	AudioComponent = CreateDefaultSubobject<UAudioComponent>("SplineAudioComponent");
	AudioComponent->SetupAttachment(SceneComponent);
}

void AAudioSpline::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AAudioSpline::OnOverlapBegin);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AAudioSpline::OnOverlapEnd);
	bIsActive = bAutoStart;
	SetActorTickEnabled(bUseTick);
	if (!bUseTick)
	{
		StartTimer();
	}
}

void AAudioSpline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsActive)
	{
		SplineUpdate();
	}
}

void AAudioSpline::SplineUpdate()
{
	NewLocation = SplineComponent->FindLocationClosestToWorldLocation(ActorToFollow->GetActorLocation(),
		ESplineCoordinateSpace::World);
	AudioComponent->SetWorldLocation(NewLocation);
}

void AAudioSpline::StartTimer()
{
	if (!bIsActive)
	{
		return;
	}
	if (!MemberTimerHandle.IsValid())
	{
		bIsActive = true;
		GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AAudioSpline::SplineUpdate, Frequency, true);
	}
}

bool AAudioSpline::GetActive() const
{
	return bIsActive;
}

void AAudioSpline::SetActive(const bool IsActive)
{
	bIsActive = IsActive;
	SetActorTickEnabled(bUseTick);
	if (!bIsActive)
	{
		GetWorldTimerManager().ClearTimer(MemberTimerHandle);
		return;
	}
	if (!bUseTick)
	{
		StartTimer();
	}
}

bool AAudioSpline::GetUseTick() const
{
	return bUseTick;
}

void AAudioSpline::SetUseTick(const bool UseTick)
{
	bUseTick = UseTick;
	SetActive(bIsActive);
}

void AAudioSpline::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!bUseSphereCollision)
	{
		return;
	}
	if (OtherActor == ActorToFollow)
	{
		SetActive(true);
	}
}

void AAudioSpline::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (!bUseSphereCollision)
	{
		return;
	}
	if (OtherActor == ActorToFollow)
	{
		SetActive(false);
	}
}

float AAudioSpline::GetFrequency() const
{
	return Frequency;
}

void AAudioSpline::SetFrequency(const float NewFrequency)
{
	if (NewFrequency > 0)
	{
		Frequency = NewFrequency;
	}
}

bool AAudioSpline::GetUseSphereCollision() const
{
	return bUseSphereCollision;
}

void AAudioSpline::SetUseSphereCollision(const bool UseSPhereCollision)
{
	bUseSphereCollision = UseSPhereCollision;
}

void AAudioSpline::ToggleIsActive()
{
	SetActive(!GetActive());
}

void AAudioSpline::ToggleUseTick()
{
	SetUseTick(!GetUseTick());
}

void AAudioSpline::ToggleUseSphereCollision()
{
	bUseSphereCollision = !bUseSphereCollision;
}