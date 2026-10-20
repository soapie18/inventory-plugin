// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemDataAsset.h"
#include "InventoryComponent.generated.h"


USTRUCT()
struct FInventoryItemSlot 
{
	GENERATED_BODY()
public:
	TObjectPtr<UItemDataAsset> ItemData = nullptr;
	int currentQuantity = 0;
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
	bool AddItemToInventory(UItemDataAsset* ItemData);
	

	// Debigging Functions

	UFUNCTION( BlueprintCallable )
	void DebugPrintItemsStored();


	// Getter functions
	
	UFUNCTION( BlueprintCallable, BlueprintPure=true)
	float GetNetInventoryValue();
	
	UFUNCTION(BlueprintCallable, BlueprintPure=true)
	int GetStackQuanitityOfItem(UItemDataAsset* itemData);
	
private:
	
	TArray<FInventoryItemSlot> InventoryArray {};

	UPROPERTY(BlueprintReadOnly)
	float NetInventoryValue;
	
 //public:
 //	UPROPERTY( BlueprintReadWrite, EditAnywhere, Category = "Inventory Details" )
 //	float MaxCarryCapacity;

	

};
