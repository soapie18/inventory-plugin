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

bool UInventoryComponent::MakeNewSlot(int QuantityToAdd, FItemRowData* Row)
{
	//bool AllAdded = false;

	//if (!AllSlotsFilled)
	//{
	//	//Make a slot with up to the max allowed quantity (if quantity to add does not exceed max).
	//	if (QuantityToAdd <= Row->StackHeight)
	//	{
	//		/*FInventorySlot Stack(QuantityToAdd, Row);*/

	//		FInventorySlot Stack;

	//		AllAdded = true;

	//		return AllAdded; 
	//	}

	//	//If quantity to add exceeds max, make a slot with max value, subtract this from left to add, 
	//	//and then call this function again to go through the process of creating a slot with the right quantity in it next time.
	//	else
	//	{
	//		/*FInventorySlot Stack(Row->StackHeight, Row);*/

	//		FInventorySlot Stack;

	//		QuantityToAdd -= Row->StackHeight;

	//		if (QuantityToAdd <= 0)
	//		{
	//			AllAdded = true;
	//			return AllAdded;
	//		}

	//		AllAdded = MakeNewSlot(QuantityToAdd, Row);

	//		if (!AllAdded)
	//		{
	//			AllSlotsFilled = true;

	//			//TODO: Drop excess
	//		}

	//		return AllAdded;
	//	}
	//}

	//else
	//{
	//	//TODO: Drop excess
	//	AllAdded = false;

	//	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Blue, TEXT("Inventory is full"));
	//	return false;
	//}
	return false;
}


bool UInventoryComponent::AddItemToInventory(FName RowName, UDataTable* Table, int QuantityToAdd)
{
	//if (AllSlotsFilled)
	//{
	//	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Blue, TEXT("Inventory is full"));

	//	//TODO: Drop excess

	//	return false;
	//}

	//if (Table == nullptr)
	//{
	//	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Green, TEXT("Table Null Ptr"));
	//	return false;
	//}
	//
	//FItemRowData* Row = Table->FindRow<FItemRowData>(RowName, TEXT("Item Lookup"));

	//if (Row == nullptr)
	//{
	//	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 2.0f, FColor::Green, TEXT("Row Null Ptr"));
	//	return false;
	//}
	//
	//for (FInventorySlot& Slot : InventoryArray)
	//{
	//	bool AllQuantityAdded = false;

	//	//Is there an existing slot, and does it have space?
	//	if (Slot.ItemData->ItemID == Row->ItemID && Slot.Quantity <= Slot.ItemData->StackHeight)
	//	{
	//		//Finding the difference between the current stack height and the max stack height, and subtracting
	//		//this from amount left to allocate to the inventory. Figuring out how much quantity we should add to the stack found.

	//		int Difference = Slot.ItemData->StackHeight - Slot.Quantity;

	//		if (Difference >= QuantityToAdd)
	//		{
	//			Slot.Quantity += QuantityToAdd;

	//			AllQuantityAdded = true;
	//			
	//			return AllQuantityAdded;
	//		}

	//		//Quantity left to add was larger than space in found slot so set the slot to max and track how much we have left to add to yet another slot.
	//		QuantityToAdd -= Slot.ItemData->StackHeight - Slot.Quantity;
	//		Slot.Quantity = Slot.ItemData->StackHeight;
	//		
	//		//Exit the function if we are at 0 - is this necessary? because of difference >= check earlier? will keep for now.
	//		if (QuantityToAdd <= 0)
	//		{
	//			return true;
	//		}
	//		
	//		//Using the leftovers and making a new stack holding that quantity if possible. This function calls itself within,
	//		//so that enough slots are made to hold all the quanitity given to it. If max slots is hit it will instead drop the
	//		//excess.
	//		AllQuantityAdded = MakeNewSlot(QuantityToAdd, Row);

	//		return AllQuantityAdded;
	//	}

	//	else
	//	{
	//		bool AllQuantityAdded = MakeNewSlot(QuantityToAdd, Row);

	//		return AllQuantityAdded;
	//	}
	//}
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







