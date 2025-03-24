#include "GameTypes.h"

struct ExtraContainerChangesEntryData;
struct NiExtraData;
struct NiObject;
struct ActorAnimData;


struct BaseProcess_vtbl{
	FVV* 	Destructor;
	FVV* 	Unk_01 ;
	FU4* 	GetProcessLevel ;	// 0 - high, 3 - low
	void*	Unk_03 ;
	void*	ManagePackProcedure ;
	FVVU4U4* 	Unk_05 ;
	FBoU4U4* 	Unk_06 ;
	void*	SetCurHour ;
	FVV* 	Unk_08 ;
	FBo* 	Unk_09 ;
	FFl* 	GetCurHour ;
	FU4* 	GetCurPackedDate ;
	FVVU4* 	SetCurPackedDate ;
	FU4* 	GetCurDay ;
	FU4* 	GetCurMonth ;
	FU4* 	GetCurYear ;
	FVVU4* 	Unk_10 ;
	FU4* 	Unk_11 ;
	FVVU4* 	Unk_12 ;
	FVV* 	Unk_13 ;
	FU4* 	Unk_14 ;
	FVVU4* 	Unk_15 ;
	FVVU4U4* 	Unk_16 ;
	FVV* 	Unk_17 ;
	FVVU4* 	Unk_18 ;
	FBo* 	Unk_19 ;
	FVVU4* 	Unk_1A ;
	void*	Unk_1B ;
	void*	Unk_1C ;
	FU4U4* 	Unk_1D ;
	FU4U4* 	Unk_1E ;
	void*	Unk_1F ;
	FVVU4U4* 	Unk_20 ;
	void*	Unk_21 ;
	FBo* 	Unk_22 ;
	FVVU4* 	Unk_23 ;
	FVVU4* 	Unk_24 ;
	FVV* 	Unk_25 ;
	FVV* 	UpdateUnk088 ;
	FFl* 	GetUnk088 ;
	FVVFl*	SetUnk088 ;
	FVV* 	Unk_29 ;

	// returns HighProcess::DetectionList::Data* associated with detectedActor. detectionState is one of kDetectionState_XXX enum
	// ###TODO: move some of this stuff out of HighProcess class def so we can forward declare it
	void*  SetDetected ;
	FBo* 	Unk_2B ;
	FVVU4* 	Unk_2C ;

	FVV* 	Unk_2C_1_2 ;	// added in 1.2 patch

