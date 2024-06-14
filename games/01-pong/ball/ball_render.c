#include "ball_render.h"

void render_ball(void)
{
    set_sprite_data(0, 1, Ball8x8);
    set_sprite_tile(0, 0);
    move_sprite(0, 80, 80);
}
