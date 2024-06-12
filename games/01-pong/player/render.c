#include "render.h"
#include "../global/screen.h"
#include "../assets/Ship.h"

// Define and initialize constants and variables
const uint8_t PLAYER_H = 8;
uint8_t player_pos_y;
uint8_t player_pos_x;

void render_player(void)
{
    player_pos_y = SCREEN_HEIGHT - PLAYER_H - DEATH_ZONE_H;
    player_pos_x = SCREEN_WIDTH / 2;

    set_sprite_data(0, 3, Ship);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 1);
    set_sprite_tile(2, 2);
    move_sprite(0, player_pos_x - 8, player_pos_y);
    move_sprite(1, player_pos_x, player_pos_y);
    move_sprite(2, player_pos_x + 8, player_pos_y);
    SHOW_SPRITES;
}