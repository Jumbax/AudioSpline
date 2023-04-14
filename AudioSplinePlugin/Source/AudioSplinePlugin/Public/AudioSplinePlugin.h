// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FAudioSplinePluginModule : public IModuleInterface, public FSelfRegisteringExec
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

protected:
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;

	virtual TSharedRef<SDockTab> SpawnAudioSplineTab(const FSpawnTabArgs& TabSpawnArgs);

	virtual FReply OnClickedToggleIsActiveButton();
	
	virtual FReply OnClickedToggleUseTickButton();
	
	virtual FReply OnClickedToggleUseSphereButton();
	
	virtual AAudioSpline* GetAudioSplineActor();
	
	virtual void ToggleIsActive();
	
	virtual void ToggleUseTick();
	
	virtual void ToggleUseSphereCollision();
};