	FVVU4* 	Unk_2D ;
	FVVU4* 	Unk_2E ;
	FBo* 	Unk_2F ;
	FVVU4* 	Unk_30 ;
	FBo* 	Unk_31 ;
	FTR* 	GetUnk02C ;
	void*	SetUnk02C ;
	FU4* 	Unk_34 ;
	FVVU4* 	Unk_35 ;
	FVVU4* 	Unk_36 ;
	FU4* 	Unk_37 ;
	FVVU4* 	Unk_38 ;
	FU4U4* 	Unk_39 ;
	FU4U4* 	Unk_3A ;
	FU4U4* 	Unk_3B ;
	void* GetEquippedWeaponData ;
	FU4U4* 	Unk_3D ;
	void* GetEquippedAmmoData ;
	FVVU4* 	Unk_3F ;
	void*	Unk_40 ;
	FBoU4* 	Unk_41 ;
	FBoU4* 	Unk_42 ;
	FBoU4* 	Unk_43 ;
	FBoU4* 	Unk_44 ;
	FU4U4* 	Unk_45 ;
	FU4U4* 	Unk_46 ;
	FU4U4* 	Unk_47 ;
	FU4U4* 	Unk_48 ;
	FU4U4* 	Unk_49 ;
	FU4U4* 	Unk_4A ;
	FU4U4* 	Unk_4B ;
	FU4U4* 	Unk_4C ;
	FBo* 	Unk_4D ;
	FBo* 	Unk_4E ;
	void*	GetUnk084 ;
	void*	SetUnk084 ;
	FBo* 	GetUnk01E ;
	FVVU4* 	SetUnk01E ;
	void*	Unk_53 ;
	void*	SetUnk024 ;
	FVV* 	Unk_55 ;
	FVV* 	Unk_56 ;
	FVV* 	Unk_57 ;
	FVVFl* 	GetUnk028 ;
	FFl* 	SetUnk028 ;
	FVV* 	Unk_5A ;
	FVV* 	Unk_5B ;
	FVV* 	Unk_5C ;
	void*	SetCurrentPackage ;
	void*	SetCurrentPackProcedure ;  //Return eProceudre
	void*	GetCurrentPackProcedure ;
	FPv* GetCurrentPackage ;	// returns MiddleHighProcess::pkg0C0 if not NULL, else BaseProcess::package
	FVVU4* 	Unk_61 ;			// marks ScriptEventList::kEvent_OnPackageDone
	FPv*	GetCharProxy ;	// increfs and returns the proxy (or sets to NULL)
	void*	Unk_63 ;
	FVV* 	Unk_64 ;
	FVV* 	Unk_65 ;
	FVV* 	Unk_66 ;
	FVV* 	Unk_67 ;
	void*	SayTopic ; // unks: 0, 0
	FVV* 	Unk_69 ;	
	FVV* 	Unk_6A ;
	FVV* 	Unk_6B ;
	FVV* 	Unk_6C ;
	FVV* 	Unk_6D ;
	FVV* 	Unk_6E ;
	FVV* 	Unk_6F ;
	FVV* 	Unk_70 ;
	void*	GetLOS ;	// arg0 unused
	FVV* 	Unk_72 ;
	FVV* 	Unk_73 ;
	FVV* 	Unk_74 ;
	FVV* 	Unk_75 ;
	FVV* 	Unk_76 ;
	FVV* 	Unk_77 ;
	FVV* 	Unk_78 ;
	FVV* 	Unk_79 ;
	FVV* 	Unk_7A ;
	FVV* 	Unk_7B ;
	FVV* 	Unk_7C ;
	FVV* 	Unk_7D ;
	FVV* 	Unk_7E ;
	FVV* 	Unk_7F ;
	FVV* 	Unk_80 ;
	FVV* 	Unk_81 ;
	FVV* 	Unk_82 ;
	void*   GetIsAlerted ;
	void*   SetIsAlerted ;
	FVV* 	Unk_85 ;
	FVV* 	Unk_86 ;
	FVV* 	Unk_87 ;
	FVV* 	Unk_88 ;
	FVV* 	Unk_89 ;
	FVV* 	Unk_8A ;
	FVV* 	Unk_8B ;
	FVV* 	Unk_8C ;
	FVV* 	Unk_8D ;
	FVV* 	Unk_8E ;
	FVV* 	Unk_8F ;
	FVV* 	Unk_90 ;
	void* GetUnk020 ;
	void* SetUnk020 ;
	FVV* 	Unk_93 ;
	FVV* 	Unk_94 ;
	FVV* 	Unk_95 ;
	FVV* 	Unk_96 ;
	FVV* 	Unk_97 ;
	FVV* 	Unk_98 ;
	FVV* 	Unk_99 ;
	FVV* 	Unk_9A ;
	FVV* 	Unk_9B ;
	FVV* 	Unk_9C ;
	FVV* 	Unk_9D ;
	FVV* 	Unk_9E ;
	FVV* 	Unk_9F ;
	FVV* 	Unk_A0 ;
	FVV* 	Unk_A1 ;
	FVV* 	Unk_A2 ;
	FVV* 	Unk_A3 ;
	FVV* 	Unk_A4 ;
	FVV* 	Unk_A5 ;
	FVV* 	Unk_A6 ;
	FVV* 	Unk_A7 ;
	FVV* 	Unk_A8 ;
	FVV* 	Unk_A9 ;
	FPv* GetQueuedMagicItem ;	// returns MiddleHighProcess+144
	FVV* 	Unk_AB ;
	FVV* 	Unk_AC ;
	FVV* 	Unk_AD ;
	FVV* 	Unk_AE ;
	FU4* 	GetMovementFlags ;
	FVV* 	Unk_B0 ;
	FVV* 	Unk_B1 ;
	FVV* 	Unk_B2 ;
	FVV* 	Unk_B3 ;
	FVV* 	Unk_B4 ;
	FVV* 	Unk_B5 ;

