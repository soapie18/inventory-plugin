// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"



// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


bool UInventoryComponent::AddItemToInventory(UItemDataAsset* ItemData)
{
	if (!ItemData)
	{
		return false;
	}
	
	if (ItemData->stackable)
	{
		for (FInventoryItemSlot& Stack : InventoryArray)
		{
			if (Stack.ItemData == ItemData && Stack.currentQuantity < ItemData->stackHeight )
			{
				Stack.currentQuantity++;
				return true;
			}
		}
	}
	
	//TODO: upgrade to TMultiMap if becomes relevant - see docs
	FInventoryItemSlot NewItem;
	NewItem.ItemData = ItemData;
	InventoryArray.Add(NewItem);
	
	return false;
}

void UInventoryComponent::DebugPrintItemsStored()
{
	for (const FInventoryItemSlot& Stack : InventoryArray)
	{
		FName Message = Stack.ItemData->itemID;
		GEngine->AddOnScreenDebugMessage(1, 10.0f, FColor::Green, Message.ToString());
	}
	
}


