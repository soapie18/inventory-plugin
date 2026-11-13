// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemActor.h"

// Sets default values
AItemActor::AItemActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMesh"));
	
	RootComponent = StaticMesh;
	
	Box = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollider"));

	Box->SetBoxExtent(FVector(64, 64, 64));
	Box->SetGenerateOverlapEvents(true);
	Box->SetupAttachment(RootComponent);

	FItemRowData* Row = ItemRowHandle.DataTable->FindRow<FItemRowData>(ItemRowHandle.RowName, TEXT("Retrieving Row"));

	if (Row != nullptr)
	{
		MaxStackQuantity = Row->MaxStackHeight;
	}
	
	CurrentStack = rand() % MaxStackQuantity;

}

// Called when the game starts or when spawned
void AItemActor::BeginPlay()
{
	Super::BeginPlay();
	

	FString Message = "Max stack quantity of item: ";
	Message.AppendInt(MaxStackQuantity);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Black, Message);

	FString Message2 = "Max stack quantity of item: ";
	Message2.AppendInt(CurrentStack);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Black, Message2);
}

// Called every frame
void AItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

