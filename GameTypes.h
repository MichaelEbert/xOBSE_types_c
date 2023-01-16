typedef unsigned int UInt32;
typedef signed int Int32;
typedef unsigned short UInt16;
typedef unsigned char UInt8;

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
	