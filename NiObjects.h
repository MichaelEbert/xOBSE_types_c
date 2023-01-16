#include "NiNodes.h"

/***********NiAVObject***************/
struct NiAVObject_vtbl{
	NiObjectNET_vtbl _base;
	void* 			UpdatePropertiesAndControllers;	// calls Update on properties and controllers
	void* 			Unk_14;
	void* 			Unk_15;
	void* 			GetObject;
	void* 			Unk_17;
	void* 			Unk_18;	// if(updateProperties) UpdatePropertiesAndControllers(arg); Unk_1D(); Unk_1E();
	void* 			Unk_19;			// update controllers, if kFlag_SelUpdatePropControllers update properties, if(kFlag_SelUpdateTransforms) { Unk_1D(); Unk_1E(); }
	void* 			Unk_1A;			// update controllers, if kFlag_SelUpdatePropControllers update properties, if(kFlag_SelUpdateTransforms) { Unk_1D(); Unk_1E(); }
	void* 			Unk_1B;			// empty
	void* 			Unk_1C;			// empty
	void* 			UpdateTransform;		// update world transform based on local transform and parent ;				// empty
	void* 			Cull;	// accumulate for drawing? NiNode iterates children
	void* 			Unk_20;			// get NiMaterialProperty, pass to arg if found
};

struct _NiAVObject{
	_NiObjectNET _base;
	UInt16						m_flags;				// 018
	UInt8						pad01A[2];				// 01A
	NiObject					* m_parent;				// 01C
	NiSphere					m_kWorldBound;			// 020
	NiMatrix33					m_localRotate;			// 030
	NiVector3					m_localTranslate;		// 054
	float						m_fLocalScale;			// 060
	NiMatrix33					m_worldRotate;			// 064
	NiVector3					m_worldTranslate;		// 088
	float						m_worldScale;			// 094
	NiTList						m_propertyList;			// 098
	NiObject					* m_spCollisionObject;	// 0A8
};

struct NiAVObject{
	NiAVObject_vtbl* _vtbl;
	_NiAVObject _data;
};

/***********NiDynamicEffect***************/
struct NiDynamicEffect_vtbl{
	NiAVObject_vtbl _base;
	void* GetEffectType;
};

struct _NiDynamicEffect{
	_NiAVObject _base;
	UInt8	enable;		// 0AC
	UInt8	pad0AD[3];	// 0AD
	UInt32	unk0B0;		// 0B0 - init'd to monotonically increasing number (uid?)
	UInt32	unk0B4;		// 0B4
	UInt32	unk0B8;		// 0B8 - init'd to 1

	NiTList	affectedNodes;		// 0BC
	NiTList	unaffectedNodes;	// 0CC
};

struct NiDynamicEffect{
	NiDynamicEffect_vtbl* _vtbl;
	_NiDynamicEffect _data;
};

/***********NiLight***************/
struct NiLight_vtbl{
	NiDynamicEffect_vtbl _base;
};

struct _NiLight{
	_NiDynamicEffect _base;
	float	m_fDimmer;	// 0DC
	NiColor	m_kAmb;		// 0E0
	NiColor	m_kDiff;	// 0EC
	NiColor	m_kSpec;	// 0F8
	UInt32	unk104;		// 104
};

struct NiLight{
	NiLight_vtbl* _vtbl;
	_NiLight _data;
};

/***********NiDirectionalLight***************/
struct NiDirectionalLight_vtbl{
	NiLight_vtbl _base;
};

struct _NiDirectionalLight{
	_NiLight _base;
	NiVector3	m_direction;	// 108
};

struct NiDirectionalLight{
	NiDirectionalLight_vtbl* _vtbl;
	_NiDirectionalLight _data;
};

/***********NiNode***************/
struct NiNode_vtbl{
	NiAVObject_vtbl _base;
	void* 			AddObject;
	void* 			RemoveObject;
	void* 			Unk_23;
	void* 			Unk_24;
	void* 			UpdateParentTransforms;	// update world bounds, recurse up parent
	void* 			Unk_26;
};

struct _NiNode{
	_NiAVObject _base;
	NiTArray	m_children;			// 0AC
	NiTList	m_effects;			// 0BC
	NiSphere					m_combinedBounds;	// 0CC
};

struct NiNode{
	NiNode_vtbl* _vtbl;
	_NiNode _data;
};