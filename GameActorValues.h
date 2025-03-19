typedef unsigned int UInt32;
typedef signed int Int32;
typedef unsigned short UInt16;
typedef unsigned char UInt8;

#include "GameTypes.h"

enum ActorValues{
	kActorVal_Strength = 0,		// 0x00
	kActorVal_Intelligence,
	kActorVal_Willpower,
	kActorVal_Agility,
	kActorVal_Speed,
	kActorVal_Endurance,		//0x05
	kActorVal_Personality,
	kActorVal_Luck,
	kActorVal_Health,
	kActorVal_Magicka,
	kActorVal_Fatigue,			// 0x0a
	kActorVal_Encumbrance,

	kActorVal_Armorer,
	kActorVal_Athletics,
	kActorVal_Blade,
	kActorVal_Block,			// 0x0f
	kActorVal_Blunt,			// 0x10
	kActorVal_HandToHand,
	kActorVal_HeavyArmor,

	kActorVal_Alchemy,			
	kActorVal_Alteration,
	kActorVal_Conjuration,		// 0x15
	kActorVal_Destruction,
	kActorVal_Illusion,
	kActorVal_Mysticism,
	kActorVal_Restoration,

	kActorVal_Acrobatics,		// 0x1a
	kActorVal_LightArmor,
	kActorVal_Marksman,
	kActorVal_Mercantile,
	kActorVal_Security,
	kActorVal_Sneak,			// 0x1f
	kActorVal_Speechcraft,		// 0x20

	kActorVal_Aggression,
	kActorVal_Confidence,
	kActorVal_Energy,
	kActorVal_Responsibility,
	kActorVal_Bounty,			// 0x25
	kActorVal_Fame,
	kActorVal_Infamy,
	kActorVal_MagickaMultiplier,
	kActorVal_NightEyeBonus,
	kActorVal_AttackBonus,		// 0x2a
	kActorVal_DefendBonus,
	kActorVal_CastingPenalty,
	kActorVal_Blindness,
	kActorVal_Chameleon,
	kActorVal_Invisibility,		// 0x2f
	kActorVal_Paralysis,		// 0x30
	kActorVal_Silence,
	kActorVal_Confusion,
	kActorVal_DetectItemRange,
	kActorVal_SpellAbsorbChance,
	kActorVal_SpellReflectChance,// 0x35
	kActorVal_SwimSpeedMultiplier,
	kActorVal_WaterBreathing,
	kActorVal_WaterWalking,
	kActorVal_StuntedMagicka,
	kActorVal_DetectLifeRange,	// 0x3a
	kActorVal_ReflectDamage,
	kActorVal_Telekinesis,
	kActorVal_ResistFire,
	kActorVal_ResistFrost,
	kActorVal_ResistDisease,	// 0x3f
	kActorVal_ResistMagic,		// 0x40
	kActorVal_ResistNormalWeapons,
	kActorVal_ResistParalysis,
	kActorVal_ResistPoison,
	kActorVal_ResistShock,
	kActorVal_Vampirism,		// 0x45
	kActorVal_Darkness,
	kActorVal_ResistWaterDamage,
	///
	kActorVal_OblivionMax,
	kActorVal_NoActorValue = 256,					// ### incorrect definition, actually 255
	kActorVal_NoActorValue_Proper = 0xFF,			// changing the above value will break existing mods that use it
													// so special-case it for (MGEF, more?)commands that expect the correct value
};

struct ActorValues_Entry{
	UInt32 avCode;
	float value;
};

struct tlist__ActorValues_Entry_Node;

struct tlist__ActorValues_Entry_Node{
	ActorValues_Entry* item;
	tlist__ActorValues_Entry_Node* next;
};

struct tlist__ActorValues_Entry{
	tlist__ActorValues_Entry_Node m_listHead;
};

struct ActorValues{
	tlist__ActorValues_Entry avList;
	ActorValues_Entry	* magicka;		// 08
	ActorValues_Entry	* fatigue;		// 0C
	ActorValues_Entry	** avArray;		// 10 array of more AV modifiers, size 0x12?
};