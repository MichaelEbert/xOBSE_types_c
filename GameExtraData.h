#include "GameBSExtraData.h"
#include "GameForms.h"
#include "GameAPI.h"
#include "GameTypes.h"
#include "GameObjects.h"
/***********ExtraCount***************/
struct ExtraCount{
	BSExtraData_vtbl *_vtbl;
	_BSExtraData _base;
	SInt16 count;
};

/***********ExtraContainerChanges***************/
struct ExtraContainerChanges_vtbl{
	BSExtraData_vtbl _base;
	void* dtor;
};

struct ExtraContainerChangesEntryData{
	tList_ExtraDataList* extendData;
	SInt32			      countDelta;
	TESForm*              type;
};

struct tlist_ExtraCtrChangesEntryData;

struct tlist_ExtraCtrChangesEntryData{
	ExtraContainerChangesEntryData* item;
	tlist_ExtraCtrChangesEntryData* next;
};

struct ExtraContainerChanges_data{
	tlist_ExtraCtrChangesEntryData* objlist;
	TESObjectREFR* owner;
	float totalWeight;
	float armorWeight;
};

struct _ExtraContainerChanges{
	_BSExtraData _base;
	ExtraContainerChanges_data* data;
};

struct ExtraContainerChanges{
	ExtraContainerChanges_vtbl* _vtbl;
	_ExtraContainerChanges _data;
};

/***********ExtraFollower***************/
struct ExtraFollower_vtbl{
	BSExtraData_vtbl _base;
	void* dtor;
};

struct tList_ExtraFollower_Entry;
struct tList_ExtraFollower_Entry
{
	Character* character;
	tList_ExtraFollower_Entry* next;
};

struct _ExtraFollower{
	_BSExtraData _base;
	tList_ExtraFollower_Entry* followers;
};

struct ExtraFollower{
	ExtraFollower_vtbl* _vtbl;
	_ExtraFollower _data;
};

/***********ExtraHealth***************/
struct ExtraHealth_vtbl{
	BSExtraData_vtbl _base;
	void* dtor;
};

struct _ExtraHealth{
	_BSExtraData _base;
	float health;
};

struct ExtraHealth{
	ExtraHealth_vtbl* _vtbl;
	_ExtraHealth _data;
};

/***********ExtraUses***************/
struct _ExtraUses{
	_BSExtraData _base;
	UInt32 unk0;
};

struct ExtraUses{
	BSExtraData_vtbl* _vtbl;
	_ExtraUses _data;
};

/***********ExtraCharge***************/
struct _ExtraCharge{
	_BSExtraData _base;
	float charge;
};

struct ExtraCharge{
	BSExtraData_vtbl* _vtbl;
	_ExtraCharge _data;
};

/***********ExtraSoul***************/
struct _ExtraSoul{
	_BSExtraData _base;
	UInt8 soul;
	UInt8 padding[3];
};

struct ExtraSoul{
	BSExtraData_vtbl* _vtbl;
	_ExtraSoul _data;
};

/***********ExtraPoison***************/
struct _ExtraPoison{
	_BSExtraData _base;
	AlchemyItem* poison;
};

struct ExtraPoison{
	BSExtraData_vtbl* _vtbl;
	_ExtraPoison _data;
};

/***********ExtraMerchantContainer***************/
struct _ExtraMerchantContainer{
	_BSExtraData _base;
	TESObjectREFR* containerRef;
};

struct ExtraMerchantContainer{
	BSExtraData_vtbl* _vtbl;
	_ExtraMerchantContainer _data;
};

/***********ExtraLock***************/
struct ExtraLockData
{
	UInt32	lockLevel;
	TESKey	* key;
	UInt8	flags;
	UInt8	pad[3];
};

struct ExtraLock_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraLock{
	_BSExtraData _base;
	ExtraLockData* data;
};

struct ExtraLock{
	ExtraLock_vtbl* _vtbl;
	_ExtraLock _data;
};

/***********ExtraRank***************/
struct ExtraRank_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraRank{
	_BSExtraData _base;
	UInt32 rank;
};

struct ExtraRank{
	ExtraRank_vtbl* _vtbl;
	_ExtraRank _data;
};

/***********ExtraOwnership***************/
struct ExtraOwnership_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraOwnership{
	_BSExtraData _base;
	TESForm* owner;
};

struct ExtraOwnership{
	ExtraOwnership_vtbl* _vtbl;
	_ExtraOwnership _data;
};

