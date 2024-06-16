#include <gb/gb.h>
#include "../globaldefs/globaldefs.h"
#include "../assets/Wall.h"
#include "../assets/BackgroundMap.h"

void render_background(void);
void check_wall_collision(Object *object, uint8_t future_pos_x);