#ifndef LIBCOCOA_APPKIT_APPLICATION_H
#define LIBCOCOA_APPKIT_APPLICATION_H

#include "../common/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    NSApplicationActivationPolicyRegular    = 0,
    NSApplicationActivationPolicyAccessory  = 1,
    NSApplicationActivationPolicyProhibited = 2
} NSApplicationActivationPolicy;

id NSApplication_sharedApplication(void);
void NSApplication_run(id app);
BOOL NSApplication_setActivationPolicy(id app, NSApplicationActivationPolicy policy);
void NSApplication_activateIgnoringOtherApps(id app, BOOL flag);
void NSApplication_finishLaunching(id app);
void NSApplication_setMainMenu(id app, id menu);

#ifdef __cplusplus
}
#endif

#endif