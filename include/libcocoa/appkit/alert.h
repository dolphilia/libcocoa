#ifndef LIBCOCOA_APPKIT_ALERT_H
#define LIBCOCOA_APPKIT_ALERT_H

#include "../common/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    NSAlertStyleWarning       = 0,
    NSAlertStyleInformational = 1,
    NSAlertStyleCritical      = 2
} NSAlertStyle;

id NSAlert_alloc(void);
id NSAlert_init(id alert);
void NSAlert_setAlertStyle(id alert, NSInteger style);
void NSAlert_setMessageText(id alert, id text);
void NSAlert_setInformativeText(id alert, id text);
void NSAlert_addButtonWithTitle(id alert, id title);
void NSAlert_runModal(id alert);
id NSAlert_release(id alert);

#ifdef __cplusplus
}
#endif

#endif