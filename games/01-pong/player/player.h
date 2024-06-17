#include <gb/gb.h>
#include "../assets/Ship.h"
#include "../background/background.h"
#include "../globaldefs/globaldefs.h"

void init_player(Object *player);

void move_player(Object *player, uint8_t position_x);

void control_player(Object *player);

void increase_player_velocity(Object *player);
void decrease_player_velocity(Object *player);
