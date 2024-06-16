#include <gb/gb.h>
#include "player/player.h"
#include "background/Background.h"

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