	// action is one of kAction_XXX. Returns action, return value probably unused.
	void*	SetCurrentAction ;
	FVV* 	Unk_B7 ;
/*	FVV* 	Unk_B8 ;   //OR set this as GetKnockedState
	virtual UInt8	GetKnockedState(void) ; //And this as SetKnockedState(UInt8 knockedState) TODO investigate
	*/
	FVV* 	GetKnockedState ;  //JROush DB report this as HasFatigue/SetHasFatigue
	void*	SetKnockedState  ;
    
	FVV* 	Unk_BA ;
/*	FVV* 	Unk_BB ;

	// arg3 is a multiplier, arg4 appears to be base force to apply
	FVV*	KnockbackActor(Actor* target, float arg1, float arg2, float arg3, float arg4) ;
While OBSE and TESR define this order, VTBL analysis suggest that Unk_BB is actually KnockbackActor
TODO test and control. Seems correct for MiddleHighProcess
	*/
	void*	KnockbackActor ;
	FVV* 	Unk_BC ;   //Seems to be actually be some stuff about skeleton nodes and animations. At least for MiddleHighProcess
	FVV* 	Unk_BD ;
	void*	GetCombatMode ;
	void*	SetCombatMode ;
	void*	GetWeaponOut ;
	void*	SetWeaponOut ;
	FVV* 	Unk_C2 ;
	FPv*	Unk_C3 ;	// returns some pointer
	FVV* 	Unk_C4 ;
	FVV* 	Unk_C5 ;
	FVV* 	Unk_C6 ;
	FVV* 	Unk_C7 ;
	FVV* 	Unk_C8 ;
	FVV* 	Unk_C9 ;
	FVV* 	Unk_CA ;
	FVV* 	Unk_CB ;
	FVV* 	Unk_CC ;
	FVV* 	Unk_CD ;
	FVV* 	Unk_CE ;
	FVV* 	Unk_CF ;
	FVV* 	Unk_D0 ;
	FVV* 	Unk_D1 ;
	FVV* 	Unk_D2 ;
	FVV* 	Unk_D3 ;
	FVV* 	Unk_D4 ;
	FVV* 	Unk_D5 ;
	FVV* 	Unk_D6 ;
	FVV* 	Unk_D7 ;
	FVV* 	Unk_D8 ;
	FVV* 	Unk_D9 ;
	FVV* 	Unk_DA ;
	void*	GetSitSleepState ;
	FVV* 	Unk_DC ;
	void*	GetFurniture ;
	FVV* 	Unk_DE ;
	FVV* 	Unk_DF ;
	FU4* 	GetUnk0D4 ;
	FVV* 	Unk_E1 ;
	FVV* 	Unk_E2 ;
	void*	GetUnk01C ;
	void* SetUnk01C ;
	FVV* 	Unk_E5 ;
	FVV* 	Unk_E6 ;
	FVV* 	Unk_E7 ;
	FVV* 	Unk_E8 ;
	FVV* 	Unk_E9 ;
	void*	GetLightAmount ;
	FVV* 	Unk_EB ;
	void	* GetDetectionState ;	// returns HighProcess::DetectionList::Data *
	FVV* 	Unk_ED ;
	FVV* 	Unk_EE ;
	FVV* 	Unk_EF ;
	FVV* 	Unk_F0 ;
	FVV* 	Unk_F1 ;
	FVV* 	Unk_F2 ;
	FVV* 	Unk_F3 ;
	FVV* 	Unk_F4 ;
	FVV* 	Unk_F5 ;
	FVV* 	Unk_F6 ;
	FVV* 	Unk_F7 ;
	FVV* 	Unk_F8 ;
	FVV* 	Unk_F9 ;
	FVV* 	Unk_FA ;
	FVV* 	Unk_FB ;
	FVV* 	Unk_FC ;
	FVV* 	Unk_FD ;
	FVV* 	Unk_FE ;
	FVV* 	Unk_FF ;
	FVV* 	Unk_100 ;
	FVV* 	Unk_101 ;
	FPv* CreatePath ;
	FPv* GetCurrentPath ;
	FVV* 	Unk_104 ;
	FVV* 	Unk_105 ;
	FVV* 	Unk_106 ;
	FVV* 	Unk_107 ;
	FVV* 	Unk_108 ;
	FVV* 	Unk_109 ;
	FVV* 	Unk_10A ;
	FVV* 	Unk_10B ;
	FVV* 	Unk_10C ;
	FVV* 	Unk_10D ;
	FVV* 	Unk_10E ;
	FVV* 	Unk_10F ;
	FVV* 	Unk_110 ;
	FVV* 	Unk_111 ;
	FVV* 	Unk_112 ;
	FVV* 	Unk_113 ;
	FVV* 	Unk_114 ;
	FVV* 	Unk_115 ;
	FVV* 	Unk_116 ;
	FVV* 	Unk_117 ;
	FVV* 	Unk_118 ;
	FVV* 	Unk_119 ;
	FVV* 	Unk_11A ;
	FVV* 	Unk_11B ;
	FVV* 	Unk_11C ;
	FVV* 	Unk_11D ;
	FVV* 	Unk_11E ;
	FVV* 	Unk_11F ;
	FVV* 	Unk_120 ;
	FVV* 	Unk_121 ;
	FVV* 	Unk_122 ;
	FVV* 	Unk_123 ;
	FVV* 	Unk_124 ;
	FVV* 	Unk_125 ;
	FVV* 	Unk_126 ;
	FVV* 	Unk_127 ;
	FVV* 	Unk_128 ;
	FVV* 	Unk_129 ;
	FVV* 	Unk_12A ;
	FVV* 	Unk_12B ;
	FVV* 	Unk_12C ;
	FVV* 	Unk_12D ;
	FVV* 	Unk_12E ;
	FVV* 	Unk_12F ;
	FVV* 	Unk_130 ;
	FVV* 	Unk_131 ;

