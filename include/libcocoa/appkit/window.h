#ifndef LIBCOCOA_APPKIT_WINDOW_H
#define LIBCOCOA_APPKIT_WINDOW_H

#include "../common/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    NSWindowStyleMaskBorderless          = 0,
    NSWindowStyleMaskTitled              = (1 << 0),
    NSWindowStyleMaskClosable            = (1 << 1),
    NSWindowStyleMaskMiniaturizable      = (1 << 2),
    NSWindowStyleMaskResizable           = (1 << 3),
    NSWindowStyleMaskTexturedBackground  = (1 << 8),
    NSWindowStyleMaskUnifiedTitleAndToolbar = (1 << 12),
    NSWindowStyleMaskFullScreen          = (1 << 14),
    NSWindowStyleMaskFullSizeContentView = (1 << 15),
    NSWindowStyleMaskUtilityWindow       = (1 << 4),
    NSWindowStyleMaskDocModalWindow      = (1 << 6),
    NSWindowStyleMaskHUDWindow           = (1 << 13)
} NSWindowStyleMask;

typedef enum {
    NSBackingStoreRetained    = 0,
    NSBackingStoreNonretained = 1,
    NSBackingStoreBuffered    = 2
} NSBackingStoreType;

id NSWindow_alloc(void);
id NSWindow_initWithContentRect(id window, CGRect contentRect, NSUInteger styleMask, NSInteger backing, BOOL defer);
void NSWindow_setTitle(id window, id title);
void NSWindow_makeKeyAndOrderFront(id window, id sender);
id NSWindow_contentView(id window);

#ifdef __cplusplus
}
#endif

#endif