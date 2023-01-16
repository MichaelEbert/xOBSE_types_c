#include "GameTypes.h"
#include "NiObjects.h"

struct Menu;

enum TileTypeID{
	TileRect = 0x0385,
	TileImage = 0x0386,
	TileText = 0x0387,
	Tile3D = 0x0388,
	TileMenu = 0x0389,
	TileWindow = 0x038B,
};

TileTypeID FTileTypeID(void);

/***********Tile***************/
struct Tile;

struct Tile_vtbl{
	void*	Destructor;
	void*	Unk_01;//(UInt32 unk0, const char * str, UInt32 unk2);	// initialize? doesn't read data
	void*	Unk_02;	// create render objects?
	FTileTypeID*	GetTypeID;
	FPc*	GetType;
	void*	UpdateField;//(UInt32 valueID, float floatValue, const char* strValue);	//checks for equality, doesn't always update...
	void*	Unk_06;	// does something with tile's NiNode
};


struct NiTLNode_Tile;
struct NiTLNode_Tile{
	NiTLNode_Tile* next;
	NiTLNode_Tile* prev;
	Tile* data;
};

struct NiTList_Tile{
	NITList_vtbl* _vtbl;
	NiTLNode_Tile* start;
	NiTLNode_Tile* end;
	UInt32 numItems;
};

struct TileValueExpressionList;
struct TileValueExpressionList{
	void* expr;
	TileValueExpressionList* next;
};

struct TileValue{
	Tile	* parentTile;	// 00 - Tile * back to owning tile
	float	num;			// 04
	BSStringT	str;			// 08
	TileValueExpressionList	exprList;	// 10
	UInt16	id;				// 18
	UInt8	bIsNum;			// 1A 0 = string, 1 = number
	UInt8	pad1B;			// 1B
};

struct NiTLNode_TileValue;
struct NiTLNode_TileValue{
	NiTLNode_TileValue* next;
	NiTLNode_TileValue* prev;
	TileValue* data;
};

struct NiTList_TileValue{
	NITList_vtbl* _vtbl;
	NiTLNode_TileValue* start;
	NiTLNode_TileValue* end;
	UInt32 numItems;
};

struct _Tile{
	UInt8	unk04;			// 04 - 0 = base tile
	UInt8	unk05;			// 05 - looks like bool, possibly bModified? Seems only used for x, y, width, height changed
	UInt8	unk06;			// 06
	UInt8	pad07;			// 07
	BSStringT	name;			// 08
	Tile	* parent;		// 10
	NiTList_TileValue	valueList;	// 14
	UInt32	unk24;			// 24	// NiNode *
	void	* unk28;		// 28
	UInt32	flags;			// 2C
	NiTList_Tile	childList;		// 30
};

struct Tile{
	Tile_vtbl* _vtbl;
	_Tile _data;
};

/***********TileRect***************/
struct TileRect_vtbl{
	Tile_vtbl _base;
};

struct _TileRect{
	_Tile _base;
	UInt32 unk40;
};

struct TileRect{
	TileRect_vtbl* _vtbl;
	_TileRect _data;
};

/***********TileImage***************/
struct TileImage_vtbl{
	Tile_vtbl _base;
};

struct _TileImage{
	_Tile _base;
	float	unk40;		// 40
	NiNode	* unk44;	// 44
	UInt8	unk48;		// 48
	UInt8	pad49[3];	// 49
};

struct TileImage{
	TileImage_vtbl* _vtbl;
	_TileImage _data;
};

/***********TileText***************/
struct TileText_vtbl{
	Tile_vtbl _base;
};

struct _TileText{
	_Tile _base;
	UInt32	pad40[4];	// 40
	UInt8	unk50;		// 50
	UInt8	pad51[3];	// 51
};

struct TileText{
	TileText_vtbl* _vtbl;
	_TileText _data;
};

/***********TileMenu***************/
struct TileMenu_vtbl{
	TileRect_vtbl _base;
};

struct _TileMenu{
	_TileRect _base;
	Menu* menu; //TODO: Menu class in GameMenus.h
};

struct TileMenu{
	TileMenu_vtbl* _vtbl;
	_TileMenu _data;
};

/***********TileWindow***************/
struct TileWindow_vtbl{
	Tile_vtbl _base;
};

struct _TileWindow{
	_Tile _base;
};

struct TileWindow{
	TileWindow_vtbl* _vtbl;
	_TileWindow _data;
};