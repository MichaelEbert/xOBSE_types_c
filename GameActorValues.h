typedef unsigned int UInt32;
typedef signed int Int32;
typedef unsigned short UInt16;
typedef unsigned char UInt8;

#include "GameTypes.h"

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