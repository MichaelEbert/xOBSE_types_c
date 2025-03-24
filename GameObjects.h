typedef unsigned int UInt32;
typedef signed int Int32;
typedef unsigned short UInt16;
typedef unsigned char UInt8;

#include "GameForms.h"
#include "GameBSExtraData.h"
#include "GameActorValues.h"
#include "GameProcess.h"

//OBSE doesn't define this
struct DialoguePackage;

//TODO:
struct ActorAnimData;
struct TESTopic;

/***********MagicCaster***************/
struct MagicCaster_vtbl{
	void* AddAbility;
	void* AddDisease;
	void* AddObjectEnchantment;
	void* 	FindTouchTarget;
	void* 	PlayTargettedCastAnim;
	void* 	PlayCastingAnim;
	void* 	ApplyMagicItemCost;

	// looks like returns true if can use magicItem, filling out type (and arg1 is magicka cost?)
	FBo* IsMagicItemUsable;
	FTR*	GetParentRefr;
	void* GetMagicNode;	// looks up "magicnode" node in caster's NiNode
	void*	AddEffectToSelf;
	void*	GetSpellEffectiveness;
	void* GetActiveMagicItem;		// calls through to MiddleHighProcess
	void*	SetActiveMagicItem;
	void*	GetCastingTarget;
	void*	SetCastingTarget;
	void*	CreateActiveMagicEffect;	// activate effect?
};

struct _MagicCaster{
	NiNode* magicNode;
	UInt32 state;
};

struct MagicCaster{
	MagicCaster_vtbl* _vtbl;
	_MagicCaster _data;
};

/***********MagicTarget***************/
struct MagicTarget_vtbl{
	void* Destructor;
	FTR* GetParent;
	void* GetEffectList;
	//TODO incomplete VTBL
};

struct _MagicTarget{
	UInt8	unk04;		// 004
	UInt8	pad05[3];
};

struct MagicTarget{
	MagicTarget_vtbl* _vtbl;
	_MagicTarget _data;
};

/***********TESObjectREFR***************/

void func_additem_t(TESForm* item, ExtraDataList* xDataList, UInt32 count);

struct TESObjectREFR_vtbl{
	TESForm_vtbl _base;
	void* Unk_37;
	FBo* CanCastShadows;	// 38
	void* SetCanCastShadows;
	void* IsProjectile;
	void* GetScale;
	void* GetStartingAngle;
	void* GetStartingPos;
	void* MoveInitialPosition;
	void* Unk_3F;
	void* RemoveItem;
	void* Unk_41;
	void* Unk_42;
	void* Unk_43;
	void* Unk_44;
	func_additem_t* AddItem;
	void* Unk_46;
	void* Unk_47;
	void* Unk_48;
	void* GetMagicTarget;
	void* Unk_4A;
	void* Unk_4B;
	void* Unk_4C;
	void* Unk_4D;
	void* Unk_4E;
	void* Unk_4F;
	void* Unk_50;	// 50
	void* Unk_51;
	void* Unk_52;			// inits animation-related data, and more
	void* GenerateNiNode;
	void* Set3D;
	void* 	GetNiNode;
	void* Unk_56;
	void* Unk_57;
	void* Unk_58;
	void* Unk_59;
	void* Unk_5A;
	void* Unk_5B;
	FTF* GetBaseForm;	// returns type this object references
	F3F* GetPos;
	void* Unk_5E;
	void* Unk_5F;
	void* Unk_60;	// 60
	void* Unk_61;
	void* Unk_62;
	void* GetSleepState;
	FBo* IsActor;
	void* ChangeCell;
	FBo* IsDead;
	void* Unk_67;
	void* Unk_68;
	void* Unk_69;
};

struct NiNode;

//TSEObjectREFR is actually multiple inherited from TESMemContextForm
// the baseForm at 1C is a TESMemContextForm
// TESChildCell inherit at 18h

struct _TESObjectREFR{
	_TESForm _base;
	TESChildCell	childCell;		// 018
	TESForm	* baseForm;				// 01C
										// U8(typeInfo + 4) == 0x23 is true if the object is a character
	float	rotX, rotY, rotZ;		// 020 - either public or accessed via simple inline accessor common to all child classes
	float	posX, posY, posZ;		// 02C - seems to be private
	float	scale;					// 038
	NiNode	* niNode;				// 03C
	TESObjectCELL	* parentCell;	// 040
	BaseExtraList	baseExtraList;	// 044
};

struct TESObjectREFR{
	TESObjectREFR_vtbl* _vtbl;
	_TESObjectREFR _data;
};


/***********MobileObject***************/

