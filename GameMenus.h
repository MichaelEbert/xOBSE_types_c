#include "GameTiles.h"

struct TESObjectREFR;
struct ExtraContainerChangesEntryData;
enum MenuType{
	kMenuType_None = 0,			// for gamemode
	kMenuType_BigFour,			// F1 - F4 menus

	kMenuType_Message = 0x3E9,
	kMenuType_Inventory,
	kMenuType_Stats,
	kMenuType_HUDMain,
	kMenuType_HUDInfo,
	kMenuType_HUDReticle,
	kMenuType_Loading,
	kMenuType_Container,
	kMenuType_Dialog,
	kMenuType_HUDSubtitle,
	kMenuType_Generic,
	kMenuType_SleepWait,
	kMenuType_Pause,
	kMenuType_LockPick,
	kMenuType_Options,
	kMenuType_Quantity,
	kMenuType_Audio,
	kMenuType_Video,
	kMenuType_VideoDisplay,
	kMenuType_Gameplay,
	kMenuType_Controls,
	kMenuType_Magic,
	kMenuType_Map,
	kMenuType_MagicPopup,
	kMenuType_Negotiate,
	kMenuType_Book,
	kMenuType_LevelUp,
	kMenuType_Training,
	kMenuType_BirthSign,
	kMenuType_Class,
	kMenuType_unk407,
	kMenuType_Skills,
	kMenuType_unk409,
	kMenuType_Persuasion,
	kMenuType_Repair,
	kMenuType_RaceSex,
	kMenuType_SpellPurchase,
	kMenuType_Load,
	kMenuType_Save,
	kMenuType_Alchemy,
	kMenuType_Spellmaking,
	kMenuType_Enchantment,
	kMenuType_EffectSetting,
	kMenuType_Main,
	kMenuType_Breath,
	kMenuType_QuickKeys,
	kMenuType_Credits,
	kMenuType_SigilStone,
	kMenuType_Recharge,
	kMenuType_unk41A,
	kMenuType_TextEdit,

	kMenuType_Max
};

/***********Menu***************/
struct Menu_vtbl{
	void* Destructor;		// pass false to free memory
	void* SetField;
	void* Unk_02;	// show menu?
	void* HandleClick; // buttonID = <id> trait defined in XML
	void* HandleMouseover;	//called on mouseover, activeTile is moused-over Tile
	void* Unk_05;
	void* Unk_06;
	void* Unk_07;
	void* Unk_08;
	void* Unk_09;
	void* Unk_0A;
	void* Unk_0B;
	void* HandleKeyboardInput;	//for keyboard shortcuts, return true if handled
	void* GetID;
	void* Unk_0E;
};

struct _Menu{
	TileMenu* tile;		// 04
	UInt32	unk08;		// 08
	UInt32	unk0C;		// 0C
	UInt32	unk10;		// 10
	UInt32	unk14;		// 14
	UInt32	unk18;		// 18
	UInt32	unk1C;		// 1C - initialized to 1
	UInt32	id;			// 20 - uninitialized
	UInt32	unk24;		// 24 - initialized to 4, is 8 if enabled?
};

struct Menu{
	Menu_vtbl* _vtbl;
	_Menu _data;
};

/***********MessageMenu***************/
struct MessageMenu_vtbl{
	Menu_vtbl _base;
};

struct _MessageMenu{
	_Menu _base;
	TileRect		* backGround;		// 28
	TileText		* messageText;		// 2C
	TileRect		* focusBox;			// 30
	TileImage		* buttons[10];		// 34..58 each has a child TileText
	void			* buttonCallback;	// 5C
	UInt8			minButtonIndex;		// 60
	UInt8			pad61[3];			// 61
};

struct MessageMenu{
	MessageMenu_vtbl* _vtbl;
	_MessageMenu _data;
};

/***********QuantityMenu***************/
struct QuantityMenu_vtbl{
	Menu_vtbl _base;
};

struct _QuantityMenu{
	_Menu _base;
	TileRect		* background;		// 28
	TileText		* display_text;		// 2C
	TileImage		* quantity_scroll;	// 30 user7 trait of this tile holds currently selected quantity
	TileImage		* horizontal_scroll_marker;	// 34
	TileImage		* button_okay;		// 38
	TileImage		* button_cancel;	// 3C
	UInt32			maxQuantity;		// 40
	UInt32			unk44;				// 44 is 0x33 if created from ContainerMenu (hard-coded value) - why 0x33?
	UInt32			unk48;				// 48 always == maxQuantity? Not currently selected quantity
	Tile			* itemTile;			// 4C Tile of selected item in container menu
	UInt32			unk50;				// 50 init'd to arg3 of CreateQuantityMenu()
	UInt32			unk54;				// 54
};

struct QuantityMenu{
	QuantityMenu_vtbl* _vtbl;
	_QuantityMenu _data;
};

/***********InventoryMenu***************/
struct InventoryMenu_vtbl{
	Menu_vtbl _base;
};

struct _InventoryMenu{
	_Menu _base;
	TileRect		* focusBox;			//028
	TileRect		* listContents;		//02C
	TileRect		* scrollBar;		//030
	TileImage		* scrollMarker;		//034
	TileRect		* invP4P5Header;	//038 - ?
	UInt32			unk03C;				//03C
	UInt8			filterType;			//040 init'd to 1F (all), 1=weapons, 2=armor, ...
	UInt8			pad041[3];
	UInt8			unk044;				//044 init'd to FF
	UInt8			unk045[3];
	float			unk048;				//048
	UInt32			unk04C;				//04C
	ExtraContainerChangesEntryData*			selectedItem;				//050
	UInt32			unk054;				//054 uninitialized
};

struct InventoryMenu{
	InventoryMenu_vtbl* _vtbl;
	_InventoryMenu _data;
};

/***********ContainerMenu***************/
struct ContainerMenu_vtbl{
	Menu_vtbl _base;
};

struct _ContainerMenu{
	_Menu _base;
	TileImage			* scrollBar;		//028
	TileImage			* scrollMarker;		//02C
	TileRect			* listContents;		//030
	TileRect			* focusBox;			//034
	TileRect			* invP4P5Header;	//038
	TileRect			* selectedItemTile;	//03C user11 = idx of item in inventory/container
	UInt8				filterType;			//040
	UInt8				pad041[3];
	TESObjectREFR		* refr;				//044
	UInt32				unk048;				//048
	UInt32				unk04C;				//04C
	float				unk050;				//050
	UInt8				unk054;				//054
	UInt8				bTransactionInProgress;	// set true after first transaction confirmed by player. ###TODO: reset when?
	UInt8				unk056;				// may be padding
	UInt8				pad057;
	UInt32				unk058;				//058
	UInt32				unk05C;				//05C
	UInt8				unk060;				//060
	bool				isBarter;			//	 1 if bartering with merchant
	UInt8				unk062;
	UInt8				unk063;
	bool				isContainerContents; //init'd to 1. 0 when switched to player's inventory view
	UInt8				pad065[3];
};

struct ContainerMenu{
	ContainerMenu_vtbl* _vtbl;
	_ContainerMenu _data;
};