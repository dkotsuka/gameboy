#include "player_move.h"

uint8_t player_position = 88;
int8_t player_direction;

// Function to move player
void move_player(void)
{
    switch (joypad())
    {
    case J_LEFT:
        player_direction = -1;
        break;
    case J_RIGHT:
        player_direction = 1;
        break;
    default:
        player_direction = 0;
        break;
    }

    player_position += player_direction;
    if (player_position < 16)
    {
        player_position = 16;
    }
    if (player_position > 152)
    {
        player_position = 152;
    }

    move_sprite(player_sprite_index_1, player_position - 8, 144);
    move_sprite(player_sprite_index_2, player_position, 144);
    move_sprite(player_sprite_index_3, player_position + 8, 144);
}