struct MobileObject_vtbl{
	TESObjectREFR_vtbl _base;
	void* Unk_6A;
	void* Unk_6B;
	void* Unk_6C;
	void* Move;
	//void* Jump; why is this commented out in xobse. where did jump go.
	void* FallImpact;
	void* Unk_6F;
	void* Unk_70;
	void* Unk_71;
	void* Unk_72;
	void* Unk_73;
	void* SetPosition;
	void* Unk_75;
	void* Unk_76;
	void* Unk_77;
	void* GetZRotation;
	void* Unk_79;
	void* Unk_7A;
	void* Unk_7B;
	void* Unk_7C;
	void* GetJumpScale;
	void* IsDead;
	void* Unk_7F;
	void* Unk_80;
};

struct _MobileObject{
	_TESObjectREFR _base;
	BaseProcess* process;
};

struct MobileObject{
	MobileObject_vtbl* _vtbl;
	_MobileObject _data;
};

/***********Actor***************/
struct Actor_vtbl{
	MobileObject_vtbl _base;
	void* GetFame; // 81
	void* GetInfamy;	// 82
	void* Resurrect; //If unk3 is 1, it try to use the bhkProxyController. MAybe relative to animations? unk3 == 0, recreate the processes
	void* Unk_84;
	void* Unk_85;
	void* Unk_86;
	void* Unk_87;
	void* ApplyDamage;
	void* GetDisposition; //
 	void* ProcessControl;	// handles input for PlayerCharacter
	void* Unk_8B;
	void* SetPackageDismount;
	void* Unk_8D;
	void* Unk_8E;
	void* Unk_8F;
	void* OnAlarmAttack;	// 90 tries to send alarm when 'this' attacks victim
	void* Unk_91;
	void* Unk_92;	// SendTrespassAlarm
	void* Unk_93;
	void* Unk_94;
	void* Unk_95;
	void* Unk_96;
	void* IsOverEncoumbered;   //Possible incorrect decompilation. 
	void* HasVampireFed;
	void* SetVampireHasFed;
	void* Unk_9A;  //GetBirthsign?
	void* GetHandReachDistance;   
	void* SetTransparency;  //Can create or delete ExtraRefractionProperty, set something on the NiAvObject, call a base object vtbl function
	void* Unk_9D;
	void* Unk_9E;
	void* Unk_9F;
	void* Unk_A0;	// A0
	void* GetActorValue;								// current, cumulative value
	void* GetAV_F;
	void* SetAV_F;							// base value
	void* SetActorValue;
	void* ModMaxAV_F;
	void* ModMaxAV;
	void* ApplyScriptAVMod_F;	// script cmds Mod/ForceAV
	void* ApplyScriptAVMod;
	void* DamageAV_F;			// modifier <= 0, console ModAV cmd, damage health, etc
	void* DamageAV;
	void* ModBaseAV_F;
	void* ModBaseAV;
	void* Unk_AD;
	void* Unk_AE;
	void* Unk_AF;
	void* Unk_B0;	// B0
	void* some_removeitem_thing;  //some_removeitem_thing
	void* Unk_B2;
	void* Unk_B3; // called after Activate by TESForm::Unk33()
	void* Unk_B4;
	void* Unk_B5;
	void* Unk_B6;
	void* Unk_B7;	// AddSpell?
	void* Unk_B8;	// RemoveSpell?
	void* Unk_B9;
	void* Unk_BA;
	void* Unk_BB;
	void* Unk_BC;
	void* Unk_BD;
	void* Unk_BE;
	void* Unk_BF;
	void* Unk_C0;	// C0
	void* Unk_C1;
	void* Unk_C2;
	void* Unk_C3;
	void* ManageAlarm;  //TODO check
	void* Unk_C5;
	void* Unk_C6;
	void* Unk_C7;
	void* AddPackageWakeUp;
	void* Unk_C9;
	void* Unk_CA;
	void* Unk_CB;
	void* GetCombatController;
	void* IsInCombat;
	void* GetCombatTarget;
	void* Unk_CF;
	void* Unk_D0;	// D0
	void* Unk_D1;
	void* Unk_D2;
	void* Unk_D3;
	void* IsYielding;
	void* Unk_D5;
	void* Unk_D6;
	void* Unk_D7;
	void* Unk_D8;
	void* Unk_D9;
	void* Unk_DA;
	void* Unk_DB;
	void* Unk_DC;
	void* Unk_DD;
	void* Unk_DE;
	void* Unk_DF;
	void* GetMountedHorse;	// E0 returns this->horseOrRider, only for Character
	void* Unk_E1;
	void* Unk_E2;
	void* Unk_E3;
	void* Unk_E4;
	void* Unk_E5;
	void* Unk_E6;
	void* ModExperience;
	void* Unk_E8;
	void* Unk_E9;
	void* Unk_EA;
	void* AttackHandling;	// args all null for melee attacks
	void* Unk_EC;
	void* Unk_ED;	// something with blocking
	void* OnHealthDamage;
};

