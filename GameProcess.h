typedef unsigned int UInt32;
typedef signed int Int32;
typedef unsigned short UInt16;
typedef unsigned char UInt8;

struct BaseProcess_vtbl{
	void* functions[0x140];
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