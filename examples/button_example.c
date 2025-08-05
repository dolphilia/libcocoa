#include <libcocoa/libcocoa.h>

void buttonClicked(id self, SEL _cmd, id sender) {
    id pool = NSAutoreleasePool_new();
    
    id alert = NSAlert_init(NSAlert_alloc());
    NSAlert_setAlertStyle(alert, NSAlertStyleWarning);
    id messageText = NSString_stringWithUTF8String("Confirmation");
    id informativeText = NSString_stringWithUTF8String("Button was clicked!");
    id okButtonTitle = NSString_stringWithUTF8String("OK");
    NSAlert_setMessageText(alert, messageText);
    NSAlert_setInformativeText(alert, informativeText);
    NSAlert_addButtonWithTitle(alert, okButtonTitle);
    NSAlert_runModal(alert);
    NSAlert_release(alert);
    
    NSAutoreleasePool_drain(pool);
}

int main() {
    id pool = NSAutoreleasePool_new();
    
    id app = NSApplication_sharedApplication();
    NSApplication_setActivationPolicy(app, NSApplicationActivationPolicyRegular);
    
    id mainMenu = NSMenu_createApplicationMenu("Button Example");
    NSApplication_setMainMenu(app, mainMenu);
    
    NSApplication_finishLaunching(app);
    
    CGRect rect = CGRectMake(300, 300, 400, 200);
    
    id window = NSWindow_alloc();
    window = NSWindow_initWithContentRect(window, rect, 
        NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable, 
        NSBackingStoreBuffered, NO);
    
    id titleString = NSString_stringWithUTF8String("libcocoa Button Example");
    NSWindow_setTitle(window, titleString);
    
    NSWindow_makeKeyAndOrderFront(window, nil);
    NSApplication_activateIgnoringOtherApps(app, YES);
    
    CGRect buttonRect = CGRectMake(150, 80, 100, 40);
    
    id button = NSButton_initWithFrame(NSButton_alloc(), buttonRect);
    
    id buttonTitle = NSString_stringWithUTF8String("Click Me");
    NSButton_setTitle(button, buttonTitle);
    NSButton_setBezelStyle(button, NSBezelStyleRounded);
    
    Class NSObject = ObjC_getClass("NSObject");
    Class MyButtonHandler = ObjC_allocateClassPair(NSObject, "MyButtonHandler", 0);
    ObjC_classAddMethod(MyButtonHandler, ObjC_selRegisterName("buttonClicked:"), (IMP)buttonClicked, "v@:@");
    ObjC_registerClassPair(MyButtonHandler);
    id delegate = ((id (*)(id, SEL)) objc_msgSend)((id)MyButtonHandler, ObjC_selRegisterName("new"));
    NSButton_setTarget(button, delegate);
    NSButton_setAction(button, ObjC_selRegisterName("buttonClicked:"));
    
    id contentView = NSWindow_contentView(window);
    NSView_addSubview(contentView, button);
    
    NSApplication_run(app);
    
    NSAutoreleasePool_drain(pool);
    return 0;
}