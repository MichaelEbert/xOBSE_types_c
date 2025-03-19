#include "GameTypes.h"
#include "NiExtraData.h"

#include "GameTiles.h"
#include "GameMenus.h"
#include "GameForms.h"
#include "GameExtraData.h"
#include "GameObjects.h"
#include "GameMenus.h"

//list types:
/*
TESContainer : first is 0x8, entry is {data,next}
TESLeveledList: first is 0x4, entry is {data, next}
BaseExtraList: *first is 0x4, entry is {vtbl, type, next}


*/

/////////Script///////////////

struct Script_RefVariable{
	BSStringT	name;		// variable name/editorID (not used at run-time)
	TESForm	* form;
	UInt32	varIdx;		// always zero in editor
};

struct Script_RefListEntry;
struct Script_RefListEntry
{
	Script_RefVariable		* var;
	Script_RefListEntry	* next;
};

struct Script_VariableInfo
{
	UInt32			idx;		// 00
	UInt32			pad04;		// 04
	double			data;		// 08
	UInt8			type;		// 10
	UInt8			pad11[3];	// 11
	UInt32			unk14;		// 14
	BSStringT			name;		// 18
};

struct Script_VarInfoEntry;
struct Script_VarInfoEntry
{
	Script_VariableInfo	* data;
	Script_VarInfoEntry	* next;
};

struct ScriptInfo
{
	UInt32	unk0;		// 00
	UInt32	numRefs;	// 04
	UInt32	dataLength;	// 08
	UInt32	varCount;	// 0C
	UInt32	type;		// 10
};

struct Script_vtbl{
	TESForm_vtbl _base;
};

struct _Script{
	_TESForm _base;
	ScriptInfo		info;					// 018 / 024
	char			* text;					// 02C / 038
	void			* data;					// 030 / 03C
	UInt32			unk34;					// 034
	float			questDelayTimeCounter;	// 038      - init'd to fQuestDelayTime, decremented by frametime each frame
	float			secondsPassed;			// 03C      - only if you've modified fQuestDelayTime
	Script_RefListEntry	refList;				// 040 / 040 - ref variables and immediates
	Script_VarInfoEntry	varList;				// 048 / 048 - local variable list
};

struct Script{
	Script_vtbl * _vtbl;
	_Script _data;
};

