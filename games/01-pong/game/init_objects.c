#include "init_objects.h"

void init_objects(Object *ball, Object *player)
{
    render_background();
    init_ball(ball);
    init_player(player);
    SHOW_SPRITES;
}