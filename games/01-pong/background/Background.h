#include <gb/gb.h>
#include "../globaldefs/globaldefs.h"
#include "../assets/Wall.h"
#include "../assets/BackgroundMap.h"

void render_background(void);

#ifndef CHECK_WALL_COLLISION
#define CHECK_WALL_COLLISION
void check_wall_collision(Object *object, uint8_t future_pos_x, uint8_t future_pos_y, BYTE change_direction);
#endif // CHECK_WALL_COLLISION

void change_object_dir_x(Object *object, BYTE change_dir);
void change_object_dir_y(Object *object, BYTE change_dir);