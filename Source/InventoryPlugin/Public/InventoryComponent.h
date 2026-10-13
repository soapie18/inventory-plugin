// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemDataAsset.h"
#include "InventoryComponent.generated.h"


USTRUCT()
struct FInventoryItemStack 
{
	GENERATED_BODY()

public:
	TObjectPtr<UItemDataAsset> itemData = nullptr;
 
	float currentQuanity = 0.0f;
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

	UPROPERTY()
	TArray<FInventoryItemStack> ItemsArr;

	bool AddItemToInventory(UItemDataAsset* itemData);
};
