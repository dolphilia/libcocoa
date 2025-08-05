#include <libcocoa/libcocoa.h>

int main() {
    id pool = NSAutoreleasePool_new();
    
    id app = NSApplication_sharedApplication();
    NSApplication_setActivationPolicy(app, NSApplicationActivationPolicyRegular);
    
    id mainMenu = NSMenu_createApplicationMenu("Minimal Window");
    NSApplication_setMainMenu(app, mainMenu);
    
    NSApplication_finishLaunching(app);
    
    CGRect rect = CGRectMake(300, 300, 400, 200);
    
    id window = NSWindow_alloc();
    window = NSWindow_initWithContentRect(window, rect, 
        NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable, 
        NSBackingStoreBuffered, NO);
    
    id titleString = NSString_stringWithUTF8String("Minimal Window Test");
    NSWindow_setTitle(window, titleString);
    
    NSWindow_makeKeyAndOrderFront(window, nil);
    NSApplication_activateIgnoringOtherApps(app, YES);
    
    NSApplication_run(app);
    
    NSAutoreleasePool_drain(pool);
    return 0;
}