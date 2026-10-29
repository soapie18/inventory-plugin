// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EItemCategory.h"
#include "ItemRowData.generated.h"

USTRUCT(BlueprintType)
struct FItemRowData : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	FString ItemID;

	UPROPERTY(EditAnywhere)
	FText ItemDisplayName;
	
	UPROPERTY(EditAnywhere)
	EItemCategory ItemCategory;

	UPROPERTY(EditAnywhere)
	float ItemWeight;
	
	UPROPERTY(EditAnywhere)
	float ItemValue;

	UPROPERTY(EditAnywhere)
	bool Stackable;

	UPROPERTY(EditAnywhere)
	float StackHeight;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UTexture2D> ItemIcon = nullptr;;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMesh> ItemMesh = nullptr;
};