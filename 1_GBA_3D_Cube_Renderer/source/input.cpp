#include "input.h"

u16 curr_key_input = 0;
u16 prev_key_input = 0;

void scan_keys()
{
    prev_key_input = curr_key_input;
    curr_key_input = ~REG_KEYINPUT & KEY_MASK;
}

u32 get_key(u32 key)
{
    return (curr_key_input & key) == key;
}

u32 get_key_down(u32 key)
{
    return (curr_key_input &~prev_key_input) & key;
}

u32 get_key_up(u32 key)
{
    return (prev_key_input &~curr_key_input) & key;
}