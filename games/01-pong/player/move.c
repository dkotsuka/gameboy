#include "move.h"

// Function to move player
void move_player(void)
{
    switch (joypad())
    {
    case J_LEFT:
        scroll_sprite(0, -1, 0);
        scroll_sprite(1, -1, 0);
        scroll_sprite(2, -1, 0);
        break;
    case J_RIGHT:
        scroll_sprite(0, 1, 0);
        scroll_sprite(1, 1, 0);
        scroll_sprite(2, 1, 0);
        break;
    }
}
