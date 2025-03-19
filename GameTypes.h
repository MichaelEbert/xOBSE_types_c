typedef unsigned int UInt32;
typedef signed int Int32;
typedef signed int SInt32;
typedef unsigned short UInt16;
typedef unsigned char UInt8;
typedef signed char SInt8;

struct BSStringT{
	char	* m_data;
	UInt16	m_dataLen;
	UInt16	m_bufLen;
};

struct TESChildCell{
	void** _vtbl; //TODO vtbl
};

/***********tList***************/

struct tList;
struct tList{
	void* item;
	tList* next;
};

/*
ENUMS TO CLEAN UP AFTER IMPORT:
ghidra has all enums be size 4 by default. this project includes several size 1 enums:
GameBSExtraData:
	ExtraDataType
GameForms:
	TESGlobal_type
	TESFaction_Flags
	FormType
	DoorFlags

*/

struct ParamInfo
{
	const char * typeStr;
	UInt32		typeID;		// ParamType
	UInt32		isOptional;	// do other bits do things?
};

/*function types*/
/*
start with F
then:
VV = void
U4 = uint32
U2 = uint16
U1 = uint8
Bo = bool
EL = ExtraDataList
Fl = float
Pc = char*
3F = NiVector3

TF = TESForm
TR = TESObjectREFR*
Ac = Actor
*/
struct TESForm;
struct TESObjectREFR;
struct Actor;
struct NiVector3;

NiVector3* F3F();
bool FBo();
bool FBoU4(UInt32 param);
bool FBoU4U4(UInt32 param0, UInt32 param1);
float FFl();
float FFlU4(UInt32 param);
char* FPc();
UInt32 FU4();
UInt32 FU4U4(UInt32 param);
void FVV();
void FVVAc(Actor* param);
void FVVFl(float param);
void FVVPc(char* param);
void FVVU4(UInt32 param);
void FVVU4U4(UInt32 param0, UInt32 param1);
void* FPv();
TESForm* FTF();
TESObjectREFR* FTR();
TESObjectREFR* FTRU4(UInt32 param);
	