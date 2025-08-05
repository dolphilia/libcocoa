#include "libcocoa/appkit/window.h"
#include "libcocoa/common/objc_utils.h"

id NSWindow_alloc(void) {
    id windowClass = (id)objc_getClass("NSWindow");
    return ((id (*)(id, SEL))objc_msgSend)(windowClass, sel_registerName("alloc"));
}

id NSWindow_initWithContentRect(id window, CGRect contentRect, NSUInteger styleMask, NSInteger backing, BOOL defer) {
    return ((id (*)(id, SEL, CGRect, NSUInteger, NSInteger, BOOL))objc_msgSend)(window, sel_registerName("initWithContentRect:styleMask:backing:defer:"), contentRect, styleMask, backing, defer);
}

void NSWindow_setTitle(id window, id title) {
    ((void (*)(id, SEL, id))objc_msgSend)(window, sel_registerName("setTitle:"), title);
}

void NSWindow_makeKeyAndOrderFront(id window, id sender) {
    ((void (*)(id, SEL, id))objc_msgSend)(window, sel_registerName("makeKeyAndOrderFront:"), sender);
}

id NSWindow_contentView(id window) {
    return ((id (*)(id, SEL))objc_msgSend)(window, sel_registerName("contentView"));
}