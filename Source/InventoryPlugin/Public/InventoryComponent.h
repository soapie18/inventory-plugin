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
	bool AddItemToInventory(FName Row);
	

	// Debugging Functions

	UFUNCTION( BlueprintCallable )
	void DebugPrintItemsStored();


	// Getter functions
	
	UFUNCTION( BlueprintCallable, BlueprintPure = true, Category = "Get - Inventory" )
	float GetCurrentWeight();
	
	//UFUNCTION( BlueprintCallable, BlueprintPure=true)
	//float GetNetInventoryValue();
	
	/*UFUNCTION(BlueprintCallable, BlueprintPure=true)
	int GetStackQuanitityOfItem(UItemDataAsset* itemData);*/
	
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
