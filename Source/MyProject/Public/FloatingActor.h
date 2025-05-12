// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OurFunctionLib.h"
#include "FloatingActor.generated.h"

UCLASS()
class MYPROJECT_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

	UPROPERTY()
	USceneComponent* Root;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, Category = "Mesh Spawning")
	UStaticMesh* MeshToSpawn;


	UPROPERTY(EditAnywhere, Category = "Mesh Spawning")
	UMaterialInterface* MaterialToApply;

	UPROPERTY(EditAnywhere, meta = (ClampMin = 10, ClampMax = 100))
	int32 resolution = 10;

	
	TArray<UStaticMeshComponent*> points;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave")
	EWaveFunction WaveFunction = EWaveFunction::Wave;





	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
