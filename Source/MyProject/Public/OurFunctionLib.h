// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OurFunctionLib.generated.h"

UENUM(BlueprintType)
enum class EWaveFunction : uint8
{
	Wave        UMETA(DisplayName = "Wave"),
	MultiWave   UMETA(DisplayName = "MultiWave"),
	Ripple      UMETA(DisplayName = "Ripple"),
	Sphere      UMETA(DisplayName = "Sphere"),
	Torus		UMETA(DisplayName = "Torus")
};

using FWaveFunction = TFunction<FVector(float, float, float)>; 

class MYPROJECT_API FunctionDispatcher
{
public:
    static FWaveFunction GetFunction(EWaveFunction FunctionType);
};


/**
 * 
 */
UCLASS()
class MYPROJECT_API UOurFunctionLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Static function
	UFUNCTION(BlueprintCallable, Category = "Math|WaveFunctions")
	static FVector Wave(float Y, float X, float T);

	UFUNCTION(BlueprintCallable, Category = "Math|WaveFunctions")
	static FVector MultiWave(float Y, float X, float T);

	UFUNCTION(BlueprintCallable, Category = "Math|WaveFunctions")
	static FVector Ripple(float Y, float X, float T);

	UFUNCTION(BlueprintCallable, Category = "Math|WaveFunctions")
	static FVector Sphere(float Y, float X, float T);

	UFUNCTION(BlueprintCallable, Category = "Math|WaveFunctions")
	static FVector Torus(float Y, float X, float T);
	
};
