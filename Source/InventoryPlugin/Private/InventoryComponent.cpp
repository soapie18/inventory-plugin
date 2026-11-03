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


// Getters
float UInventoryComponent::GetCurrentWeight()
{
	float TotalWeight = 0;	
	
	for (const FInventorySlot& Slot : InventoryArray)
	{
		TotalWeight += Slot.ItemData->ItemWeight;
	}
	
	return TotalWeight;
}


bool UInventoryComponent::AddItemToInventory(FName RowName)
{
	if (ItemsTable == nullptr)
	{
		return false;
	}
	
	FItemRowData* Row = ItemsTable->FindRow<FItemRowData>(RowName, TEXT("Item Lookup"));

	if (Row == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Green, TEXT("Null Ptr"));
		return false;
	}
	
	float CurrentWeight = GetCurrentWeight();
	
	if (Row->ItemWeight + CurrentWeight > MaxCarryCapacity)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Green, TEXT("Max Capacity Reached"));
		return false;
	}
	
	if (Row->Stackable)
	{
		for (FInventorySlot& Slot : InventoryArray)
		{
			if (Slot.ItemData == Row && Slot.Quantity < Row->StackHeight)
			{
				Slot.Quantity += 1;
				return true;
			}
		}
	}
	
	FInventorySlot NewSlot;
	NewSlot.ItemData = Row;
	NewSlot.Quantity = 1;
	
	InventoryArray.Add(NewSlot);
	
	return true;
}


void UInventoryComponent::DebugPrintItemsStored()
{
	FString Message;
	
	for (const FInventorySlot& Slot : InventoryArray)
	{
		Message.Append(Slot.ItemData->ItemDisplayName.ToString() + " : ");
		Message.AppendInt(Slot.Quantity);
		Message.Append(", ");
		
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Green, Message);
	}
}







