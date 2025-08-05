#include "libcocoa/appkit/alert.h"
#include "libcocoa/common/objc_utils.h"

id NSAlert_alloc(void) {
    id alertClass = (id)objc_getClass("NSAlert");
    return ((id (*)(id, SEL))objc_msgSend)(alertClass, sel_registerName("alloc"));
}

id NSAlert_init(id alert) {
    return ((id (*)(id, SEL))objc_msgSend)(alert, sel_registerName("init"));
}

void NSAlert_setAlertStyle(id alert, NSInteger style) {
    ((void (*)(id, SEL, NSInteger))objc_msgSend)(alert, sel_registerName("setAlertStyle:"), style);
}

void NSAlert_setMessageText(id alert, id text) {
    ((void (*)(id, SEL, id))objc_msgSend)(alert, sel_registerName("setMessageText:"), text);
}

void NSAlert_setInformativeText(id alert, id text) {
    ((void (*)(id, SEL, id))objc_msgSend)(alert, sel_registerName("setInformativeText:"), text);
}

void NSAlert_addButtonWithTitle(id alert, id title) {
    ((void (*)(id, SEL, id))objc_msgSend)(alert, sel_registerName("addButtonWithTitle:"), title);
}

void NSAlert_runModal(id alert) {
    ((void (*)(id, SEL))objc_msgSend)(alert, sel_registerName("runModal"));
}

id NSAlert_release(id alert) {
    return ((id (*)(id, SEL))objc_msgSend)(alert, sel_registerName("release"));
}