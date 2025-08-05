#include <objc/objc.h>
#include <objc/runtime.h>
#include <objc/message.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>
#include <stdbool.h>

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

// Window Style Masks
typedef enum {
    NSWindowStyleMaskBorderless          = 0,
    NSWindowStyleMaskTitled              = (1 << 0),
    NSWindowStyleMaskClosable            = (1 << 1),
    NSWindowStyleMaskMiniaturizable      = (1 << 2),
    NSWindowStyleMaskResizable           = (1 << 3),
} NSWindowStyleMask;

// Backing Store Types
typedef enum {
    NSBackingStoreRetained    = 0,
    NSBackingStoreNonretained = 1,
    NSBackingStoreBuffered    = 2
} NSBackingStoreType;

// Application Activation Policy
typedef enum {
    NSApplicationActivationPolicyRegular    = 0,
    NSApplicationActivationPolicyAccessory  = 1,
    NSApplicationActivationPolicyProhibited = 2
} NSApplicationActivationPolicy;

// Common functions
Class ObjC_getClass(const char* className) {
    return objc_getClass(className);
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

// NSApplication functions
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

// NSWindow functions
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

// NSMenu functions
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

int main() {
    id pool = NSAutoreleasePool_new();
    
    id app = NSApplication_sharedApplication();
    NSApplication_setActivationPolicy(app, NSApplicationActivationPolicyRegular);
    
    id mainMenu = NSMenu_createApplicationMenu("Standalone Window");
    NSApplication_setMainMenu(app, mainMenu);
    
    NSApplication_finishLaunching(app);
    
    CGRect rect = CGRectMake(300, 300, 400, 200);
    
    id window = NSWindow_alloc();
    window = NSWindow_initWithContentRect(window, rect, 
        NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable, 
        NSBackingStoreBuffered, NO);
    
    id titleString = NSString_stringWithUTF8String("Standalone Window Test");
    NSWindow_setTitle(window, titleString);
    
    NSWindow_makeKeyAndOrderFront(window, nil);
    NSApplication_activateIgnoringOtherApps(app, YES);
    
    NSApplication_run(app);
    
    NSAutoreleasePool_drain(pool);
    return 0;
}