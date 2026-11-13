// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemRowData.h"
#include "Engine/DataTable.h"
#include "InventoryComponent.generated.h"


USTRUCT()
struct FInventorySlot 
{
	GENERATED_BODY()
public:
	const FItemRowData* ItemData = nullptr;
	int32 Quantity = 0;

	FInventorySlot();

	FInventorySlot(int32 Q, FItemRowData* DataPtr)
	{
		Quantity = Q;
		ItemData = DataPtr;
	}

}; 




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYPLUGIN_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Key functionality

	bool MakeNewSlot(int QuantityToAdd, FItemRowData* Row);

	UFUNCTION( BlueprintCallable )
	bool AddItemToInventory(FName Row, UDataTable* Table, int QuantityToAdd);

	UFUNCTION(BlueprintCallable)
	bool RemoveItemFromInventory(FName Row, UDataTable* Table);

	/*UFUNCTION(BlueprintCallable)
	void InstantiateDroppedObject(FName Row, UDataTable* Table);*/
	
	// Debugging Functions

	UFUNCTION( BlueprintCallable )
	void DebugPrintItemsStored();

	// Getter functions
	
	UFUNCTION(BlueprintCallable, BlueprintPure = true, Category = "Inventory")
	float GetCurrentValue();

	UFUNCTION(BlueprintCallable, BlueprintPure = true, Category = "Inventory")
	int GetNumberOfStacks();

	UFUNCTION(BlueprintCallable, BlueprintPure = true, Category = "Inventory")
	int GetTotalArrayItemsQuantity();



private:
	
	TArray<FInventorySlot> InventoryArray {};

	UPROPERTY()
	float NetInventoryValue;
	
	UPROPERTY(EditAnywhere, Category = "Inventory Details")
	int MaxInventorySlots;

	bool AllSlotsFilled = false;
	
public:
	
	UPROPERTY(EditAnywhere, Category = "Inventory Details")
	TObjectPtr<UDataTable> ItemsTable = nullptr;


};
