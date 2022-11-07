// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Net/UnrealNetwork.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SM = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));

	ConstructorHelpers::FObjectFinder<UStaticMesh> SMS(TEXT("StaticMesh'/Game/VehicleVarietyPack/Meshes/SM_Hatchback.SM_Hatchback'"));

	if (SMS.Succeeded())
	{
		SM->SetStaticMesh(SMS.Object);
	}

	bReplicates = true;
	SetReplicateMovement(true);
}

void AMyActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
	MyLocation = GetActorLocation();

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AMyActor::MyActorMove_Implementation(FVector Value)
{
	AddActorWorldOffset(Value);
}

