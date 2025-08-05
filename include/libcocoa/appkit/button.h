#ifndef LIBCOCOA_APPKIT_BUTTON_H
#define LIBCOCOA_APPKIT_BUTTON_H

#include "../common/types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    NSBezelStyleRounded          = 1,
    NSBezelStyleRegularSquare    = 2,
    NSBezelStyleDisclosure       = 5,
    NSBezelStyleShadowlessSquare = 6,
    NSBezelStyleCircular         = 7,
    NSBezelStyleTexturedSquare   = 8,
    NSBezelStyleHelpButton       = 9,
    NSBezelStyleSmallSquare      = 10,
    NSBezelStyleTexturedRounded  = 11,
    NSBezelStyleRoundRect        = 12,
    NSBezelStyleRecessed         = 13,
    NSBezelStyleRoundedDisclosure = 14
} NSBezelStyle;

id NSButton_alloc(void);
id NSButton_initWithFrame(id button, CGRect frame);
void NSButton_setTitle(id button, id title);
void NSButton_setBezelStyle(id button, NSInteger style);
void NSButton_setTarget(id button, id target);
void NSButton_setAction(id button, SEL action);

#ifdef __cplusplus
}
#endif

#endif