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
    player.velocity.x = 1;
    player.velocity.y = 0;
    player.max_speed = 5;

    set_sprite_data(0, 3, Ship);

    set_sprite_tile(0, 0);
    player.sprite_ids[0] = 0;
    set_sprite_tile(1, 1);
    player.sprite_ids[1] = 1;
    set_sprite_tile(2, 2);
    player.sprite_ids[2] = 2;

    move_player(player.position.x + 4);
}

void move_player(uint8_t position_x)
{
    check_wall_collision(position_x);

    move_sprite(player.sprite_ids[0], player.position.x, player.position.y);
    move_sprite(player.sprite_ids[1], player.position.x + 8, player.position.y);
    move_sprite(player.sprite_ids[2], player.position.x + 16, player.position.y);
}

void control_player(void)
{
    switch (joypad())
    {
    case J_RIGHT:
        player.direction_x = 1;
        increase_player_velocity();
        break;
    case J_LEFT:
        player.direction_x = -1;
        increase_player_velocity();
        break;
    default:
        decrease_player_velocity();
        break;
    }

    move_player(player.position.x + (player.velocity.x * player.direction_x));
}

void increase_player_velocity(void)
{
    if (player.velocity.x < player.max_speed)
    {
        player.velocity.x += 1;
    }
}

void decrease_player_velocity(void)
{
    if (player.velocity.x > 0)
    {
        player.velocity.x -= 1;
    }
}

void check_wall_collision(uint8_t position_x)
{
    if (position_x < 12)
    {
        player.position.x = 12;
    }
    else if (position_x + player.width > 160)
    {
        player.position.x = 164 - player.width;
    }
    else
    {
        player.position.x = position_x;
    }
}