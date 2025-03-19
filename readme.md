This is a translation of the xOBSE header files in to C so they can be parsed by Ghidra.
Most of the datatypes are in the same header files that they are in in xOBSE.

## General Structure
Each class has 3 structs: 
```c
struct CLASSNAME_vtbl{
    //this contains the virtual methods for the class
}
struct _CLASSNAME{
    //_BASECLASS
    //this contains the data members of the class
    int data0;
    int data1;
}
struct CLASSNAME{
    //wrapper object to construct the final class structure
    CLASSNAME_vtbl* _vtbl;
    _CLASSNAME _data;
}
```

If used in ghidra, you will see a lot of _data._base._base._base.xxxx. ignore all the _data and _base, that's just traversing the inheritance tree.

This structure is used so inheritance works. A class inherits all the elements of its base class, EXCEPT the vtable. So we have to have the vtable be a separate element that is only included in the final structure. 
When creating a derived class, include the base class's _CLASSNAME struct as the first element of the derived class's _CLASSNAME. 
So you end up with a data structure looking like
```
CHILDCLASS{
child VTBL*---------->CHILDCLASS_VTBL{
//_CHILDCLASS start     parent_method0()
  parent_data0          parent_method1()
  parent_data1          ...
  ...                   child_method0
  child_data0           child_method1
  child_data1         }
  ...
//_CHILDCLASS end
}
```