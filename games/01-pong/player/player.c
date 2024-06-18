#include "player.h"

void init_player(Object *player)
{
    player->direction.x = 0;
    player->height = 8;
    player->width = 22;
    player->position.x = 81;
    player->position.y = 148;
    player->velocity.x = 1;
    player->velocity.y = 0;
    player->max_speed = 5;

    set_sprite_data(0, 3, Ship);

    set_sprite_tile(0, 0);
    player->sprite_ids[0] = 0;
    set_sprite_tile(1, 1);
    player->sprite_ids[1] = 1;
    set_sprite_tile(2, 2);
    player->sprite_ids[2] = 2;

    move_player(player, player->position.x);
}

void move_player(Object *player, uint8_t position_x)
{
    check_wall_collision(player, position_x, player->position.y, 0);

    move_sprite(player->sprite_ids[0], player->position.x - 1, player->position.y);
    move_sprite(player->sprite_ids[1], player->position.x + 7, player->position.y);
    move_sprite(player->sprite_ids[2], player->position.x + 15, player->position.y);
}

void control_player(Object *player)
{
    switch (joypad())
    {
    case J_RIGHT:
        player->direction.x = 1;
        increase_player_velocity(player);
        break;
    case J_LEFT:
        player->direction.x = -1;
        increase_player_velocity(player);
        break;
    default:
        decrease_player_velocity(player);
        break;
    }

    move_player(player, player->position.x + (player->velocity.x * player->direction.x));
}

void increase_player_velocity(Object *player)
{
    if (player->velocity.x < player->max_speed)
    {
        player->velocity.x += 1;
    }
}

void decrease_player_velocity(Object *player)
{
    if (player->velocity.x > 0)
    {
        player->velocity.x -= 1;
    }
}
