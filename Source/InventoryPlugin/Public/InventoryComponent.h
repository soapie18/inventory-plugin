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
	FItemRowData* ItemData = nullptr;	
	int Quantity = 0;
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

	UFUNCTION( BlueprintCallable )
	bool AddItemToInventory(FName Row, UDataTable* Table);

	UFUNCTION(BlueprintCallable)
	bool RemoveItemFromInventory(FName Row, UDataTable* Table);

	UFUNCTION(BlueprintCallable)
	void InstantiateDroppedObject(FName Row, UDataTable* Table);
	
	// Debugging Functions

	UFUNCTION( BlueprintCallable )
	void DebugPrintItemsStored();

	// Getter functions
	
	UFUNCTION( BlueprintCallable, BlueprintPure = true, Category = "Inventory" )
	float GetCurrentWeight();

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
	float MaxCarryCapacity;

public:
	
	UPROPERTY(EditAnywhere, Category = "Inventory Details")
	TObjectPtr<UDataTable> ItemsTable = nullptr;


};
