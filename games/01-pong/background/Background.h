#include <gb/gb.h>
#include "../globaldefs/globaldefs.h"
#include "../assets/Wall.h"
#include "../assets/BackgroundMap.h"

void render_background(void);

void check_wall_collision(Object *object, uint8_t future_pos_x, uint8_t future_pos_y, BYTE change_direction);
BYTE check_collision_between(Object *object1, Object *object2);
BYTE calculate_collision(Area2D area1, Area2D area2);

void change_object_dir_x(Object *object, BYTE change_dir);
void change_object_dir_y(Object *object, BYTE change_dir);