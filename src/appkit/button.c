#include "libcocoa/appkit/button.h"
#include "libcocoa/common/objc_utils.h"

id NSButton_alloc(void) {
    id buttonClass = (id)objc_getClass("NSButton");
    return ((id (*)(id, SEL))objc_msgSend)(buttonClass, sel_registerName("alloc"));
}

id NSButton_initWithFrame(id button, CGRect frame) {
    return ((id (*)(id, SEL, CGRect))objc_msgSend)(button, sel_registerName("initWithFrame:"), frame);
}

void NSButton_setTitle(id button, id title) {
    ((void (*)(id, SEL, id))objc_msgSend)(button, sel_registerName("setTitle:"), title);
}

void NSButton_setBezelStyle(id button, NSInteger style) {
    ((void (*)(id, SEL, NSInteger))objc_msgSend)(button, sel_registerName("setBezelStyle:"), style);
}

void NSButton_setTarget(id button, id target) {
    ((void (*)(id, SEL, id))objc_msgSend)(button, sel_registerName("setTarget:"), target);
}

void NSButton_setAction(id button, SEL action) {
    ((void (*)(id, SEL, SEL))objc_msgSend)(button, sel_registerName("setAction:"), action);
}