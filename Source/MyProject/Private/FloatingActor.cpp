// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"
#include "OurFunctionLib.h"


// Sets default values
AFloatingActor::AFloatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = Root;

}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();

    if (!MeshToSpawn) {
        UE_LOG(LogTemp, Warning, TEXT("No MeshToSpawn!"));
        return;
    }

    float step = 2.f / resolution;
    float scale = step;

    for (int i = 0; i < resolution * resolution; i++) {
        UStaticMeshComponent* MeshComp = NewObject<UStaticMeshComponent>(this);
        MeshComp->RegisterComponent();
        MeshComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
        MeshComp->SetStaticMesh(MeshToSpawn);
        MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        MeshComp->SetSimulatePhysics(false);
        if (MaterialToApply)
            MeshComp->SetMaterial(0, MaterialToApply);

        MeshComp->SetRelativeScale3D(FVector(scale)); // scale to keep cubes small
        points.Add(MeshComp);
    }
               
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FWaveFunction Function = FunctionDispatcher::GetFunction(WaveFunction);

    float step = 2.f / resolution;
    float V = 50.f * step - 100.f; //!!! (100 * x + 50) * step - 100.f;
    for (int i = 0, y = 0, x = 0; i < resolution * resolution; i++, y++) {
        if (y == resolution) {
            y = 0;
            x += 1;
            V = (100 * x + 50) * step - 100.f;
        }
    float Time = GetWorld()->GetTimeSeconds();
    float U = (100 * y + 50) * step - 100.f;
    UStaticMeshComponent* MeshComp = points[i];
    FVector Position = FVector(0.f);
    Position = Function(U, V, Time);
    MeshComp->SetRelativeLocation(Position);
    }

    
}

