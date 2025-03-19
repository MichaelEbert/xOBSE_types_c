#include "GameForms.h"
#include "nitypes.h"
/***********ChangesMap***************/
struct ChangesMap_vtbl{
    NiTPointerMap_vtbl _base;
    void* unk07();
    void* unk08();
};

struct _ChangesMap{
    _NiTPointerMap _base;
};

struct ChangesMap{
	ChangesMap_vtbl* _vtbl;
	_ChangesMap _data;
};