#include "NiTypes.h"

struct Menu;
struct NiNode;
struct SceneGraph;
struct Script;
struct TESForm;
struct TESObjectREFR;
struct Tile;

struct ScriptEventList_Event{
	TESForm* object;
	UInt32 eventMask;
};

struct ScriptEventList{
	Script		* mf_script;						// 00
	UInt32		m_unk1;							// 04
	void	* m_eventList;					// 08
	void	* m_vars;						// 0C
	void	* m_scriptEffectInfo;	// 10
};
	
/***********InterfaceManager***************/
struct InterfaceManager_vtbl{
};

struct _InterfaceManager{
	SceneGraph*		unk000;							// 000
	SceneGraph*		unk004;							// 004
	UInt32			unk008[(0x018 - 0x008) >> 2];	// 008
	void*			unk018;							// 018 NiDirectionalLight *
	Tile			* cursor;						// 01C
	UInt32			unk020[(0x050 - 0x020) >> 2];	// 020
	bool			debugTextOn;					// 050
	UInt8			unk051[3];
	NiNode*			unk054[(0x064 - 0x054) >> 2];	// 054
	NiNode*			unk064;							// 064 ShadowSceneNode *
	Tile			* menuRoot;						// 068
	Tile			* strings;						// 06C
	NiNode*			unk070;							// 070
	UInt32			unk074;							// 074
	void*			unk078;							// 078 NiAlphaProperty*
	UInt32			unk07C;							// 07C
	Tile			* hudReticule;					// 080
	UInt32			unk084;							// 084
	Tile			* altActiveTile;				// 088 appears to be active tile when activeTile is null and keyboard navigation used
	UInt32			unk08C;							// 08C
	UInt32			unk090;							// 090
	UInt32			unk094;							// 094
	Tile			* activeTile;					// 098 - moused-over tile
	Menu			* activeMenu;					// 09C - menu over which the mouse cursor is placed
	UInt32			unk0A0;							// 0A0
	UInt32			unk0A4;							// 0A4
	UInt32			unk0A8;							// 0A8
	UInt32			unk0AC;							// 0AC
	UInt8			msgBoxButtonPressed;			// 0B0
	UInt8			unk0B1[3];						// 0B1
	void			* unk0B4;						// 0B4 - stores callback for ShowMessageBox() (anything else?)
	UInt32			unk0B8;							// 0B8	
	TESObjectREFR	* debugSelection;				// 0BC
	UInt32			unk0C0[(0x134 - 0x0C0) >> 2];	// 0C0
};

struct InterfaceManager{
	InterfaceManager_vtbl* _vtbl;
	_InterfaceManager _data;
};