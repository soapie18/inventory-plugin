// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"



// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	//MaxCarryCapacity = 10.0f;
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
		for (FInventorySlot& Stack : InventoryArray)
		{
			if (Stack.ItemData == ItemData && Stack.Quantity < ItemData->stackHeight)
			{
				Stack.Quantity += 1;
				return true;
			}
		}
	}

	//change to using TMultiMap if becomes relevant - see docs
	FInventorySlot NewSlot;

	NewSlot.ItemData = ItemData;
	NewSlot.Quantity = 1;

	InventoryArray.Add(NewSlot);

	return true;
}

void UInventoryComponent::DebugPrintItemsStored()
{
	for (const FInventorySlot& Stack : InventoryArray)
	{
		FName Message = Stack.ItemData->itemID;
		GEngine->AddOnScreenDebugMessage(1, 5.0f, FColor::Green, Message.ToString());
	}

}

int UInventoryComponent::GetStackQuanitityOfItem(UItemDataAsset* ItemData)
{
	int itemStackSize = 0;

	for (FInventorySlot& Stack : InventoryArray)
	{
		if (Stack.ItemData == ItemData)
		{
			itemStackSize = Stack.Quantity;
			return itemStackSize;
		}
	}

	return itemStackSize;

}

float UInventoryComponent::GetNetInventoryValue()
{
	NetInventoryValue = 0;
	
	for (const FInventorySlot& Stack : InventoryArray)
	{
		NetInventoryValue += Stack.ItemData->itemValue;
	}

	return NetInventoryValue;
}




