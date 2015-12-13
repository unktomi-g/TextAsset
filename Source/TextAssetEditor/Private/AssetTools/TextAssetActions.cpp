// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "TextAssetEditorPrivatePCH.h"
#include "ContentBrowserModule.h"


#define LOCTEXT_NAMESPACE "AssetTypeActions"


/* FTextAssetActions constructors
 *****************************************************************************/

FTextAssetActions::FTextAssetActions(const TSharedRef<ISlateStyle>& InStyle)
	: Style(InStyle)
{ }


/* FAssetTypeActions_Base overrides
 *****************************************************************************/

bool FTextAssetActions::CanFilter()
{
	return true;
}


uint32 FTextAssetActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}


FText FTextAssetActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_TextAsset", "Text Asset");
}


UClass* FTextAssetActions::GetSupportedClass() const
{
	return UTextAsset::StaticClass();
}


FColor FTextAssetActions::GetTypeColor() const
{
	return FColor::White;
}


bool FTextAssetActions::HasActions(const TArray<UObject*>& InObjects) const
{
	return false;
}


void FTextAssetActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid()
		? EToolkitMode::WorldCentric
		: EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto TextAsset = Cast<UTextAsset>(*ObjIt);

		if (TextAsset != nullptr)
		{
			TSharedRef<FTextAssetEditorToolkit> EditorToolkit = MakeShareable(new FTextAssetEditorToolkit(Style));
			EditorToolkit->Initialize(TextAsset, Mode, EditWithinLevelEditor);
		}
	}
}



#undef LOCTEXT_NAMESPACE