#include <gb/gb.h>
#include "player/player.h"
#include "background/background.h"

void main(void)
{
    render_background();
    init_player();
    SHOW_SPRITES;

    while (1)
    {
        control_player();
        vsync();
    }
}