	// action type is one of HighProcess::kActionType_XXX
	FTRU4* GetActionTarget ;	
	FVV* 	Unk_133 ;
	FPc*	Unk_134 ;
	FVV* 	Unk_135 ;
	FVV* 	Unk_136 ;
	FVV* 	Unk_137 ;
	FVV* 	Unk_138 ;
	FVV* 	Unk_139 ;
	FVV* 	Unk_13A ;
	FFl* 	GetUnk08C ;
	FVVFl* 	SetUnk08C ;
	FVV* 	Unk_13D ;
	FVV* 	Unk_13E ;
	FVV* 	Unk_13F ;
	FVV* 	Unk_140 ;
};

struct _BaseProcess{
//	void					** _vtbl;				// 000
	void*	editorPackProcedure;	// 004
	void				* editorPackage;		// 008
};

struct BaseProcess{
	BaseProcess_vtbl* _vtbl;
	_BaseProcess _data;
};

/***********ActorProcessManager***************/
struct tList_Actor;
struct tList_Actor{
	Actor* entry;
	tList_Actor* next;
};

struct ActorProcessManager_ActorList{
	tList_Actor head;
	tList_Actor* tail;
};

struct ActorProcessManager{
	ActorProcessManager_ActorList				middleHighActors;		// 00
	ActorProcessManager_ActorList				lowActors0C;			// 0C significantly smaller list than lowActors18. 
													//	  Plausible: actors currently scheduled for low processing
	ActorProcessManager_ActorList				lowActors18;			// 18
	float					unk24;					// 24
	UInt32					unk28;					// 28
	void					* unk2C;				// 2C
	UInt32					unk30;					// 30
	void					* unk34;				// 34
	UInt32					unk38[4];				// 38
	tList		tempEffects;			// 48
	UInt32					unk4C[4];				// 4C
	tList_Actor			highActors;				// 5C
	Actor					* actor64;				// 64
	tList_Actor		* unkNodes[3];			// 68 ##TODO: which lists do these belong to
	UInt32					unk74;					// 74 Possibly not a member. Definitely no more members following this.
};

