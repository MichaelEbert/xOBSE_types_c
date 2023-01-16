typedef unsigned int UInt32;
typedef signed int Int32;
typedef unsigned short UInt16;
typedef unsigned char UInt8;

enum ExtraDataType
{
	kExtraData_Havok =					0x02,
	kExtraData_Cell3D =					0x03,
	kExtraData_WaterHeight =			0x04,
	kExtraData_CellWaterType =			0x05,
	kExtraData_RegionList =				0x08,
	kExtraData_SeenData =				0x09,
	kExtraData_EditorID =				0x0A,
	kExtraData_CellMusicType =			0x0B,
	kExtraData_CellClimate =			0x0C,
	kExtraData_ProcessMiddleLow =		0x0D,
	kExtraData_EditorCommonDialogData = 0x0E,
	kExtraData_CellCanopyShadowMask =	0x0F,
	kExtraData_DetachTime =				0x10,
	kExtraData_PersistentCell =			0x11,
	kExtraData_Script =					0x12,
	kExtraData_Action =					0x13,
	kExtraData_StartingPosition =		0x14,
	kExtraData_Anim =					0x15,

	kExtraData_UsedMarkers =			0x17,
	kExtraData_DistantData =			0x18,
	kExtraData_RagDollData =			0x19,
	kExtraData_ContainerChanges =		0x1A,
	kExtraData_Worn =					0x1B,
	kExtraData_WornLeft =				0x1C,

	kExtraData_StartLocation =			0x1E,
	kExtraData_Package =				0x1F,
	kExtraData_TresPassPackage =		0x20,
	kExtraData_RunOncePacks =			0x21,
	kExtraData_ReferencePointer =		0x22,
	kExtraData_Follower =				0x23,
	kExtraData_LevCreaModifier =		0x24,
	kExtraData_Ghost =					0x25,
	kExtraData_OriginalReference =		0x26,
	kExtraData_Ownership =				0x27,
	kExtraData_Global =					0x28,
	kExtraData_Rank =					0x29,
	kExtraData_Count =					0x2A,
	kExtraData_Health =					0x2B,
	kExtraData_Uses =					0x2C,
	kExtraData_TimeLeft =				0x2D,
	kExtraData_Charge =					0x2E,
	kExtraData_Soul =					0x2F,
	kExtraData_Light =					0x30,
	kExtraData_Lock =					0x31,
	kExtraData_Teleport =				0x32,
	kExtraData_MapMarker =				0x33,

	kExtraData_LeveledCreature =		0x35,
	kExtraData_LeveledItem =			0x36,
	kExtraData_Scale =					0x37,
	kExtraData_Seed =					0x38,
	kExtraData_NonActorMagicCaster =	0x39,

	kExtraData_CrimeGold =				0x3D,
	kExtraData_OblivionEntry =			0x3E,
	kExtraData_EnableStateParent =		0x3F,
	kExtraData_EnableStateChildren =	0x40,
	kExtraData_ItemDropper =			0x41,
	kExtraData_DroppedItemList =		0x42,
	kExtraData_RandomTeleportMarker =	0x43,
	kExtraData_MerchantContainer =		0x44,

	kExtraData_PersuasionPercent =		0x46,
	kExtraData_CannotWear =				0x47,
	kExtraData_Poison =					0x48,

	kExtraData_LastFinishedSequence =	0x4A,
	kExtraData_SavedMovementData =		0x4B,
	kExtraData_NorthRotation =			0x4C,
	kExtraData_XTarget =				0x4D,
	kExtraData_FriendHitList =			0x4E,
	kExtraData_HeadingTarget =			0x4F,
	kExtraData_BoundArmor =				0x50,
	kExtraData_RefractionProperty =		0x51,
	kExtraData_InvestmentGold =			0x52,
	kExtraData_StartingWorldOrCell =	0x53,

	kExtraData_QuickKey =				0x55,

	kExtraData_EditorRefMoveData =		0x57,
	kExtraData_TravelHorse =			0x58,
	kExtraData_InfoGeneralTopic =		0x59,
	kExtraData_HasNoRumors =			0x5A,
	kExtraData_ExtraSound =				0x5B,
	kExtraData_HaggleAmount =			0x5C,
};

struct BSExtraData_vtbl{
	void* dtor;
	void* Compare;
};

//BSExtraData partially fulfills the tList contract and can use tList::insert, just not
// tList::getItem.

struct BSExtraData;
struct _BSExtraData{
	ExtraDataType		type;		// 004
	UInt8		pad[3];		// 005
	BSExtraData	* next;		// 008
};

struct BSExtraData{
	BSExtraData_vtbl* _vtbl;
	_BSExtraData _data;
};

struct BaseExtraList;
struct BaseExtraList_vtbl{
	void * Destroy;
};

struct _BaseExtraList{
	BSExtraData * m_data;
	UInt8 m_presenceBitfield[0x0C];
};

struct BaseExtraList{
	BaseExtraList_vtbl* _vtbl;
	_BaseExtraList _data;
};

struct ExtraDataList{
	BaseExtraList _base;
};

struct tList_ExtraDataList;
struct tList_ExtraDataList{
	ExtraDataList* item;
	tList_ExtraDataList* next;
};