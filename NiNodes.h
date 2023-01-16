#include "nitypes.h"
#include "GameTypes.h"

struct NiExtraData;
struct TESForm;

/***********NiRefObject***************/

struct NiRefObject_vtbl{
	void* Destructor;
};

struct _NiRefObject{
	UInt32		m_uiRefCount;	// 004 - name known
};

struct NiRefObject{
	NiRefObject_vtbl* _vtbl;
	_NiRefObject _data;
};

/***********NiObject***************/
struct NiObject_vtbl{
	NiRefObject_vtbl _base;
	void *		GetType;
	void *		Unk_02;	// NiNode returns 'this'
	void *		Unk_03;
	void *		Unk_04;
	void *		Unk_05;
	void *		Copy;
	void *		Load;
	void *		PostLoad;
	void *		FindNodes;	// give NiStream all of the NiNodes we own
	void *		Save;
	void *		Compare;
	void *		DumpAttributes;
	void *		DumpChildAttributes;
	void *		Unk_0E;
	void *		Unk_0F;
	void *		Unk_10;
	void *		Unk_11;
	void *		Unk_12;
};

struct _NiObject{
	_NiRefObject _base;
};

struct NiObject{
	NiObject_vtbl* _vtbl;
	_NiObject _data;
};

/***********NiObjectNET***************/
struct NiObjectNET_vtbl{
	NiObject_vtbl _base;
};

struct _NiObjectNET{
	_NiObject _base;
	const char			* m_pcName;						// 008 - name known
	void	* m_controller;					// 00C TODO:NiTimeController

	// doesn't appear to be part of a class?
	NiExtraData			** m_extraDataList;				// 010
	UInt16				m_extraDataListLen;				// 014
	UInt16				m_extraDataListCapacity;		// 016
};

struct NiObjectNET{
	NiObjectNET_vtbl* _vtbl;
	_NiObjectNET _data;
};

/***********NiTexture***************/
struct NiTexture;

struct NiTexture_vtbl{
	NiObjectNET_vtbl _base;
	void*	GetWidth;
	void*	GetHeight;
};

struct _NiTexture{
	_NiObjectNET _base;
	UInt32			pixelLayout;	// 018
	UInt32			alphaFormat;	// 01C
	UInt32			mipmapFormat;	// 020
	void	* rendererData;	// 024
	NiTexture		* nextTex;		// 028 - linked list updated in ctor/dtor
	NiTexture		* prevTex;		// 02C
};

struct NiTexture{
	NiTexture_vtbl* _vtbl;
	_NiTexture _data;
};