/***********LowProcess***************/

struct LowProcess_vtbl{
	BaseProcess_vtbl _base;
	FVV*	Unk_141;
	FVV*	Unk_142;
	FVV*	Unk_143;
	FVV*	Unk_144;
	FVVAc*	Alarm;
	FVV*	Unk_146;
	FVV*	Unk_147;
	FVV*	Unk_148;
	FVV*	Unk_149;
	FVV*	Unk_14A;
	FVV*	Unk_14B;
	FVV*	Unk_14C;
	FVV*	Unk_14D;
	FVV*	Unk_14E;
	FVV*	Unk_14F;
	FVV*	Unk_150;
	FVV*	Unk_151;
	FVV*	Unk_152;
	FVV*	Unk_153;
	FVV*	Unk_154;
	FVV*	Unk_155;
	FVV*	Unk_156;
	void*	MountHorse;
	void*	DismoutHorse;
	FVV*	Unk_159;
};

struct _LowProcess{
	_BaseProcess _base;
	float	unk00C;				// 00C - initialized to -1
	float	unk010;				// 010
	float	curHour;			// 014 - initialized to -1
	UInt32	curPackedDate;		// 018 - (year << 13) | (month << 9) | day
	UInt8	unk01C;				// 01C
	UInt8	unk01D;				// 01D
	UInt8	unk01E;				// 01E
	UInt8	isAlerted;				// 01F
	UInt8	unk020;				// 020
	UInt8	pad021[3];			// 021
	TESForm * usedItem;			// 024 for idles like reading book, making potions, etc
	float	unk028;				// 028
	Actor*  follow;				// 02C
	TESObjectREFR   * unk030;	// 030 seen XMarkerHeading refs here
	void	* pathing;			// 034
	UInt32	unk038;				// 038
	UInt32	unk03C;				// 03C
	UInt32	unk040;				// 040
	UInt32	unk044;				// 044
	UInt32	unk048;				// 048
	UInt32	unk04C;				// 04C
	UInt32	unk050;				// 050
	UInt32	unk054;				// 054
	UInt32	unk058;				// 058
	UInt32	unk05C;				// 05C
	UInt32	unk060;				// 060
	UInt32	unk064;				// 064
	UInt32	unk068;				// 068
	UInt32	unk06C;				// 06C
	ActorValues	avDamageModifiers;	// 070
	UInt8	unk084;				// 084
	UInt8	pad085[3];			// 085
	float	unk088;				// 088 - counter in seconds
	float	unk08C;				// 08C
};

struct LowProcess{
	LowProcess_vtbl* _vtbl;
	_LowProcess _data;
};

/***********MiddleLowProcess***************/

struct MiddleLowProcess_vtbl{
	LowProcess_vtbl _base;
	FVV* Unk_15A;
};

struct _MiddleLowProcess{
	_LowProcess _base;
	UInt32			unk090;				// 090
	ActorValues		maxAVModifiers;		// 094
};

struct MiddleLowProcess{
	MiddleLowProcess_vtbl* _vtbl;
	_MiddleLowProcess _data;
};

/***********MiddleHighProcess***************/

struct MiddleHighProcess_vtbl{
	MiddleLowProcess_vtbl _base;
	FVV*	Unk_15B;
	FVV*	Unk_15C;
	FVV*	Unk_15D;
	FVV*	Unk_15E;
	FVV*	Unk_15F;
	FVVAc*	Dialogue;
	void*	RemoveWornItems;
	void*	Travel;
	FVV*	Unk_163;
	FVV*	Unk_164;
};

