#include "libcocoa/appkit/application.h"
#include "libcocoa/common/objc_utils.h"

id NSApplication_sharedApplication(void) {
    return ((id (*)(id, SEL))objc_msgSend)((id)objc_getClass("NSApplication"), sel_registerName("sharedApplication"));
}

void NSApplication_run(id app) {
    ((void (*)(id, SEL))objc_msgSend)(app, sel_registerName("run"));
}

BOOL NSApplication_setActivationPolicy(id app, NSApplicationActivationPolicy policy) {
    return ((BOOL (*)(id, SEL, NSApplicationActivationPolicy))objc_msgSend)(app, sel_registerName("setActivationPolicy:"), policy);
}

void NSApplication_activateIgnoringOtherApps(id app, BOOL flag) {
    ((void (*)(id, SEL, BOOL))objc_msgSend)(app, sel_registerName("activateIgnoringOtherApps:"), flag);
}

void NSApplication_finishLaunching(id app) {
    ((void (*)(id, SEL))objc_msgSend)(app, sel_registerName("finishLaunching"));
}

void NSApplication_setMainMenu(id app, id menu) {
    ((void (*)(id, SEL, id))objc_msgSend)(app, sel_registerName("setMainMenu:"), menu);
}