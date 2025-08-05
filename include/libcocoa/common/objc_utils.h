#ifndef LIBCOCOA_COMMON_OBJC_UTILS_H
#define LIBCOCOA_COMMON_OBJC_UTILS_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

Class ObjC_getClass(const char* className);
Class ObjC_allocateClassPair(Class superClass, const char* name, size_t extraBytes);
void ObjC_registerClassPair(Class cls);
void ObjC_classAddMethod(Class cls, SEL sel, IMP imp, const char* types);
SEL ObjC_selRegisterName(const char* selName);

id NSAutoreleasePool_new(void);
void NSAutoreleasePool_drain(id pool);

id NSString_stringWithUTF8String(const char* str);

#ifdef __cplusplus
}
#endif

#endif