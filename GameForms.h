typedef unsigned int UInt32;
typedef signed int Int32;
typedef unsigned short UInt16;
typedef signed short SInt16;
typedef unsigned char UInt8;

#include "GameTypes.h"

struct TESObjectREFR;
struct TESWorldSpace;
struct Script;
struct Character;
struct TESPackage;
struct EnchantmentItem;
struct IngredientItem;
struct TESFaction;
struct TESRace;

enum FormType
{
	kFormType_None = 0,
	kFormType_TES4,
	kFormType_Group,
	kFormType_GMST,
	kFormType_Global,
	kFormType_Class,
	kFormType_Faction,
	kFormType_Hair,
	kFormType_Eyes,
	kFormType_Race,
	kFormType_Sound,
	kFormType_Skill,
	kFormType_Effect,
	kFormType_Script,
	kFormType_LandTexture,
	kFormType_Enchantment,
	kFormType_Spell,		// 10
	kFormType_BirthSign,
	kFormType_Activator,
	kFormType_Apparatus,
	kFormType_Armor,
	kFormType_Book,
	kFormType_Clothing,
	kFormType_Container,
	kFormType_Door,
	kFormType_Ingredient,
	kFormType_Light,
	kFormType_Misc,
	kFormType_Stat,	// ???
	kFormType_Grass,
	kFormType_Tree,
	kFormType_Flora,
	kFormType_Furniture,	// 20
	kFormType_Weapon,
	kFormType_Ammo,
	kFormType_NPC,
	kFormType_Creature,
	kFormType_LeveledCreature,
	kFormType_SoulGem,
	kFormType_Key,
	kFormType_AlchemyItem,
	kFormType_SubSpace,
	kFormType_SigilStone,
	kFormType_LeveledItem,
	kFormType_SNDG,
	kFormType_Weather,
	kFormType_Climate,
	kFormType_Region,
	kFormType_Cell,			// 30
	kFormType_REFR,
	kFormType_ACHR,
	kFormType_ACRE,
	kFormType_PathGrid,
	kFormType_WorldSpace,
	kFormType_Land,
	kFormType_TLOD,	// tile low lod?
	kFormType_Road,
	kFormType_Dialog,
	kFormType_DialogInfo,
	kFormType_Quest,
	kFormType_Idle,
	kFormType_Package,
	kFormType_CombatStyle,
	kFormType_LoadScreen,
	kFormType_LeveledSpell,	// 40
	kFormType_ANIO,
	kFormType_WaterForm,
	kFormType_EffectShader,
	kFormType_TOFT
};
/***********BaseFormComponent***************/

struct BaseFormComponent_vtbl
{
	void* Destructor;
	void* unk01;
	void* CopyFromBase;
	void* CompareToBase; // return false if equal - compares names, typeID, flags
};

struct _BaseFormComponent
{
};

struct BaseFormComponent
{
	BaseFormComponent_vtbl* _vtbl;	// 000
};

/***********TESForm***************/

struct TESForm_ModReferenceList;

struct TESForm_ModReferenceList
{
	void				* data;		// ###TODO fix cyclic header dependency to use ModEntry::Data* directly
	TESForm_ModReferenceList	* next;
};

