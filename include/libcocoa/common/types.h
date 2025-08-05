#ifndef LIBCOCOA_COMMON_TYPES_H
#define LIBCOCOA_COMMON_TYPES_H

#include <objc/objc.h>
#include <objc/runtime.h>
#include <objc/message.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long NSUInteger;
typedef long NSInteger;
typedef bool BOOL;

#ifndef YES
#define YES ((BOOL)1)
#endif

#ifndef NO
#define NO ((BOOL)0)
#endif

#ifndef nil
#define nil ((id)0)
#endif

#ifdef __cplusplus
}
#endif

#endif