struct Actor_PowerListData {
	SpellItem	* power;
	float		timer;		// init'ed to (3600 / TimeScale) * 24 <- TimeScale is a TESGlobal
};

struct Actor_PowerListEntry;
struct Actor_PowerListEntry{
	Actor_PowerListData* data;
	Actor_PowerListEntry* next;
};

struct Actor_DispositionModifier{
		Int32			  modifier;					// 00 - Can be positive or negative. Linear based on previous interactions
		TESObjectREFR	* refr;						// 04 - This is always the player
};

struct Actor;

struct _Actor{
	_MobileObject _base;
	MagicCaster		magicCaster;					// 05C
	MagicTarget		magicTarget;					// 068

	UInt32			unk070[(0x07C - 0x070) >> 2];	// 070
	Actor			* unk07C;						// 07C
	UInt32			unk080[(0x088 - 0x080) >> 2];	// 080
	ActorValues		avModifiers;					// 088
	Actor_PowerListEntry  greaterPowerList;				// 09C
	Actor_DispositionModifier * dispositionModifier;      // 0A4 - This is created after the player has increased/decreased the Actor's disposition
	UInt32          unk0A8;                         // 0A8	
	float			unk0AC;							// 0AC
	UInt32			DeadState;						// 0B0
	UInt32			unk0B4[(0x0CC - 0x0B4) >> 2];	// 0B4
	TESObjectREFR	* unk0CC;						// 0CC
	UInt32			unk0D0;							// 0D0
	Actor			* horseOrRider;					// 0D4 - For Character, currently ridden horse
														 //- For horse (Creature), currently riding Character
	UInt32			unk0D8[(0x0E4 - 0x0D8) >> 2];	// 0D8
	Actor			* unk0E4;						// 0E4
	UInt32			unk0E8[(0x104 - 0x0E8) >> 2];	// 0E8
};

struct Actor{
	Actor_vtbl* _vtbl;
	_Actor _data;
};

struct Character{
	Actor_vtbl* _vtbl;
	_Actor _data;
};

/***********PlayerCharacter***************/
typedef Actor_vtbl PlayerCharacter_vtbl;

struct Creature;

enum PlayerCharacterMiscStat
	{
		kMiscStat_DaysInPrison = 0,
		kMiscStat_DaysPassed,
		kMiscStat_SkillIncreases,
		kMiscStat_TrainingSessions,
		kMiscStat_LargestBounty,
		kMiscStat_CreaturesKilled,
		kMiscStat_PeopleKilled,
		kMiscStat_PlacesDiscovered,
		kMiscStat_LocksPicked,
		kMiscStat_LockpicksBroken,
		kMiscStat_SoulsTrapped,	// 10
		kMiscStat_IngredientsEaten,
		kMiscStat_PotionsMade,
		kMiscStat_OblivionGatesShut,
		kMiscStat_HorsesOwned,
		kMiscStat_HousesOwned,
		kMiscStat_StoresInvestedIn,
		kMiscStat_BooksRead,
		kMiscStat_SkillBooksRead,
		kMiscStat_ArtifactsFound,
		kMiscStat_HoursSlept,	// 20
		kMiscStat_HoursWaited,
		kMiscStat_DaysAsAVampire,
		kMiscStat_LastDayAsAVampire,
		kMiscStat_PeopleFedOn,
		kMiscStat_JokesTold,
		kMiscStat_DiseasesContracted,
		kMiscStat_NirnrootsFound,
		kMiscStat_ItemsStolen,
		kMiscStat_ItemsPickpocketed,
		kMiscStat_Trespasses,	// 30
		kMiscStat_Assaults,
		kMiscStat_Murders,
		kMiscStat_HorsesStolen,

		kMiscStat_Max			// 34
	};