enum FormFlags
{
	kFormFlags_FromMaster           = 0x00000001,   // form is from an esm file
	kFormFlags_FromActiveFile       = 0x00000002,   // form is overriden by active mod or save file
	kFormFlags_Loaded				= 0x00000004,   // ?? (from OBSE ModEntry defininition)
	kFormFlags_Linked               = 0x00000008,   // set after formids have been resolved into TESForm*
	kFormFlags_Deleted              = 0x00000020,   // set on deletion, not saved in CS, probably game as well
	kFormFlags_BorderRegion         = 0x00000040,   // ?? (from TES4Edit)
	kFormFlags_TurnOffFire          = 0x00000080,   // ?? (from TES4Edit)
	kFormFlags_CastShadows          = 0x00000200,   // ?? (from TES4Edit), Unused, Don't cast shadows from TESR.
	kFormFlags_Essential            = 0x00000400,   // aka Quest Item, Persistent Reference, Essenstial Actor
	kFormFlags_InitiallyDisabled    = 0x00000800,   // ?? (from TES4Edit)
	kFormFlags_Ignored              = 0x00001000,   // record is not loaded by CS, perhaps game as well
	kFormFlags_Temporary            = 0x00004000,   // not saved in CS, probably game as well
	kFormFlags_VisibleWhenDistant   = 0x00008000,   // ?? (from TES4Edit)
	kFormFlags_OffLimits            = 0x00020000,   // ?? (from TES4Edit) //Offlimits for TESObjectCELL, Dangerous for TESObjectACTV?
	kFormFlags_Compressed           = 0x00040000,   // ?? (from TES4Edit)
	kFormFlags_CantWait             = 0x00080000,   // ?? (from TES4Edit) //For TESObjectCELL can't wait. Unknown for others TESForm
	kFormFlags_IgnoresFriendlyHits  = 0x00100000,
	kFormFlags__SavedInRecord       = 0x000A8EE0,    // flag bits copied to record during serialization (from shadeMe)
};

struct TESForm_vtbl
{
	BaseFormComponent_vtbl _base;
	void * Destroy;	// delete form? pass false to free the object's memory
	void * Unk_05;	// destroy form components
	void * Unk_06;	// call unk01 on form components
	void * LoadForm;
	void * Unk_08;	// calls load form
	void * Unk_09;	// save form
	void * Unk_0A;	// calls save form
	void * Unk_0B;
	void * Unk_0C;
	void * Unk_0D;
	void * Unk_0E;
	void * Unk_0F;
	FVVU4 * MarkAsModified;	// 10
	FVVU4 * ClearModified;
	void * Unk_12;
	void * GetSaveSize;
	void * SaveGame;	// output buffer not passed as param, accessed indirectly via g_createdBaseObjList
	void * LoadGame;
	void * Unk_16;
	void * Unk_17;
	void * Unk_18;
	void * Unk_19;
	void * Unk_1A;
	void * DoPostFixup;	// initialize form after other forms loaded
	void * Unk_1C;
	void * GetDescription;
	void * Unk_1E;
	void * Unk_1F;
	void * Unk_20;	// 20
	void * Unk_21;
	void * Unk_22;
	void * Unk_23;
	void * Unk_24;
	void * SetQuestItem;
	void * Unk_26;
	void * Unk_27;
	void * Unk_28;
	void * Unk_29;
	void * Unk_2A;	// return true if the form is a reference?
	void * Unk_2B;
	void * Unk_2C;
	void * CopyFrom;
	void * Compare;
	void * Unk_2F;
	void * Unk_30;	// 30
	void * Unk_31;
	void * Unk_32;
	void * Unk_33; // related to activate, refr1 is activating refr, refr0 is a reference to this TESForm being activated, seen unk2 == 0
	void * GetName;	// not sure which objects this works on, doesn't seem to work on player or random objects
	void * GetEditorName;	// returns nothing at run-time
	void * SetName; //func 0x36
};

struct _TESForm
{
	_BaseFormComponent _base;
	FormType	typeID;					// 004
	FormFlags	flags;					// 008
										// 0x000002 - something used in flagsCopy
										// 00000040 - something (TESForm_Fn26)
										// 00000400 - quest item
										// 00004000 - temporary?
										// 00010000 - something (TESForm_Fn27)
										// 00020000 - something (TESForm_Fn28)
										// 00080000 - something (sub_464A60)
										// 00100000 - something (sub_464A30)
	UInt32	refID;					// 00C
	TESForm_ModReferenceList	modRefList;	// 010 / 01C	
};

struct TESForm{
	TESForm_vtbl* _vtbl;
	_TESForm _data;
};

