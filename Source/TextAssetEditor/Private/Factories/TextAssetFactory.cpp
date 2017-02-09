// Copyright 2015 Headcrash Industries LLC. All Rights Reserved.

#include "TextAssetEditorPrivatePCH.h"
#include "TextAssetFactory.h"


/* UTextAssetFactory structors
 *****************************************************************************/

UTextAssetFactory::UTextAssetFactory( const FObjectInitializer& ObjectInitializer )
	: Super(ObjectInitializer)
{
	Formats.Add(FString(TEXT("txt;")) + NSLOCTEXT("UTextAssetFactory", "FormatTxt", "Text File").ToString());
	Formats.Add(FString(TEXT("xml;")) + NSLOCTEXT("UTextAssetFactory", "FormatXml", "XML File").ToString());
	Formats.Add(FString(TEXT("json;")) + NSLOCTEXT("UTextAssetFactory", "FormatJSON", "JSON File").ToString());
	SupportedClass = UTextAsset::StaticClass();
	bCreateNew = false;
	bEditorImport = true;
}


/* UFactory overrides
 *****************************************************************************/

UObject* UTextAssetFactory::FactoryCreateBinary(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, const TCHAR* Type, const uint8*& Buffer, const uint8* BufferEnd, FFeedbackContext* Warn)
{
	UTextAsset* TextAsset = nullptr;
	FString TextString;

	if (FFileHelper::LoadFileToString(TextString, *CurrentFilename))
	{
		TextAsset = NewObject<UTextAsset>(InParent, Class, Name, Flags);
		TextAsset->Text = FText::FromString(TextString);
	}

	return TextAsset;
}
