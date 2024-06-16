#include <gb/gb.h>
#include "player/player.h"
#include "ball/ball.h"
#include "background/background.h"

void main(void)
{
    render_background();
    init_ball();
    init_player();
    SHOW_SPRITES;

    while (1)
    {
        control_player();
        start_ball_movement();
        vsync();
    }
}