#include "player_move.h"

// Function to move player
void move_player(void)
{
    switch (joypad())
    {
    case J_LEFT:
        scroll_sprite(player_sprite_index_1, -1, 0);
        scroll_sprite(player_sprite_index_2, -1, 0);
        scroll_sprite(player_sprite_index_3, -1, 0);
        break;
    case J_RIGHT:
        scroll_sprite(player_sprite_index_1, 1, 0);
        scroll_sprite(player_sprite_index_2, 1, 0);
        scroll_sprite(player_sprite_index_3, 1, 0);
        break;
    }
}