/***********ExtraGlobal***************/
struct ExtraGlobal_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraGlobal{
	_BSExtraData _base;
	TESGlobal* globalVar;
};

struct ExtraGlobal{
	ExtraGlobal_vtbl* _vtbl;
	_ExtraGlobal _data;
};

/***********ExtraTeleport***************/
struct ExtraTeleport_vtbl{
	BSExtraData_vtbl _base;
};

struct ExtraTeleport_Data{
	TESObjectREFR* linkedDoor;
	float			x; //x, y, z, zRot refer to teleport marker's position and rotation
	float			y;
	float			z;
	float			xRot;		// angles in radians. x generally 0
	float			yRot;		// y generally -0.0, no reason to modify
	float			zRot;
};

struct _ExtraTeleport{
	_BSExtraData _base;
	ExtraTeleport_Data* data;
};

struct ExtraTeleport{
	ExtraTeleport_vtbl* _vtbl;
	_ExtraTeleport _data;
};

/***********ExtraRandomTeleportMarker***************/
struct ExtraRandomTeleportMarker_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraRandomTeleportMarker{
	_BSExtraData _base;
	TESObjectREFR* teleportRef;
};

struct ExtraRandomTeleportMarker{
	ExtraRandomTeleportMarker_vtbl* _vtbl;
	_ExtraRandomTeleportMarker _data;
};

/***********ExtraQuickKey***************/
struct ExtraQuickKey_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraQuickKey{
	_BSExtraData _base;
	UInt8 keyID;		//0 thru 7
	UInt8 pad[3];
};

struct ExtraQuickKey{
	ExtraQuickKey_vtbl* _vtbl;
	_ExtraQuickKey _data;
};

/***********ExtraTrespassPackage***************/
struct ExtraTrespassPackage_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraTrespassPackage{
	_BSExtraData _base;
	void* package;
};

struct ExtraTrespassPackage{
	ExtraTrespassPackage_vtbl* _vtbl;
	_ExtraTrespassPackage _data;
};

/***********ExtraRegionList***************/
struct ExtraRegionList_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraRegionList{
	_BSExtraData _base;
	void* ExtraRegionList; // TODO fix
};

struct ExtraRegionList{
	ExtraRegionList_vtbl* _vtbl;
	_ExtraRegionList _data;
};

/***********ExtraPersistentCell***************/
struct ExtraPersistentCell_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraPersistentCell{
	_BSExtraData _base;
	TESObjectCELL* cell;
};

struct ExtraPersistentCell{
	ExtraPersistentCell_vtbl* _vtbl;
	_ExtraPersistentCell _data;
};

/***********ExtraEnableStateChildren***************/
struct ExtraEnableStateChildren_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraEnableStateChildren{
	_BSExtraData _base;
	tList TESObjectREFRList;
};

struct ExtraEnableStateChildren{
	ExtraEnableStateChildren_vtbl* _vtbl;
	_ExtraEnableStateChildren _data;
};

/***********ExtraScript***************/
struct ExtraScript_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraScript{
	_BSExtraData _base;
	Script* script;
	ScriptEventList * eventList;
};

struct ExtraScript{
	ExtraScript_vtbl* _vtbl;
	_ExtraScript _data;
};

/***********ExtraReferencePointer***************/
struct ExtraReferencePointer_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraReferencePointer{
	_BSExtraData _base;
};

struct ExtraReferencePointer{
	ExtraReferencePointer_vtbl* _vtbl;
	_ExtraReferencePointer _data;
};


/***********ExtraReferencePointer***************/
struct ExtraReferencePointer_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraReferencePointer{
	_BSExtraData _base;
	TESObjectREFR*	reference;	// a persistent reference. ExtraReferencePointer marks an item in an inventory that originated
								// by activating a persistent reference. When the item is dropped, moves the original reference rather
								// than create a dynamic ref
};

struct ExtraReferencePointer{
	ExtraReferencePointer_vtbl* _vtbl;
	_ExtraReferencePointer _data;
};

/***********ExtraLeveledItem***************/
struct ExtraLeveledItem_vtbl{
	BSExtraData_vtbl _base;
};

struct _ExtraLeveledItem{
	_BSExtraData _base;
};

struct ExtraLeveledItem{
	ExtraLeveledItem_vtbl* _vtbl;
	_ExtraLeveledItem _data;
};
