#ifndef DEBUG_H
#define DEBUG_H

#include "types.h"

#define NOCASH_SIG      ((char*)0x0FFFA00)
#define REG_NOCASH_LOG  VOLADDR(0x04FFFA1C, unsigned char)
#define VOLADDR(a, t)   (*(t volatile *)(a))

/**
 * Example as to how one would write a message to No$GBA.
 * 
 * char message[120];
 * 
 * if(logInitNoCash())
 * {
 *      sprintf(message, "I wanna write something");
 *      logOutputNoCash(0, message);
 * }
*/
extern bool logInitNoCash();
extern void logOutputNoCash(unsigned char level, const char* message);


#endif