/***********TESLeveledList***************/
struct TESLeveledList_vtbl{
	BaseFormComponent_vtbl _base;
};

struct TESLeveledList_Data{
	UInt16		level;
	UInt16		pad;
	union
	{
		TESForm*	form;
		UInt32		formID;	// only valid during load
	};
	UInt16		count;
};

struct TESLeveledList_Entry;
struct TESLeveledList_Entry{
	TESLeveledList_Data* data;
	TESLeveledList_Entry* next;
};

struct _TESLeveledList{
	_BaseFormComponent _base;
	TESLeveledList_Entry list;
	UInt8		chanceNone;	//00C
	UInt8		flags;		//00D
	UInt16		pad00E;
};

struct TESLeveledList{
	TESLeveledList_vtbl* _vtbl;
	_TESLeveledList _data;
};

/***********TESObject***************/
struct TESObject_vtbl{
	TESForm_vtbl _base;
	void* Unk_37;
	void* Unk_38;
	void* Unk_39;
	void* IsObjectAutoCalc;
	void* SetObjectAutoCalc;
	void* Unk_3C;
	void* Unk_3D;
	void* Unk_3E;
	void* Unk_3F;
	void* Unk_40;
	void* Unk_41;
	void* IncrObjectREFCount;
	void* DecrObjectREFCount;
	void* Unk_44;
};

struct _TESObject{
	_TESForm _base;
};

struct TESObject{
	TESObject_vtbl* _vtbl;
	_TESObject _data;
};

/***********TESBoundObject***************/
struct TESBoundObject;
struct BoundObjectListHead
{
	UInt32			boundObjectCount;	// 0
	TESBoundObject	* first;			// 4
	TESBoundObject	* last;				// 8
	UInt32			unkC;				// C
};

struct TESBoundObject_vtbl{
	TESObject_vtbl _base;
	void* Unk_45;
	void* Unk_46;
	void* Unk_47;
};

struct _TESBoundObject{
	_TESObject _base;
	BoundObjectListHead*	head;		// 018 / 24
	TESBoundObject*			prev;		// 01C / 28
	TESBoundObject*			next;		// 020 / 2C
};

struct TESBoundObject{
	TESBoundObject_vtbl* _vtbl;
	_TESBoundObject _data;
};


/***********TESBoundObject***************/
struct TESBoundObject_vtbl{
	TESObject_vtbl _base;
	void* Unk_45;
	void* Unk_46;
	void* Unk_47;
};

struct TESBoundObject;
struct BoundObjectListHead
{
	UInt32			boundObjectCount;	// 0
	TESBoundObject	* first;			// 4
	TESBoundObject	* last;				// 8
	UInt32			unkC;				// C
};

struct _TESBoundObject{
	_TESObject _base;
	BoundObjectListHead*	head;		// 018 / 24
	TESBoundObject*			prev;		// 01C / 28
	TESBoundObject*			next;		// 020 / 2C
};


struct TESBoundObject{
	TESBoundObject_vtbl* _vtbl;
	_TESBoundObject _data;
};
/***********TESBoundAnimObject***************/
struct TESBoundAnimObject_vtbl{
	TESBoundObject_vtbl _base;
};

struct _TESBoundAnimObject{
	_TESBoundObject _base;
};

struct TESBoundAnimObject{
	TESBoundAnimObject_vtbl* _vtbl;
	_TESBoundAnimObject _data;
};

/***********TESSoundFile***************/
struct TESSoundFile_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESSoundFile{
	_BaseFormComponent _base;
	BSStringT	fileName;	// 004
	BSStringT	editorID;	// 00C
};

struct TESSoundFile{
	TESSoundFile_vtbl* _vtbl;
	_TESSoundFile _data;
};

/***********RGBA***************/
struct RGBA {
	UInt8	r;
	UInt8	g;
	UInt8	b;
	UInt8	a;
};

/***********TESFullName***************/
struct TESFullName_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESFullName{
	_BaseFormComponent _base;
	BSStringT name;
};

