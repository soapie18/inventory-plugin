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



float UInventoryComponent::GetCurrentValue()
{
	float TotalValue = 0;

	for (const FInventorySlot& Slot : InventoryArray)
	{
		TotalValue += Slot.ItemData->ItemValue;
	}

	return TotalValue;
}

int UInventoryComponent::GetNumberOfStacks()
{
	return InventoryArray.Num();
}

int UInventoryComponent::GetTotalArrayItemsQuantity()
{
	int TotalQuantity = 0;

	for (const FInventorySlot& Slot : InventoryArray)
	{
		TotalQuantity += Slot.Quantity;
	}
	
	return TotalQuantity;
}


// Key Functionality

bool UInventoryComponent::AddItemToInventory(FName RowName, UDataTable* Table, int QuantityToAdd)
{
	if (Table == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Green, TEXT("Table Null Ptr"));
		return false;
	}
	
	FItemRowData* Row = Table->FindRow<FItemRowData>(RowName, TEXT("Item Lookup"));

	if (Row == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Green, TEXT("Row Null Ptr"));
		return false;
	}
	
	//first check to see if theres space in a previous slot. when making a new slot check if max slots is hit then use reserve with the remainder as N.
	
	//could use recursion to keep calling this function until all of QuanityToAdd has either found a home or been dropped, since it might be quite a large
	//number and theres no way of telling it will fit in 2 stacks perfectly.
	
	for (FInventorySlot& Slot : InventoryArray)
	{
		if (Slot.ItemData->ItemID == Row->ItemID && Slot.Quantity <= Slot.ItemData->StackHeight)
		{
			//Finding the difference between the current stack height and the max stack height, and subtracting
			//this from amount left to allocate to the inventory. 
			QuantityToAdd -= Slot.ItemData->StackHeight - Slot.Quantity;
			Slot.Quantity = Slot.ItemData->StackHeight;
			
			if (QuantityToAdd <= 0)
			{
				return true;
			}
			
			if (!AllSlotsFilled)
			{
				//Using the leftovers and making a new stack holding that quantity, if it is less than or equal to
				//the max stack height for the given item type.
				FInventorySlot Stack;
				Stack.ItemData = Row;
				
				if (QuantityToAdd <= Stack.ItemData->StackHeight)
				{
					Stack.Quantity = QuantityToAdd;
					return true;
				}
				
				else
				{
					/*AddItemToInventory(RowName, Table, QuantityToAdd);*/
					return false;
					//TODO: Figure out how to recursively call this function until QuantityToAdd == 0 or excess is dropped.
				}
				
				
			}

			else
			{
				//TODO: Drop Excess
				return false;
			}
		}
	}
	
	return false;
}


bool UInventoryComponent::RemoveItemFromInventory(FName RowName, UDataTable* Table)
{
	if (Table == nullptr)
	{
		return false;
	}

	FItemRowData* Row = Table->FindRow<FItemRowData>(RowName, TEXT("Item Lookup"));

	if (Row == nullptr)
	{
		return false;
	}

	bool ItemFound = false;

	for (FInventorySlot& Slot : InventoryArray)
	{
		if (Slot.ItemData->ItemID == Row->ItemID)
		{
			ItemFound = true;

			Slot.Quantity -= 1;

			/*if (Slot.Quantity == 0)
			{
				InventoryArray.Remove(Slot);
			}*/
		}

		if (ItemFound)
		{
			break;
		}
	}

	if (ItemFound)
	{
		return true;
	}

	else
	{
		return false;
	}
}

// Output funcs

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







