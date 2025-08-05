#include "libcocoa/appkit/menu.h"
#include "libcocoa/common/objc_utils.h"

id NSMenu_alloc(void) {
    id menuClass = (id)objc_getClass("NSMenu");
    return ((id (*)(id, SEL))objc_msgSend)(menuClass, sel_registerName("alloc"));
}

id NSMenu_initWithTitle(id menu, id title) {
    return ((id (*)(id, SEL, id))objc_msgSend)(menu, sel_registerName("initWithTitle:"), title);
}

void NSMenu_addItem(id menu, id menuItem) {
    ((void (*)(id, SEL, id))objc_msgSend)(menu, sel_registerName("addItem:"), menuItem);
}

id NSMenuItem_alloc(void) {
    id menuItemClass = (id)objc_getClass("NSMenuItem");
    return ((id (*)(id, SEL))objc_msgSend)(menuItemClass, sel_registerName("alloc"));
}

id NSMenuItem_initWithTitle(id menuItem, id title, SEL action, id keyEquivalent) {
    return ((id (*)(id, SEL, id, SEL, id))objc_msgSend)(menuItem, sel_registerName("initWithTitle:action:keyEquivalent:"), title, action, keyEquivalent);
}

void NSMenuItem_setSubmenu(id menuItem, id submenu) {
    ((void (*)(id, SEL, id))objc_msgSend)(menuItem, sel_registerName("setSubmenu:"), submenu);
}

id NSMenu_createApplicationMenu(const char* appName) {
    id menuBar = NSMenu_initWithTitle(NSMenu_alloc(), NSString_stringWithUTF8String(""));
    
    id appMenuItem = NSMenuItem_initWithTitle(NSMenuItem_alloc(), 
        NSString_stringWithUTF8String(""), 
        NULL, 
        NSString_stringWithUTF8String(""));
    
    id appMenu = NSMenu_initWithTitle(NSMenu_alloc(), NSString_stringWithUTF8String(appName));
    
    id quitTitle = NSString_stringWithUTF8String("Quit");
    id quitKeyEquiv = NSString_stringWithUTF8String("q");
    id quitMenuItem = NSMenuItem_initWithTitle(NSMenuItem_alloc(), 
        quitTitle, 
        sel_registerName("terminate:"), 
        quitKeyEquiv);
    
    NSMenu_addItem(appMenu, quitMenuItem);
    NSMenuItem_setSubmenu(appMenuItem, appMenu);
    NSMenu_addItem(menuBar, appMenuItem);
    
    return menuBar;
}