struct TESFullName{
	TESFullName_vtbl* _vtbl;
	_TESFullName _data;
};

/***********TESModel***************/
struct TESModel_vtbl{
	BaseFormComponent_vtbl _base;
	void*	Destroy;
	FPc*	GetModelPath;
	FVVPc*	SetModelPath;
};

struct _TESModel{
	_BaseFormComponent _base;
	BSStringT	nifPath;	// 004
	float	editorSize;	// 00C 'size' field in editor, from MODB subrecord. Only present for objects defined in Oblivion.esm?
	UInt8	unk10;		// 010
	UInt8	pad11[3];
	void	* unk14;	// 014
};

struct TESModel{
	TESModel_vtbl* _vtbl;
	_TESModel _data;
};

/***********TESScriptableForm***************/
struct TESScriptableForm_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESScriptableForm{
	_BaseFormComponent _base;
	Script	* script;	// 004
	UInt8	unk1;		// 008
	UInt8	pad[3];		// 009
};

struct TESScriptableForm{
	TESScriptableForm_vtbl* _vtbl;
	_TESScriptableForm _data;
};

/***********TESValueForm***************/
struct TESValueForm_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESValueForm{
	_BaseFormComponent _base;
	UInt32	value;
};

struct TESValueForm{
	TESValueForm_vtbl* _vtbl;
	_TESValueForm _data;
};

/***********TESWeightForm***************/
struct TESWeightForm_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESWeightForm{
	_BaseFormComponent _base;
	float	weight;
};

struct TESWeightForm{
	TESWeightForm_vtbl* _vtbl;
	_TESWeightForm _data;
};

/***********TESHealthForm***************/
struct TESHealthForm_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESHealthForm{
	_BaseFormComponent _base;
	UInt32 health;
};

struct TESHealthForm{
	TESHealthForm_vtbl* _vtbl;
	_TESHealthForm _data;
};

/***********TESAttackDamageForm***************/
struct TESAttackDamageForm_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESAttackDamageForm{
	_BaseFormComponent _base;
	UInt16	damage;
	UInt16	unk0;	// bitmask? perhaps 2 UInt8s?
};

struct TESAttackDamageForm{
	TESAttackDamageForm_vtbl* _vtbl;
	_TESAttackDamageForm _data;
};


/***********TESTexture***************/
struct TESTexture_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESTexture{
	_BaseFormComponent _base;
	BSStringT ddsPath;
};

struct TESTexture{
	TESTexture_vtbl* _vtbl;
	_TESTexture _data;
};

/***********TESIcon***************/
struct TESIcon_vtbl{
	TESTexture_vtbl _base;
};

struct _TESIcon{
	_TESTexture _base;
};

struct TESIcon{
	TESIcon_vtbl* _vtbl;
	_TESIcon _data;
};

/***********TESReactionForm***************/
struct TESReactionForm_vtbl{
	BaseFormComponent_vtbl _base;
};

struct TESReactionForm_ReactionInfo{
	TESForm*	target;
	SInt32	reaction;
};

struct tList_TESRF_ReactionInfo;
struct tList_TESRF_ReactionInfo{
	TESReactionForm_ReactionInfo* item;
	tList_TESRF_ReactionInfo* next;
};

struct _TESReactionForm{
	_BaseFormComponent _base;
	tList_TESRF_ReactionInfo	targetList;		// 004
	UInt8	unk2;		// 00C
	UInt8	pad[3];		// 00D
};

struct TESReactionForm{
	TESReactionForm_vtbl* _vtbl;
	_TESReactionForm _data;
};


/***********TESContainer***************/
struct TESContainer_Data
{
	Int32	count;
	TESForm	* type;
};

struct TESContainer_Entry;
struct TESContainer_Entry
{
	TESContainer_Data	* data;
	TESContainer_Entry	* next;
};

