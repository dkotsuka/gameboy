#include "init_objects.h"

void init_objects(Object *ball)
{
    render_background();
    init_ball(ball);
    init_player();
    SHOW_SPRITES;
}