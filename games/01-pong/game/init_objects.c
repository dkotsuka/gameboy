#include "init_objects.h"

void init_objects(void)
{
    render_background();
    init_ball();
    init_player();
    SHOW_SPRITES;
}