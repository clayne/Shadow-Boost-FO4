#pragma once

#include "pch.h"

namespace Translation {

	static const char* TranslationsDir = "Data\\F4SE\\Plugins\\Translations\\ShadowBoostFO4\\";
	static const char* TranslationFile = "Language.txt";

	static const char* DefaultLang = "en";

	enum class LangID : std::uint32_t {

		CaptionWnd = 0,
		StatusHdr,
		AvgMs,
		DynValue,
		ShadowDist,
		ObjectDist,
		ItemsDist,
		ActorsDist,
		GrassDist,
		BlockLvl2,
		BlockLvl1,
		BlockLvl0,
		GodraysQuality,
		GodraysGrid,
		GodraysScale,
		GodraysCascade,
		CurrentLocationHdr,
		IsInterior,
		HasPreset,
		InteriorId,
		ExteriorId,
		InteriorName,
		ExteriorName,
		AddToPreset,
		RemoveFromPreset,
		SavePreset,
		HelpHdr,
		HelpText,
		MainHdr,
		FpsTarget,
		FpsDelay,
		MsTolerance,
		ShadowHdr,
		EnableShadow,
		ShadowFactor,
		MinShadow,
		MaxShadow,
		LodHdr,
		EnableLod,
		LodFactor,
		MinObjects,
		MaxObjects,
		MinItems,
		MaxItems,
		MinActors,
		MaxActors,
		TerrainManagerHdr,
		EnableBlockLevels,
		BlockFactor,
		BlockLevel2,
		BlockLevel1,
		BlockLevel0,
		DynValues,
		StatValues,
		CaptEditor,
		GrassHdr,
		EnableGrass,
		GrassFactor,
		MinGrass,
		MaxGrass,
		GodRaysHdr,
		EnableGodRays,
		GrQuality,
		GrGrid,
		GrScale,
		GrCascade,
		OthersHdr,
		Hotkeys,
		EnableLog,
		Transparent,
		StopInMenu,
		CreditsHdr,
		Load,
		Save,
		Default,
		WaitForNewKey,
		MenuFile,
		MenuSettings,
		MenuExit,
		MenuPreset,
		MenuEditor,
		MenuInfo,
		MenuHelp,
		MenuAbout,
		ComboLevel0,
		ComboLevel1,
		ComboLevel2,
		ComboLevel3,
		Level,
		Settings,
		OpenMenu,
		RunPausePlugin,
		FontScale,
		Classic,
		Light,
		Dark,
		MenuStyles,
		Cancel,
		SaveClose,
		About,	
		Total
	};

	enum class LangGlyph : std::uint32_t {

		Default,
		Korean,
		Japanese,
		ChineseFull,
		ChineseSimplifiedCommon,
		Cyrillic,
		Thai,
		Vietnamese
	};

	class Language {

	public:

		[[nodiscard]] static Language& GetSingleton() noexcept { return instance; }

		void Load() noexcept;

		[[nodiscard]] const char* operator[](const LangID id) noexcept { return vec[static_cast<std::uint32_t>(id)].c_str(); }

		[[nodiscard]] const ImWchar* SelectGlyph(ImGuiIO& io, const LangGlyph& glyph) noexcept;
		[[nodiscard]] void SetGlyph(ImGuiIO& io, float sizePixels = 13) noexcept;

	private:

		Language() noexcept {}
		~Language() noexcept {}

		Language(const Language&) = delete;
		Language(Language&&) = delete;

		Language& operator=(const Language&) = delete;
		Language& operator=(Language&&) = delete;

		[[nodiscard]] std::wstring GetFallout4ini() noexcept;
		[[nodiscard]] const std::string& GetFallout4lang() noexcept;

		std::string sLang{ DefaultLang };

		std::vector<std::string> vec{
			"Shadow Boost FO4",
			"Status",
			"Avg ms frames : %.3f",
			"Dynamic Value : %.3f",
			"Shadow Dist : %.3f",
			"Objects Dist : %.3f",
			"Items Dist : %.3f",
			"Actors Dist : %.3f",
			"Grass Dist : %.3f",
			"BlockLevel 2 Dist : %.3f",
			"BlockLevel 1 Dist : %.3f",
			"BlockLevel 0 Dist : %.3f",
			"God rays Quality : %i",
			"God rays Grid : %i",
			"God rays Scale : %.3f",
			"God rays Cascade : %i",
			"Current Location",
			"Is Interior : %i",
			"Has Preset : %i",
			"Interior Id : %.8X",
			"Exterior Id : %.8X",
			"Interior name : %s",
			"Exterior name : %s",
			"Add to Preset",
			"Remove from Preset",
			"Save Preset",
			"Help",
			"It is highly recommended to configure all options,\nbecause the default options may not be compatible\nwith all systems, so better check the ini files of\nthe game to get a precise idea of which settings\nneed to be changed.",
			"Main",
			"Fps Target",
			"Fps Delay",
			"Ms Tolerance",
			"Shadow",
			"Enable Shadow",
			"Shadow Factor",
			"Min Shadow",
			"Max Shadow",
			"Lod",
			"Enable Lod",
			"Lod Factor",
			"Min Objects",
			"Max Objects",
			"Min Items",
			"Max Items",
			"Min Actors",
			"Max Actors",
			"Terrain Manager",
			"Enable Block Levels",
			"Block Factor",
			"Block Level 2",
			"Block Level 1",
			"Block Level 0",
			"Dynamic values :",
			"Static values :",
			"Editor",
			"Grass",
			"Enable Grass",
			"Grass Factor",
			"Min Grass",
			"Max Grass",
			"God Rays",
			"Enable God Rays",
			"Quality",
			"Grid",
			"Scale",
			"Cascade",
			"Others",
			"Hotkeys : ",
			"Enable Log (if activated it means that\nthis window always remains active)",
			"Make it transparent",
			"Pause when a menu is open",
			"Thanks and credits",
			"Load",
			"Save",
			"Default",
			"Waiting for a new key",
			"File",
			"Settings...",
			"Exit",
			"Preset",
			"Editor ...",
			"Info",
			"Help ...",
			"About ...",
			"Level 0 (Default)",
			"Level 1 (Low)",
			"Level 2 (Lower)",
			"Level 3 (Lowest)",
			"Level",
			"Settings",
			"Open menu : ",
			"Run/Pause plugin : ",
			"Font Scale",
			"Classic",
			"Light",
			"Dark",
			"Menu Styles",
			"Cancel",
			"Save & Close",
			"About",
			"unused"
		};

		const std::vector<std::pair<LangGlyph, std::string>> vecLang {
			{ LangGlyph::Default, "en" },
			{ LangGlyph::Default, "de" },
			{ LangGlyph::Default, "es" },
			{ LangGlyph::Default, "esmx" },
			{ LangGlyph::Default, "fr" },
			{ LangGlyph::Default, "it" },
			{ LangGlyph::Default, "ptbr"},
			{ LangGlyph::Japanese, "ja" },
			{ LangGlyph::Korean, "ko" },
			{ LangGlyph::ChineseSimplifiedCommon, "cn" },
			{ LangGlyph::Cyrillic, "ru" },
			{ LangGlyph::Cyrillic, "pl"}
		};

		static Language instance;
	};
}
