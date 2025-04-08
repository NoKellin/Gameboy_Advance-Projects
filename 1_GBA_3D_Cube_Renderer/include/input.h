#ifndef INPUT_H
#define INPUT_H

#include "types.h"
#include "memory.h"

#define REG_KEYINPUT    *(vu16*)(REG_BASE+0x0130)

#define KEY_A			0x0001	//!< Button A
#define KEY_B			0x0002	//!< Button B
#define KEY_SELECT		0x0004	//!< Select button
#define KEY_START		0x0008	//!< Start button
#define KEY_RIGHT		0x0010	//!< Right D-pad
#define KEY_LEFT		0x0020	//!< Left D-pad
#define KEY_UP			0x0040	//!< Up D-pad
#define KEY_DOWN		0x0080	//!< Down D-pad
#define KEY_R			0x0100	//!< Shoulder R
#define KEY_L			0x0200	//!< Shoulder L

#define KEY_ANY			0x03FF	//!< any key
#define KEY_DIR			0x00F0	//!< any-dpad
#define KEY_ACCEPT		0x0009	//!< A or start
#define KEY_CANCEL		0x0002	//!< B (well, it usually is)
#define KEY_SHOULDER	0x0300	//!< L or R

#define KEY_RESET		0x000F	//!< St+Se+A+B

#define KEY_MASK        0x03FF

extern u16 curr_key_input;
extern u16 prev_key_input;

void scan_keys();
u32 get_key(u32 key);
u32 get_key_down(u32 key);
u32 get_key_up(u32 key);

#endif