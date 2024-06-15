#include "player.h"
#include "../assets/Ship.h"

Player player;

void init_player(void)
{
    player.direction_x = 0;
    player.height = 8;
    player.width = 24;
    player.position.x = (SCREEN_W / 2) - (player.width / 2);
    player.position.y = SCREEN_H - player.height - DEATH_ZONE_H;

    set_sprite_data(0, 3, Ship);

    set_sprite_tile(0, 0);
    player.sprite_ids[0] = 0;
    set_sprite_tile(1, 1);
    player.sprite_ids[1] = 1;
    set_sprite_tile(2, 2);
    player.sprite_ids[2] = 2;
}