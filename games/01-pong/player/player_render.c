#include "player_render.h"
#include "../global/screen.h"
#include "../global/sprites.h"
#include "../assets/Ship.h"

// Define and initialize constants and variables
const uint8_t PLAYER_H = 8;
uint8_t player_pos_y;
uint8_t player_pos_x;

void render_player(void)
{
    player_pos_y = SCREEN_HEIGHT - PLAYER_H - DEATH_ZONE_H;
    player_pos_x = SCREEN_WIDTH / 2;

    set_sprite_data(player_sprite_index_1, 3, Ship);
    set_sprite_tile(player_sprite_index_1, player_sprite_index_1);
    set_sprite_tile(player_sprite_index_2, player_sprite_index_2);
    set_sprite_tile(player_sprite_index_3, player_sprite_index_3);
    move_sprite(player_sprite_index_1, player_pos_x - 8, player_pos_y);
    move_sprite(player_sprite_index_2, player_pos_x, player_pos_y);
    move_sprite(player_sprite_index_3, player_pos_x + 8, player_pos_y);
}