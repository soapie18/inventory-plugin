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
	UPROPERTY(BlueprintReadOnly)
	FName identifier;

	UPROPERTY(BlueprintReadOnly)
	FText itemDisplayName;

	UPROPERTY(BlueprintReadOnly)
	float itemWeight;

	UPROPERTY(BlueprintReadOnly)
	bool stackable;

	UPROPERTY(BlueprintReadOnly)
	float stackHeight;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UTexture2D> itemIcon;
};
