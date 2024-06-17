#include <gb/gb.h>
#include "../background/background.h"
#include "../globaldefs/globaldefs.h"
#include "../assets/BallSprite.h"

void init_ball(Object *ball);
void move_ball_sprite(Object *ball, uint8_t future_pos_x, uint8_t future_pos_y);
void move_ball(Object *ball, Object *player);
void check_ball_collision_with_player(Object *ball, Object *player);