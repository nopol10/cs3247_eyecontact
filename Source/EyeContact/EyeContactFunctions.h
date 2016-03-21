// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MonsterPlayer.h"
#include "EyeContactFunctions.generated.h"

/**
 * 
 */
UCLASS()
class EYECONTACT_API UEyeContactFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	// Set mouse position adapted from Rama's function
	// https://github.com/EverNewJoy/VictoryPlugin/blob/master/Source/VictoryBPLibrary/Private/VictoryBPFunctionLibrary.cpp
	UFUNCTION(BlueprintCallable, Category = "EyeContactFunctions")
	static bool SetMousePosition(const APlayerController* PlayerController, const float PosX, const float PosY);
	UFUNCTION(BlueprintCallable, Category = "EyeContactFunctions")
	static float GetRenderedMonsters(TArray<AMonsterPlayer*>& CurrentlyRenderedMonsters, float MinRecentTime, TArray<AMonsterPlayer*> Monsters);
};
