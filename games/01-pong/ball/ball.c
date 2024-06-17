#include "ball.h"

void init_ball(Object *ball)
{
    ball->direction.x = -1;
    ball->direction.y = -1;
    ball->height = 8;
    ball->width = 8;
    ball->position.x = 80;
    ball->position.y = 76;
    ball->velocity.x = 1;
    ball->velocity.y = 1;
    ball->max_speed = 4;

    set_sprite_data(3, 1, BallSprite);

    set_sprite_tile(3, 3);
    ball->sprite_ids[0] = 3;

    move_ball_sprite(ball, ball->position.x, ball->position.y);
}

void move_ball_sprite(Object *ball, uint8_t future_pos_x, uint8_t future_pos_y)
{
    check_wall_collision(ball, future_pos_x, future_pos_y, 1);
    move_sprite(ball->sprite_ids[0], ball->position.x, ball->position.y);
}

void move_ball(Object *ball, Object *player)
{
    check_ball_collision_with_player(ball, player);
    move_ball_sprite(ball, ball->position.x, ball->position.y);
}

void check_ball_collision_with_player(Object *ball, Object *player)
{
    uint8_t ball_pos_x = ball->position.x;
    uint8_t ball_pos_y = ball->position.y;
    ball->position.x = ball->position.x + ball->direction.x * ball->velocity.x;
    ball->position.y = ball->position.y + ball->direction.y * ball->velocity.y;

    BYTE has_collision = check_collision_between(ball, player);
    if (has_collision == 1)
    {
        ball->direction.y = -1;
        ball->position.x = ball_pos_x;
        ball->position.y = player->position.y - ball->height;
    }
}