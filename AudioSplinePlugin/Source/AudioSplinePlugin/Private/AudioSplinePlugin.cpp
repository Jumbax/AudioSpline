// Copyright Epic Games, Inc. All Rights Reserved.

#include "AudioSplinePlugin.h"
#include "AudioSpline.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

#define LOCTEXT_NAMESPACE "FAudioSplinePluginModule"

static const FName AudioSplineTab = TEXT("AudioSplineTab");

void FAudioSplinePluginModule::StartupModule()
{
	const TSharedRef<FGlobalTabmanager> TabManager = FGlobalTabmanager::Get();
	TabManager->RegisterNomadTabSpawner(AudioSplineTab, FOnSpawnTab::CreateRaw(this, &FAudioSplinePluginModule::SpawnAudioSplineTab));
}

void FAudioSplinePluginModule::ShutdownModule()
{
	const TSharedRef<FGlobalTabmanager> TabManager = FGlobalTabmanager::Get();
	TabManager->UnregisterNomadTabSpawner(AudioSplineTab);
}

bool FAudioSplinePluginModule::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	if (FParse::Command(&Cmd, TEXT("AudioSpline")))
	{
		if (FParse::Command(&Cmd, TEXT("Tab")))
		{
			const TSharedRef<FGlobalTabmanager> TabManager = FGlobalTabmanager::Get();
				TabManager->TryInvokeTab(AudioSplineTab);
				return true;
		}
		else if (FParse::Command(&Cmd, TEXT("ToggleIsActive")))
		{
			ToggleIsActive();
			return true;
		}
		else if (FParse::Command(&Cmd, TEXT("ToggleUseTick")))
		{
			ToggleUseTick();
			return true;
		}
		else if (FParse::Command(&Cmd, TEXT("ToggleUseSphereCollision")))
		{
			ToggleUseSphereCollision();
			return true;
		}
	}

	return false;
}

TSharedRef<SDockTab> FAudioSplinePluginModule::SpawnAudioSplineTab(const FSpawnTabArgs& TabSpawnArgs)
{
	return SNew(SDockTab).TabRole(ETabRole::NomadTab)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight().Padding(8, 8, 8, 8)
		[
			SNew(SBorder).BorderBackgroundColor(FColor::White).Padding(8, 8, 8, 8)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot().AutoHeight().HAlign(EHorizontalAlignment::HAlign_Left).Padding(2, 0, 2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("ToggleIsActive", "Toggle Is Active"))
		.OnClicked_Raw(this, &FAudioSplinePluginModule::OnClickedToggleIsActiveButton)
		]
	+ SVerticalBox::Slot().AutoHeight().HAlign(EHorizontalAlignment::HAlign_Left).Padding(2, 0, 2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("ToggleUseTick", "Toggle Use Tick"))
		.OnClicked_Raw(this, &FAudioSplinePluginModule::OnClickedToggleUseTickButton)
		]
	+ SVerticalBox::Slot().AutoHeight().HAlign(EHorizontalAlignment::HAlign_Left).Padding(2, 0, 2, 0)
		[
			SNew(SButton)
			.Text(LOCTEXT("ToggleUseSphereCollision", "Toggle Use Sphere Collision"))
		.OnClicked_Raw(this, &FAudioSplinePluginModule::OnClickedToggleUseSphereButton)
		]
			]
		]
		];
}

FReply FAudioSplinePluginModule::OnClickedToggleIsActiveButton()
{
	ToggleIsActive();
	return FReply::Handled();
}

FReply FAudioSplinePluginModule::OnClickedToggleUseTickButton()
{
	ToggleUseTick();
	return FReply::Handled();
}

FReply FAudioSplinePluginModule::OnClickedToggleUseSphereButton()
{
	ToggleUseSphereCollision();
	return FReply::Handled();
}

AAudioSpline* FAudioSplinePluginModule::GetAudioSplineActor()
{
	FWorldContext* WorldContext = GEditor->GetPIEWorldContext(0);
	if (WorldContext)
	{
		UWorld* World = WorldContext->World();
		if (World)
		{
			for (TActorIterator<AActor> ItActor(World); ItActor; ++ItActor)
			{
				AActor* Actor = *ItActor;
				if (Actor->GetClass()->IsChildOf(AAudioSpline::StaticClass()))
				{
					return Cast<AAudioSpline>(Actor);
				}
			}
		}
	}
	return nullptr;
}

void FAudioSplinePluginModule::ToggleIsActive()
{
	AAudioSpline* AudioSpline = GetAudioSplineActor();
	if (AudioSpline)
	{
		AudioSpline->ToggleIsActive();
	}
}

void FAudioSplinePluginModule::ToggleUseTick()
{
	AAudioSpline* AudioSpline = GetAudioSplineActor();
	if (AudioSpline)
	{
		AudioSpline->ToggleUseTick();
	}
}

void FAudioSplinePluginModule::ToggleUseSphereCollision()
{
	AAudioSpline* AudioSpline = GetAudioSplineActor();
	if (AudioSpline)
	{
		AudioSpline->ToggleUseSphereCollision();
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAudioSplinePluginModule, AudioSplinePlugin)