struct TESContainer_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESContainer{
	_BaseFormComponent _base;
	UInt8	type;					// 004
	UInt8	typePad[3];				// 005
	TESContainer_Entry	list;					// 008
};

struct TESContainer{
	TESContainer_vtbl* _vtbl;
	_TESContainer _data;
};

/***********TESActorBaseData***************/
struct TESActorBaseData_vtbl{
	BaseFormComponent_vtbl _base;
};

struct TESActorBaseData_FactionListData{
	TESFaction	* faction;
	UInt8		rank;
	UInt8		pad[3];
};

struct tList_TESABD_FactionListData;
struct tList_TESABD_FactionListData{
	TESActorBaseData_FactionListData* data;
	tList_TESABD_FactionListData* next;
};

struct _TESActorBaseData{
	_BaseFormComponent _base;
	UInt32	flags;	// 004 - has flags
						// 00000002 - is essential
	UInt16	baseSpellPts;	// 008
	UInt16	fatigue;	// 00A
	UInt16	barterGold;	// 00C
	SInt16	level;	// 00E absolute level, or level offset if PCLevelOffset flag set
	UInt16	minLevel;	// 010	if PCLevelOffset
	UInt16	maxLevel;	// 012
	UInt32	unk7;	// 014
	tList_TESABD_FactionListData	factionList;	//018 //TODO
};

struct TESActorBaseData{
	TESActorBaseData_vtbl* _vtbl;
	_TESActorBaseData _data;
};

/***********TESAIForm***************/
struct TESAIForm_vtbl{
	BaseFormComponent_vtbl _base;
};

struct TESAIForm_PackageEntry;
struct TESAIForm_PackageEntry{
	TESPackage		* package;
	TESAIForm_PackageEntry	* next;
};

struct _TESAIForm{
	_BaseFormComponent _base;
	UInt8	AISettings[4];			//004
	UInt32	serviceFlags;			//008
	UInt8	trainingSkill;			//00C .. = kActorVal_XXX - kActorVal_Armorer
	UInt8	trainingLevel;			//00D
	UInt16	unk00E;					//00E
	TESAIForm_PackageEntry	packageList;	// 010
};

struct TESAIForm{
	TESAIForm_vtbl* _vtbl;
	_TESAIForm _data;
};

/***********TESRaceForm***************/
struct TESRaceForm_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESRaceForm{
	_BaseFormComponent _base;
	TESRace* race;
};

struct TESRaceForm{
	TESRaceForm_vtbl* _vtbl;
	_TESRaceForm _data;
};

/***********TESEnchantableForm***************/
struct TESEnchantableForm_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESEnchantableForm{
	_BaseFormComponent _base;
	EnchantmentItem* enchantItem;	// 04
	UInt16	enchantment;			// 08 - the maximum charge, valid only for weapons
	UInt16	pad0A;					// 0A
	UInt32	castingType;			// 0C - init by derived class
};

struct TESEnchantableForm{
	TESEnchantableForm_vtbl* _vtbl;
	_TESEnchantableForm _data;
};

/***********TESProduceForm***************/
struct TESProduceForm_vtbl{
	BaseFormComponent_vtbl _base;
};

struct _TESProduceForm{
	_BaseFormComponent _base;
	IngredientItem	* ingredient;		// 004
	UInt8			harvestChance[4];	//008
};

struct TESProduceForm{
	TESProduceForm_vtbl* _vtbl;
	_TESProduceForm _data;
};

/***********TESLeveledList***************/
struct TESLeveledList_vtbl{
	BaseFormComponent_vtbl _base;
};

struct TESLeveledList_ListData{
	UInt16		level;
	UInt16		pad;
	union
	{
		TESForm*	form;
		UInt32		formID;	// only valid during load
	};
	UInt16		count;
};

struct TESLeveledList_ListEntry;
struct TESLeveledList_ListEntry{
	TESLeveledList_ListData* data;
	TESLeveledList_ListEntry* next;
};
	

