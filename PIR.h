#ifndef _PIR_H_
#define _PIR_H_
#include <stdint.h>

void PIR_Init(void);
extern volatile uint8_t PIR_State;
typedef void(*CALLBACK_PIR_Changed)(uint8_t new_value);
extern CALLBACK_PIR_Changed service_routine;

#endif
