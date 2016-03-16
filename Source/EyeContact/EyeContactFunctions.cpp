// Fill out your copyright notice in the Description page of Project Settings.

#include "EyeContact.h"
#include "EyeContactFunctions.h"




bool UEyeContactFunctions::SetMousePosition(const APlayerController* PlayerController, const float PosX, const float PosY)
{
	if (!PlayerController) return false;
	//~~~~~~~~~~~~~

	//Get Player
	const ULocalPlayer * Player = Cast<ULocalPlayer>(PlayerController->Player);
	//PlayerController::Player is UPlayer

	if (!Player) return false;
	//~~~~~~~~~~~~~~~~~~~~

	//get view port ptr
	const UGameViewportClient * ViewportClient =
		Cast < UGameViewportClient >(Player->ViewportClient);

	if (!ViewportClient) return false;
	//~~~~~~~~~~~~~~~~~~~~

	FViewport * Viewport = ViewportClient->Viewport;
	
	if (!Viewport) return false;
	//~~~~~~~~~~~~~~~~~~~~

	//Set Mouse
	Viewport->SetMouse(int32(PosX), int32(PosY));

	return true;
}

float UEyeContactFunctions::GetRenderedMonsters(TArray<AMonsterPlayer*>& CurrentlyRenderedMonsters, float MinRecentTime, TArray<AMonsterPlayer*> Monsters)
{
	//Empty any previous entries
	CurrentlyRenderedMonsters.Empty();
	float LastRenderedTime = -1;
	//Iterate Over Actors
	for (int i = 0; i < Monsters.Num(); i++) //for (TObjectIterator<AMonsterPlayer> Itr; Itr; ++Itr)
	{
		
		UE_LOG(LogTemp,Warning,TEXT("Name, Time: %s , %f"),*Monsters[i]->GetName(), Monsters[i]->GetLastRenderTime());
		if (Monsters[i]->GetLastRenderTime() > MinRecentTime)
		{
			LastRenderedTime = Monsters[i]->GetLastRenderTime();
			CurrentlyRenderedMonsters.Add(Monsters[i]);
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Size: %d"),CurrentlyRenderedMonsters.Num());
	return LastRenderedTime > MinRecentTime ? LastRenderedTime : MinRecentTime;
}