struct _TESLeveledList{
	_BaseFormComponent _base;
	TESLeveledList_ListEntry	list;		//004
	UInt8		chanceNone;	//00C
	UInt8		flags;		//00D
	UInt16		pad00E;
};

struct TESLeveledList{
	TESLeveledList_vtbl* _vtbl;
	_TESLeveledList _data;
};

/***********TESActorBase***************/
struct TESActorBase_vtbl{
	TESBoundAnimObject_vtbl _base;
	void *	GetCombatStyle;
	void * SetCombatStyle;
	void * GetActorValue;
	void * GetActorValue_F;
	void * SetActorValue_F;
	void * SetActorValue;
	void * ModActorValue_F;
	void * ModActorValue;
};

struct _TESActorBase{
	_TESBoundAnimObject _base;
	// base classes
	TESActorBaseData	actorBaseData;	// 024 
	TESContainer		container;		// 044
	//TODO fill in
	UInt8		spellList[0x68-0x54];		// 054
	UInt8			aiForm[0x80-0x68];			// 068
	UInt8		health[0x88-0x80];			// 080
	UInt8		attributes [0x94-0x88];		// 088
	UInt8		animation[0xA0-0x94];		// 094
	UInt8			fullName[0xAC-0xA0];		// 0A0
	UInt8			model[0xC4-0xAC];			// 0AC
	UInt8	scriptable[0x12];		// 0C4
};

struct TESActorBase{
	TESActorBase_vtbl* _vtbl;
	_TESActorBase _data;
};

struct EffectItem;
/***********EffectItemList***************/
struct EffectItemList_vtbl{
	void*	GetMagickaCost;
	void*	Unk_01;					// returns NULL in base class impl
	void*	GetMasteryLevel;
};

struct EffectItem_Entry;
struct EffectItem_Entry{
	EffectItem* effectItem;
	EffectItem_Entry* next;
};

struct _EffectItemList{
	EffectItem_Entry	effectList;				// 004 BSSimpleList<EffectItem>, from which this class is derived
	UInt32			hostileEffectCount;		// 00C missing from original OBSE class definition
};

struct EffectItemList{
	EffectItemList_vtbl* _vtbl;
	_EffectItemList _data;
};
/***********MagicItem***************/
struct MagicItem_vtbl{
	TESFullName_vtbl _base;
};

struct _MagicItem{
	_TESFullName _base;
	EffectItemList	list;
};

struct MagicItem{
	MagicItem_vtbl* _vtbl;
	_MagicItem _data;
};

/***********MagicItemObject***************/
struct MagicItemObject_vtbl{
	TESBoundObject_vtbl _base;
};

struct _MagicItemObject{
	_TESBoundObject _base;
	MagicItem item;	// 024
};

struct MagicItemObject{
	MagicItemObject_vtbl* _vtbl;
	_MagicItemObject _data;
};

/***********MagicItemForm***************/
struct MagicItemForm_vtbl{
	TESForm_vtbl _base;
};

struct _MagicItemForm{
	_TESForm _base;
	MagicItem item;	// 018
};

struct MagicItemForm{
	MagicItemForm_vtbl* _vtbl;
	_MagicItemForm _data;
};

/***********TESFaction***************/
struct TESFaction_vtbl{
	TESForm_vtbl _base;
};

struct TESFaction_RankData{
	BSStringT		maleRank;
	BSStringT		femaleRank;
	TESTexture	insignia;
};

struct tList_TESFaction_RankData;
struct tList_TESFaction_RankData{
	TESFaction_RankData	* data;
	tList_TESFaction_RankData	* next;
};

struct _TESFaction{
	_TESForm _base;
	// child classes
	TESFullName		fullName;	// 018
	TESReactionForm	reaction;	// 024

	// members
	UInt8		factionFlags;		// 034
	UInt8		pad35[3];			// 035
	float		crimeGoldMultiplier;// 038
	tList_TESFaction_RankData	ranks;				// 03C
};

