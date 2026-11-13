// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "Components/BoxComponent.h"
#include "ItemRowData.h"
#include "ItemActor.generated.h"



UCLASS()
class INVENTORYPLUGIN_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(RowType= "ItemRowData"), meta = (ShowOnlyInnerProperties), Category = "Item Details")
	FDataTableRowHandle ItemRowHandle;

	UPROPERTY(BlueprintReadOnly, Category = "Item Details")
	int MaxStackQuantity = 0;

	UPROPERTY(BlueprintReadWrite, Category = "Item Details")
	int CurrentStack = 0;


private:

	UPROPERTY(VisibleAnywhere, Category = "Default")
	TObjectPtr<UStaticMeshComponent> StaticMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category = "Default")
	TObjectPtr<UBoxComponent> Box;


};
