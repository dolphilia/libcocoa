#include "libcocoa/common/objc_utils.h"

Class ObjC_getClass(const char* className) {
    return objc_getClass(className);
}

Class ObjC_allocateClassPair(Class superClass, const char* name, size_t extraBytes) {
    return objc_allocateClassPair(superClass, name, extraBytes);
}

void ObjC_registerClassPair(Class cls) {
    objc_registerClassPair(cls);
}

void ObjC_classAddMethod(Class cls, SEL sel, IMP imp, const char* types) {
    class_addMethod(cls, sel, imp, types);
}

SEL ObjC_selRegisterName(const char* selName) {
    return sel_registerName(selName);
}

id NSAutoreleasePool_new(void) {
    return ((id (*)(id, SEL))objc_msgSend)((id)objc_getClass("NSAutoreleasePool"), sel_registerName("new"));
}

void NSAutoreleasePool_drain(id pool) {
    ((void (*)(id, SEL))objc_msgSend)(pool, sel_registerName("drain"));
}

id NSString_stringWithUTF8String(const char* str) {
    return ((id (*)(id, SEL, const char*))objc_msgSend)((id)objc_getClass("NSString"), sel_registerName("stringWithUTF8String:"), str);
}