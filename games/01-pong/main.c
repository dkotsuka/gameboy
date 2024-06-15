#include <gb/gb.h>
#include "player/player.h"

void main(void)
{
    init_player();
    SHOW_SPRITES;
    while (1)
    {
        vsync();
    }
}