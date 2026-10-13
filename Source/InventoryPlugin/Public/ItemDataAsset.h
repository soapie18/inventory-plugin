// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYPLUGIN_API UItemDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	FName itemID;

	UPROPERTY(EditAnywhere)
	FText itemDisplayName;

	UPROPERTY(EditAnywhere)
	float itemWeight;
	
	UPROPERTY(EditAnywhere)
	float itemValue;

	UPROPERTY(EditAnywhere)
	bool stackable;

	UPROPERTY(EditAnywhere)
	float stackHeight;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UTexture2D> itemIcon = nullptr;;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMesh> itemMesh = nullptr;
};
