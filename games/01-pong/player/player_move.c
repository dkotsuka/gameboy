#include "player_move.h"

uint8_t player_position = 88;
int8_t player_direction;
uint8_t player_acceleration = 1;
const uint8_t ACCELERATION_LIMIT = 5;

// Function to move player
void move_player(void)
{
    switch (joypad())
    {
    case J_LEFT:
        player_direction = -1;
        player_acceleration += 1;
        break;
    case J_RIGHT:
        player_direction = 1;
        player_acceleration += 1;
        break;
    default:
        player_direction = 0;
        break;
    }

    if (player_acceleration > ACCELERATION_LIMIT)
    {
        player_acceleration = ACCELERATION_LIMIT;
    }

    player_position += player_direction * player_acceleration;

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
