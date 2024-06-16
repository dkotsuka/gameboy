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

BYTE check_collision_between(Object *object1, Object *object2)
{
    Area2D obj1_area;
    Area2D obj2_area;

    obj1_area.x[0] = object1->position.x;
    obj1_area.x[1] = object1->position.x + object1->width;
    obj1_area.y[0] = object1->position.y;
    obj1_area.y[1] = object1->position.y + object1->height;

    obj2_area.x[0] = object2->position.x;
    obj2_area.x[1] = object2->position.x + object2->width;
    obj2_area.y[0] = object2->position.y;
    obj2_area.y[1] = object2->position.y + object2->height;

    return calculate_collision(obj1_area, obj2_area);
}

BYTE calculate_collision(Area2D area1, Area2D area2)
{
    BYTE collision_obj1_onto_obj2_x = area2.x[0] < area1.x[1] && area2.x[0] > area1.x[0];
    BYTE collision_obj1_onto_obj2_y = area2.y[0] < area1.y[1] && area2.y[0] > area1.y[0];
    BYTE collision_obj1_onto_obj2 = collision_obj1_onto_obj2_x && collision_obj1_onto_obj2_y;

    BYTE collision_obj2_onto_obj1_x = area1.x[0] < area2.x[1] && area1.x[0] > area2.x[0];
    BYTE collision_obj2_onto_obj1_y = area1.y[0] < area2.y[1] && area1.y[0] > area2.y[0];
    BYTE collision_obj2_onto_obj1 = collision_obj2_onto_obj1_x && collision_obj2_onto_obj1_y;

    return collision_obj1_onto_obj2 || collision_obj2_onto_obj1;
}