#include "NiNodes.h"

/*** extra data
 *	name								unk13	unk14
 *	NiExtraData							1		1
 *		TESObjectExtraData				1		1
 *		BSFaceGenAnimationData			1		1
 *		BSFaceGenModelExtraData			1		1
 *		BSFaceGenBaseMorphExtraData		1		1
 *		DebugTextExtraData				1		1
 *		NiStringExtraData				1		1
 *		NiFloatExtraData				1		1
 *			FadeNodeMaxAlphaExtraData	1		1
 *		BSFurnitureMarker				1		1
 *		NiBinaryExtraData				1		1
 *		BSBound							1		1
 *		NiSCMExtraData					0		0
 *		NiTextKeyExtraData				1		1
 *		NiVertWeightsExtraData			1		1
 *		bhkExtraData					1		1
 *		PArrayPoint - does not exist
 *		NiIntegerExtraData				1		1
 *			BSXFlags					1		1
 *		NiFloatsExtraData				1		1
 *		NiColorExtraData				1		1
 *		NiVectorExtraData				1		1
 *		NiSwitchStringExtraData			1		1
 *		NiStringsExtraData				1		1
 *		NiIntegersExtraData				1		1
 *		NiBooleanExtraData				1		1
 */

struct TESObjectREFR;

/***********NiExtraData***************/
struct NiExtraData_vtbl{
	NiObject_vtbl _base;
	void* unk_13;
	void* unk_14;
};

struct _NiExtraData{
	_NiObject _base;
	char* m_pcName;
};

struct NiExtraData{
	NiExtraData_vtbl* _vtbl;
	_NiExtraData _data;
};