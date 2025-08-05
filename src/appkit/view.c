#include "libcocoa/appkit/view.h"
#include "libcocoa/common/objc_utils.h"

void NSView_addSubview(id view, id subview) {
    ((void (*)(id, SEL, id))objc_msgSend)(view, sel_registerName("addSubview:"), subview);
}