#include "Background.h"

void render_background(void)
{
    set_bkg_data(0, 6, Wall);
    set_bkg_tiles(0, 0, 20, 18, Background);

    SHOW_BKG;
    DISPLAY_ON;
}

void check_wall_collision(Object *object, uint8_t future_pos_x)
{
    if (future_pos_x < SCREEN_LIMIT_L)
    {
        object->position.x = SCREEN_LIMIT_L;
    }
    else if (future_pos_x + object->width > SCREEN_LIMIT_R)
    {
        object->position.x = SCREEN_LIMIT_R - object->width;
    }
    else
    {
        object->position.x = future_pos_x;
    }
}