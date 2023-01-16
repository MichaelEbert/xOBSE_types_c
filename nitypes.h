typedef unsigned int UInt32;
typedef unsigned short UInt16;
typedef unsigned char UInt8;

struct NiRTTI;

// 8
struct NiRTTI
{
	const char	* name;
	NiRTTI		* parent;
};

// C
struct NiVector3
{
	float	x, y, z;
};

// 10 - always aligned?
struct NiVector4
{
	float	x, y, z, w;
};

// 10 - always aligned?
struct NiQuaternion
{
	float	x, y, z, w;
};

// 24
struct NiMatrix33
{
	float	data[9];
};

// 34
struct NiTransform
{
	NiMatrix33	rotate;		// 00
	NiVector3	translate;	// 24
	float		scale;		// 30
};

// 10
struct NiSphere
{
	float	x, y, z, radius;
};

// 1C
struct NiFrustum
{
	float	l;			// 00
	float	r;			// 04
	float	t;			// 08
	float	b;			// 0C
	float	n;			// 10
	float	f;			// 14
	UInt8	o;			// 18
	UInt8	pad19[3];	// 19
};

// 10
struct NiViewport
{
	float	l;
	float	r;
	float	t;
	float	b;
};

// C
struct NiColor
{
	float	r;
	float	g;
	float	b;
};

// 10
struct NiColorAlpha
{
	float	r;
	float	g;
	float	b;
	float	a;
};

// 10
struct NiPlane
{
	NiVector3	nrm;
	float		offset;
};

/***********NiTArray***************/
struct NiTArray_vtbl{
};

struct _NiTArray{
	void		* data;			// 04
	UInt16	capacity;		// 08 - init'd to size of preallocation
	UInt16	firstFreeEntry;	// 0A - index of the first free entry in the block of free entries at the end of the array (or numObjs if full)
	UInt16	numObjs;		// 0C - init'd to 0
	UInt16	growSize;		// 0E - init'd to size of preallocation
};

struct NiTArray{
	NiTArray_vtbl* _vtbl;
	_NiTArray _data;
};

/***********NiTList***************/
struct NITList_vtbl{
	void* Destructor;
	void* AllocateNode;
	void* FreeNode;
};

struct NiTLNode;
struct NiTLNode{
	NiTLNode* next;
	NiTLNode* prev;
	void* data;
};

struct NiTList{
	NITList_vtbl* _vtbl;
	NiTLNode* start;
	NiTLNode* end;
	UInt32 numItems;
};
/***********NiTMap***************/
struct NiTMap_vtbl{
	void*	CalculateBucket;
	void*	CompareKey;
	void*	Fn_03;	// assign to entry
	void*	Fn_04;
	void*	Fn_05;	// locked operations
	void*	Fn_06;	// locked operations
};

struct NiTEntry;
struct NiTEntry{
	NiTEntry* next;
	UInt32 key;
	UInt32 data;
};

struct NiTMap{
	NiTMap_vtbl* _vtbl;
	UInt32	m_numBuckets;	// 4
	NiTEntry	** m_buckets;	// 8
	UInt32	m_numItems;		// C
};

/***********NiTPointerMap***************/
struct NiTPointerMap_vtbl{
	void*	CalculateBucket;
	void*	CompareKey;
	void*	Fn_03;	// assign to entry
	void*	Fn_04;
	void*	Fn_05;	// locked operations
	void*	Fn_06;	// locked operations
};

struct NiTPEntry;
struct NiTPEntry{
	NiTPEntry* next;
	UInt32 key;
	void* data;
};

struct NiTPointerMap{
	NiTPointerMap_vtbl* _vtbl;
	UInt32	m_numBuckets;	// 4
	NiTPEntry	** m_buckets;	// 8
	UInt32	m_numItems;		// C
};