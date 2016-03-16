// Fill out your copyright notice in the Description page of Project Settings.

#include "EyeContact.h"
#include "MonsterPlayer.h"


// Sets default values
AMonsterPlayer::AMonsterPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonsterPlayer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMonsterPlayer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

