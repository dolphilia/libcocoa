#ifndef LIBCOCOA_APPKIT_MENU_H
#define LIBCOCOA_APPKIT_MENU_H

#include "../common/types.h"

#ifdef __cplusplus
extern "C" {
#endif

id NSMenu_alloc(void);
id NSMenu_initWithTitle(id menu, id title);
void NSMenu_addItem(id menu, id menuItem);

id NSMenuItem_alloc(void);
id NSMenuItem_initWithTitle(id menuItem, id title, SEL action, id keyEquivalent);
void NSMenuItem_setSubmenu(id menuItem, id submenu);

id NSMenu_createApplicationMenu(const char* appName);

#ifdef __cplusplus
}
#endif

#endif