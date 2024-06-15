#include <gb/gb.h>
#include "global/screen.h"
#include "player/player_render.h"
#include "player/player_move.h"
#include "ball/ball_render.h"
#include "ball/ball_move.h"

void main(void)
{
    render_player();
    render_ball();
    SHOW_SPRITES;
    while (1)
    {
        move_player();
        move_ball();
        vsync();
    }
}