struct TESFaction{
	TESFaction_vtbl* _vtbl;
	_TESFaction _data;
};

/***********TESSound***************/
struct TESSound_vtbl{
	TESBoundAnimObject_vtbl _base;
};

enum TESSound_Flags{
	kFlags_RandomFrequencyShift = 1,
	//...
	kFlags_Loop					= 1 << 4,
	kFlags_MenuSound			= 1 << 5,
	kFlags_2D					= 1 << 6,
	//...
};

struct _TESSound{
	_TESBoundAnimObject _base;
	// bases
	TESSoundFile	soundFile;	// 024

	// members
	UInt8	minAttenuation;		// 038 not taken directly from CS
	UInt8	maxAttenuation;		// 039 likewise. Different ratios for each
	UInt8	frequencyAdjust;	// 03A
	UInt8	unk9;				// 03B
	TESSound_Flags	flags;				// 03C
	UInt16	staticAttenuation;	// 040 - CS value * -100
	UInt16	unk12;				// 042 related to start/end times
};

struct TESSound{
	TESSound_vtbl* _vtbl;
	_TESSound _data;
};

/***********EnchantmentItem***************/
struct EnchantmentItem_vtbl{
	MagicItemForm_vtbl _base;
};

enum EnchantmentItemType{
	kEnchant_Scroll = 0,
	kEnchant_Staff,
	kEnchant_Weapon,
	kEnchant_Apparel
};
struct _EnchantmentItem{
	_MagicItemForm _base;
	// members
	EnchantmentItemType	enchantType;	// 034 - initialized to kEnchant_Weapon
	UInt32	charge;			// 03C - initialized to -1
	UInt32	cost;			// 040 - initialized to -1
	UInt8	flags040;		// 040
	UInt8	pad041[3];
};

struct EnchantmentItem{
	EnchantmentItem_vtbl* _vtbl;
	_EnchantmentItem _data;
};

/***********TESAmmo***************/
struct TESAmmo_vtbl{
	TESBoundObject_vtbl _base;
};

struct _TESAmmo{
	_TESBoundObject _base;
	// child classes (exposed for easy access)
	TESFullName			fullName;					// 024
	TESModel			model;						// 030
	TESIcon				icon;						// 048
	TESEnchantableForm	enchantable;				// 054
	TESValueForm		value;						// 064
	TESWeightForm		weight;						// 072
	TESAttackDamageForm	attackDmg;					// 080
	float				speed;						// 088
	UInt32				ignoreNormalWeaponResist;	// 092
	UInt32				unk1;						// 096	// seems to be a pointer
	UInt32				unk2;						// 09A	// seems to be flags?  values 0x84 and 0x200
};

struct TESAmmo{
	TESAmmo_vtbl* _vtbl;
	_TESAmmo _data;
};

/***********TESNPC***************/
struct TESNPC_vtbl{
	TESActorBase_vtbl _base;
};

struct TESNPC_Unk
{
	UInt32	unk0;	// 000
	UInt32	unk1;	// 004
	UInt32	unk2;	// 008
	UInt32	unk3;	// 00C
	UInt32	unk4;	// 010
	UInt32	unk5;	// 014
};

struct _TESNPC{ //TODO: lots of classes here
	_TESActorBase _base;
	// base classes
	TESRaceForm		race;	// 0E4
	// members
	UInt8		skillLevels[0x15];	// 0EC
	UInt8		pad101[3];			// 101
	void*	npcClass;			// 104
	TESNPC_Unk			unk1[4];			// 108
	TESNPC_Unk			unk2[4];			// 168
	void*	hair;				// 1C8 
	UInt32		hairLength;			// 1CC
	void*	eyes;				// 1D0
	void* face0;			// 1D4 male and female unknown order
	void* face1;			// 1D8
	UInt32		unk6;				// 1DC
	UInt32		unk7;				// 1E0
	void	* combatStyle;	// 1E4 is NULL if set as DEFAULT in CS
	UInt8		hairColorRGB[4];	//1E8

