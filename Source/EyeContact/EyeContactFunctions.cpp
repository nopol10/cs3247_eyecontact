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