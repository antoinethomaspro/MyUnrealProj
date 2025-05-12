// Fill out your copyright notice in the Description page of Project Settings.


#include "OurFunctionLib.h"

FVector UOurFunctionLib::Wave(float U, float V, float T)
{
    FVector p;
    p.Y = U;
    p.Z = FMath::Sin(PI * ((U + V) * 0.01f + T)) * 100.0f;
    p.X = V;
    return p;
}

FVector UOurFunctionLib::MultiWave(float Y, float X, float T)
{
    return FVector(0);
    
}

FVector UOurFunctionLib::Ripple(float Y, float X, float T)
{
    return FVector(0);
   
}

FVector UOurFunctionLib::Sphere(float U, float V, float T)
{
    FVector p;

    float r = 0.9f + 0.1f * FMath::Sin(PI * (6 * (U*0.01) + 4 * (V*0.01) + T));
    //float r = 0.9f + 0.1f * FMath::Sin(PI * (6.f * U + 4.f * V + T));

    float s = r * FMath::Cos(0.5f * PI * (V * 0.01));


    p.Y = s * (FMath::Sin(PI * ((U) * 0.01f)) * 100.0f);
    p.X = s * (FMath::Cos(PI * ((U) * 0.01f)) * 100.0f);
    p.Z = r * FMath::Sin(0.5f * PI * (V * 0.01f)) * 100.0f;

    //p.Y = FMath::Sin(PI * (V * 0.01f + T)) * 100.0f;
    return p;
}


FVector UOurFunctionLib::Torus(float U, float V, float T) {
    FVector p;

    float r1 = 0.7f + 0.1f * FMath::Sin(PI * (6.f * U * 0.01f + 0.5f * T));             //float r1 = 0.7f + 0.1f * Sin(PI * (6f * u + 0.5f * t));
    float r2 = 0.15f + 0.05f * FMath::Sin(PI * (8.f * U * 0.01f + 4.f * V * 0.01f + 2.f * T));  //float r2 = 0.15f + 0.05f * Sin(PI * (8f * u + 4f * v + 2f * t));
    float s = r1 + r2 * FMath::Cos(PI * (V * 0.01));

    p.Y = s * (FMath::Sin(PI * ((U) * 0.01f)) * 100.0f);
    p.X = s * (FMath::Cos(PI * ((U) * 0.01f)) * 100.0f);
    p.Z = r2 * FMath::Sin(PI * (V * 0.01f)) * 100.0f;

    return p;
}


FWaveFunction FunctionDispatcher::GetFunction(EWaveFunction FunctionType)
{
    switch (FunctionType)
    {
    case EWaveFunction::Wave:
        return [](float Y, float X, float T) { return UOurFunctionLib::Wave(Y, X, T); };
    case EWaveFunction::MultiWave:
        return [](float Y, float X, float T) { return UOurFunctionLib::MultiWave(Y, X, T); };
    case EWaveFunction::Ripple:
        return [](float Y, float X, float T) { return UOurFunctionLib::Ripple(Y, X, T); };
    case EWaveFunction::Sphere:
        return [](float Y, float X, float T) { return UOurFunctionLib::Sphere(Y, X, T); };
    case EWaveFunction::Torus:
        return [](float Y, float X, float T) { return UOurFunctionLib::Torus(Y, X, T); };
    default:
        return [](float Y, float X, float T) { return FVector(0.f); };
    }
}