#include "Background.h"

void render_background(void)
{
    set_bkg_data(0, 6, Wall);
    set_bkg_tiles(0, 0, 20, 18, Background);

    SHOW_BKG;
    DISPLAY_ON;
}

void check_wall_collision(Object *object, uint8_t future_pos_x, uint8_t future_pos_y, BYTE change_direction)
{
    if (future_pos_y < SCREEN_LIMIT_T)
    {
        object->position.y = SCREEN_LIMIT_T;
        change_object_dir_y(object, change_direction);
    }
    else
    {
        object->position.y = future_pos_y;
    }

    if (future_pos_x < SCREEN_LIMIT_L)
    {
        object->position.x = SCREEN_LIMIT_L;
        change_object_dir_x(object, change_direction);
    }
    else if (future_pos_x + object->width > SCREEN_LIMIT_R)
    {
        object->position.x = SCREEN_LIMIT_R - object->width;
        change_object_dir_x(object, change_direction);
    }
    else
    {
        object->position.x = future_pos_x;
    }
}

void change_object_dir_x(Object *object, BYTE change_dir)
{
    if (change_dir == 1)
    {
        object->direction.x *= -1;
    }
}

void change_object_dir_y(Object *object, BYTE change_dir)
{
    if (change_dir == 1)
    {
        object->direction.y *= -1;
    }
}