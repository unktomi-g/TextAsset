// Copyright 2015 Headcrash Industries LLC. All Rights Reserved.

#pragma once

#include "TextAsset.generated.h"


/**
 * Implements an asset that can be used to store arbitrary text, such as notes
 * or documentation.
 */
UCLASS(BlueprintType, hidecategories=(Object))
class TEXTASSET_API UTextAsset
	: public UObject
{
	GENERATED_BODY()

public:

	/** Holds the stored text. */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="TextAsset")
	FText Text;

	/** Converts to Utf-8 encoded byte array */
	UFUNCTION(Blueprintpure, Category = "TextAsset")
		void ToBytes(TArray<uint8>& Bytes)
	{
		FTCHARToUTF8 Converter(*Text.ToString());
		Bytes.SetNumUninitialized(Converter.Length());
		FMemory::Memcpy(Bytes.GetData(), (uint8*)(ANSICHAR*)Converter.Get(), Bytes.Num());
	}
};