	UInt32		unk8;				// 1EC
	NiTArray	faceGenUndo;	// 1F0
};

struct TESNPC{
	TESNPC_vtbl* _vtbl;
	_TESNPC _data;
};

/***********AlchemyItem***************/
struct AlchemyItem_vtbl{
	MagicItemObject_vtbl _base;
};

struct _AlchemyItem{
	_MagicItemObject _base;
	TESModel			model;
	TESIcon				icon;
	TESScriptableForm	scriptable;
	TESWeightForm		weight;
	UInt32				goldValue;

	UInt32				moreFlags;
};

struct AlchemyItem{
	AlchemyItem_vtbl* _vtbl;
	_AlchemyItem _data;
};

/***********TESObjectCELL***************/
struct TESObjectCell_CellCoordinates{
	SInt32	x;
	SInt32	y;
};

struct TESObjectCell_LightingData{
	RGBA		ambient;
	RGBA		directional;
	RGBA		fog;
	float		fogNear;
	float		fogFar;
	UInt32		rotXY;
	UInt32		rotZ;
	float		directionalFade;
	float		fogClipDistance;
};

struct TESObjectCELL_ObjectListEntry;
struct TESObjectCELL_ObjectListEntry{
	TESObjectREFR		* refr;
	TESObjectCELL_ObjectListEntry		* next;
};

struct ExtraDataList;

struct TESObjectCELL_vtbl{
	TESForm_vtbl _base;
};

struct _TESObjectCELL{
	_TESForm _base;
	TESFullName fullName;
	UInt8			flags0;			// 024
	UInt8			flags1;			// 025
	UInt8			cellProcessLevel;			// 026
	UInt8			pad27;			// 027
	ExtraDataList	extraData;		// 028 includes ExtraEditorID
	union {
		TESObjectCell_CellCoordinates * coords;		// if exterior
		TESObjectCell_LightingData	* lighting;		// if interior
	};								// 3C
	void	* land;			// 040
	void		* pathGrid;		// 044
	TESObjectCELL_ObjectListEntry	objectList;		//048
	TESWorldSpace	* worldSpace;	// 050
	void			* unk6;			// 054
};

struct TESObjectCELL{
	TESObjectCELL_vtbl* _vtbl;
	_TESObjectCELL _data;
};

/***********TESWorldSpace***************/

struct TESWorldSpace_vtbl{
	TESForm_vtbl _base;
};

struct _TESWorldSpace{
	_TESForm _base;
	// bases
	TESFullName	fullName;	// 018
	TESTexture	texture;	// 024

	// members
	NiTPointerMap	* cellMap;	// 030 - key is coordinates of cell: (x << 16 + y)
	TESObjectCELL	* unk034;			// 034 - pointer to TESObjectCELL (always zero so far)
	NiTPointerMap	map;		// 038 - NiTPointerMap<int, class TESTerrainLODQuadRoot *>
	TESWorldSpace	* worldSpace048;	// 048
	UInt32			unk04C[(0x58 - 0x4C) >> 2];	// 04C
	void		* climate;			// 058
	UInt32			worldFlags;			// 05C
	UInt32			unk060;				// 060
	NiTPointerMap map064;		// 064 - $NiTPointerMap@IPAV?$BSSimpleList@PAVTESObjectREFR@@@@@@
	Character		* character;		// 074
	void			* ptr078;			// 078
	TESWorldSpace	* parentWorldspace;	// 07C
	UInt32			unk080[(0xC0 - 0x80) >> 2];	// 080
	BSStringT			editorID;			// 0C0
	NiTPointerMap map0C8;		// 0C8 - ?$NiTPointerMap@I_N@@
	UInt32			unk0D8[(0xE0 - 0xD8) >> 2];	// 0D8
};

struct TESWorldSpace{
	TESWorldSpace_vtbl* _vtbl;
	_TESWorldSpace _data;
};