struct _MiddleHighProcess{
	_MiddleLowProcess _base;
	UInt32				unk0A8;		// 0A8
	UInt32				unk0AC;		// 0AC
	UInt32				unk0B0;		// 0B0
	UInt32				unk0B4;		// 0B4
	UInt32				unk0B8;		// 0B8
	float				unk0BC;		// 0BC
	TESPackage			* currentPackage;	// 0C0 if null, editorPackage applies
	UInt32				unk0C4;		// 0C4
	UInt8				unk0C8;		// 0C8
	UInt8				pad0C9[3];	// 0C9
	char	currentPackProcedure[0xD0-0xCC];		// 0CC
	UInt8				unk0D0;		// 0D0
	UInt8				pad0D0[15];	// 0D1 - never initialized
	UInt32				unk0E0;		// 0E0
	ExtraContainerChangesEntryData* equippedWeaponData;		// 0E4
	ExtraContainerChangesEntryData* equippedLightData;		// 0E8
	ExtraContainerChangesEntryData* equippedAmmoData;			// 0EC
	ExtraContainerChangesEntryData* equippedShieldData;		// 0F0
	UInt8				unk0F4;		// 0F4
	UInt8				unk0F5;		// 0F5
	UInt8				pad0F6[2];	// 0F6
	float				unk0F8;		// 0F8
	UInt32				unk0FC;		// 0FC
	UInt32				unk100;		// 100
	UInt32				unk104;		// 104
	UInt32				unk108;		// 108
	UInt32				unk10C;		// 10C
	UInt32				unk110;		// 110
	UInt8				unk114;		// 114
	UInt8				unk115;		// 115
	UInt8				pad116[2];	// 116
	void	* charProxy;	// 118 - seen bhkCharacterProxy
	SInt8				knockedState;	// 11C
	UInt8				sleepState;		// 11D
	UInt8				pad11E;		// 11E
	UInt8				pad11F;		// 11F
	TESObjectREFR		* furniture;	// 120 Furniture ref NPC is sitting on (may be used for other things)
	UInt8				unk124;		// 124 - init'd to 0x7F
	char				unk128[0x138-0x128];		// 128
	UInt16				unk138;		// 138
	UInt8				pad13A[2];	// 13A
	UInt32				unk13C;		// 13C
	UInt32				unk140;		// 140
	MagicItem			* queuedMagicItem;	// 144 set before calling sub_69AF30 after Addspell cmd, unset upon return
	UInt32				unk148;		// 148
	UInt8				unk14C;		// 14C looks like true if casting, or possibly a casting state
	UInt8				pad14D[3];	// 14D
	UInt32				unk150;		// 150
	float				actorAlpha;	// 154 valid values 0-1
	float				unk158;		// 158
	NiExtraData			* unk15C;	// 15C seen BSFaceGenAnimationData*, reset when modifying character face
	UInt8				unk160;		// 160
	UInt8				unk161;		// 161
	UInt8				pad162[2];	// 162
	UInt32				unk164;		// 164
	UInt8				unk168;		// 168
	UInt8				unk169;		// 169
	UInt8				unk16A;		// 16A
	UInt8				unk16B;		// 16B
	UInt8				unk16C;		// 16C
	UInt8				unk16D;		// 16D
	UInt8				pad16E[2];	// 16E
	UInt32				unk170;		// 170
	tList		* effectList;	// 174
	UInt32				unk178;		// 178
	ActorAnimData		* animData;	// 17C
	UInt8				unk180;		// 180
	UInt8				pad181[3];	// 181
	NiObject			* unk184;	// 184 - seen BSShaderPPLightingProperty
	void				* boundingBox;	// 188
};

struct MiddleHighProcess{
	MiddleHighProcess_vtbl* _vtbl;
	_MiddleHighProcess _data;
};