struct _PlayerCharacter{
	_Actor _base;
	UInt32		unk104[(0x118 - 0x104) >> 2];				// 104
	DialoguePackage	* dialoguePackage;						// 118
	UInt32		unk11C[(0x130 - 0x11C) >> 2];				// 11C
	float		skillExp[21];								// 130	current experience for each skill
	UInt32		majorSkillAdvances;							// 184
	UInt32		skillAdv[21];								// 188 number of advances for each skill
	UInt8		bCanLevelUp;								// 1DC
	UInt8		unk1DD[3];									// 1DD
	Creature	* lastRiddenHorse;							// 1E0
	UInt32		unk1E4[(0x204 - 0x1E4) >> 2];				// 1E4
	float		maxAVModifiers[0x48];		// 204
	float		scriptAVModifiers[0x48];	// 324
    float       health;                                    // 444
    float       magicka;                                   // 448
    float       stamina;                                   // 44C
    UInt32      unk450[(0x570 - 0x450) >> 2];             // 450
    TESObjectREFR	* lastActivatedLoadDoor;	// 570 - most recently activated load door
	UInt32		unk574[(0x588 - 0x574) >> 2];	// 574
	UInt8		isThirdPerson;					// 588
	UInt8		pad589[2];						// 589
	UInt8       isRunning;                      // 58B According to EchoEclipse, who named it shouldAutoRun
	UInt32		unk58C[(0x5B0 - 0x58C) >> 2];	// 58C
	void		* unk5B0;						// 5B0 - freed when running SetInCharGen 0
	UInt8		** attributeBonuses;			// 5B4
	UInt16		unk5B8;							// 5B8
	UInt8		unk5BA;
	UInt8		unk5BB;
	UInt32		trainingSessionsUsed;			// 5BC reset on level-up
	UInt32		unk5C0;							// 5C0
	UInt32		unk5C4;							// 5C4
	UInt32		unk5C8;							// 5C8
	ActorAnimData	* firstPersonAnimData;		// 5CC
	NiNode		* firstPersonNiNode;			// 5D0
	float		unk5D4;							// 5D4
	UInt32		unk5D8;							// 5D8
	UInt32		unk5DC;							// 5DC
	UInt32		unk5E0;							// 5E0
	TESTopic	* unk5E4;						// 5E4
	UInt32		unk5E8;							// 5E8
	tList knownQuestStageItems;	// 5EC; type is <QuestStageItem>
	TESQuest	* activeQuest;					// 5F4
	tList activeQuestTargets;	// 5F8 targets whose conditions evaluate to true, updated each frame by HUDMainMenu::Update()
	UInt32		unk600[(0x610 - 0x600) >> 2];	// 600
	UInt8		unk610;							// 610
	UInt8		isAMurderer;					// 611
	UInt8		pad612[2];						// 612
	UInt32		unk614[(0x624 - 0x614) >> 2];	// 614
	MagicItem	* activeMagicItem;				// 624
	TESObjectBOOK	* book;						// 628 //Last acitvated/read book?
	UInt32		unk62C[(0x644 - 0x62C) >> 2];	// 62C
	BirthSign	* birthSign;					// 644
	UInt32		unk648[(0x650 - 0x648) >> 2];	// 648
	TESClass	* wtfClass;						// 650 - this is not the player class! use OBLIVION_CAST(this, TESForm, TESNPC)->npcClass
	UInt32		unk654;							// 654
	PlayerCharacterMiscStat		miscStats[34];		// 658
	AlchemyItem	* alchemyItem;					// 6E0
	UInt8		bVampireHasFed;					// 6E4 returned by vtbl+260, set by vtbl+264
	UInt8		isInCharGen;					// 6E5
	UInt8		pad6E6[2];						// 6E6
	TESRegion	* region;						// 6E8
	UInt32		unk6EC[(0x734 - 0x6EC) >> 2];	// 6EC
	float		gameDifficultyLevel;			// 734 ranges from -1 to 1
	UInt32		unk738[(0x7A4 - 0x738) >> 2];	// 738
	float		requiredSkillExp[21];			// 7A4 total amt of exp needed to increase each skill
	UInt32		unk7F8;							// 7F8
	UInt32		unk7FC;							// 7FC
};

struct PlayerCharacter{
	PlayerCharacter_vtbl* _vtbl;
	_PlayerCharacter _data;
};

/***********Creature***************/
typedef Actor_vtbl Creature_vtbl;
typedef _Actor _Creature;
struct Creature{
	Creature_vtbl* _vtbl;
	_Creature _data;
};
/***********ArrowProjectile***************/
struct ArrowProjectile_vtbl{
	MobileObject_vtbl _base;
};

struct ArrowProjectile_CollisionData{
	// not sure if this data is generated for collisions with immobile objects too, or if struct is unique to ArrowProjectile (probably not)
	float			unk00[9];	// 00 presumably a matrix or set of 3 3-dimensional vectors
	TESObjectREFR	* refr;		// 24 what it hit
	NiNode			* ninode;	// 28 seen "Bip01 Spine" for Creature
	float			unk2C[9];	// 2C again
};

struct _ArrowProjectile{
	_MobileObject _base;
	ArrowProjectile_CollisionData	* unk05C;		//05C
	UInt32			unk060;			//060
	float			unk064;			//064
	float			elapsedTime;	//068
	float			speed;			//06C - base speed * GMST fArrowSpeedMult
	float			unk070;			//070
	float			unk074;			//074
	Actor			* shooter;		//078;
	EnchantmentItem	* arrowEnch;	//07C
	EnchantmentItem	* bowEnch;		//080
	AlchemyItem		* poison;		//084
	float			unk088;			//088
	float			unk08C;			//08C
	float			unk090;			//090
	UInt32			unk094;			//094
	UInt32			unk098;			//098
};

struct ArrowProjectile{
	ArrowProjectile_vtbl* _vtbl;
	_ArrowProjectile _data;
};