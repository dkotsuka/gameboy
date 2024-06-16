#include <gb/gb.h>
#include "../globaldefs/globaldefs.h"

void init_player(void);

void move_player(uint8_t position_x);

void control_player(void);

void increase_player_velocity(void);
void decrease_player_velocity(void);
void check_wall_collision(uint8_t position_x);