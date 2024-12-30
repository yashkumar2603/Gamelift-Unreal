﻿#pragma once

#include "ShooterTypes.generated.h"

USTRUCT(BlueprintType)
struct FPlayerHitResult
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite)
	FVector_NetQuantize Start = FVector_NetQuantize::ZeroVector;

	UPROPERTY(BlueprintReadWrite)
	FVector_NetQuantize End = FVector_NetQuantize::ZeroVector;

	UPROPERTY(BlueprintReadWrite)
	bool bHitPlayer = false;
	
	UPROPERTY(BlueprintReadWrite)
	bool bHitPlayerLastFrame = false;

	UPROPERTY(BlueprintReadWrite)
	bool bHeadShot = false;
};

USTRUCT(BlueprintType)
struct FReticleParams
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ScaleFactor_Targeting = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ScaleFactor_NotTargeting = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ScaleFactor_Aiming = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ScaleFactor_NotAiming = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ShapeCutFactor_Aiming = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ShapeCutFactor_NotAiming = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ShapeCutFactor_RoundFired = 0.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float ScaleFactor_RoundFired = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float AimingInterpSpeed = 15.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TargetingPlayerInterpSpeed = 10.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RoundFiredInterpSpeed = 20.f;
};

UENUM(BlueprintType)
enum class ETurningInPlace : uint8
{
	Left UMETA(DisplayName = "TurningLeft"),
	Right UMETA(DisplayName = "TurningRight"),
	NotTurning UMETA(DisplayName = "NotTurning")
};

UENUM(meta = (Bitflags))
enum class ESpecialElimType : uint16
{
	None = 0,
	Headshot        = 1 << 0,    // 00000000 00000001
	Sequential      = 1 << 1,    // 00000000 00000010
	Streak          = 1 << 2,    // 00000000 00000100
	Revenge         = 1 << 3,    // 00000000 00001000
	Dethrone        = 1 << 4,    // 00000000 00010000
	Showstopper     = 1 << 5,    // 00000000 00100000
	FirstBlood      = 1 << 6,    // 00000000 01000000
	GainedTheLead   = 1 << 7,    // 00000000 10000000
	TiedTheLeader   = 1 << 8,    // 00000001 00000000
	LostTheLead   = 1 << 9     // 00000010 00000000
};

ENUM_CLASS_FLAGS(ESpecialElimType)