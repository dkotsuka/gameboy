#include "ball.h"

Object ball;

void init_ball(void)
{
    ball.direction.x = -1;
    ball.direction.y = -1;
    ball.height = 8;
    ball.width = 8;
    ball.position.x = 80;
    ball.position.y = 76;
    ball.velocity.x = 1;
    ball.velocity.y = 1;
    ball.max_speed = 4;

    set_sprite_data(3, 1, BallSprite);

    set_sprite_tile(3, 3);
    ball.sprite_ids[0] = 3;

    move_ball(ball.position.x + 4, ball.position.y + 4);
}

void move_ball(uint8_t future_pos_x, uint8_t future_pos_y)
{
    check_wall_collision(&ball, future_pos_x, future_pos_y, 1);
    move_sprite(ball.sprite_ids[0], ball.position.x, ball.position.y);
}

void start_ball_movement(void)
{
    uint8_t position_x = ball.position.x + ball.direction.x * ball.velocity.x;
    uint8_t position_y = ball.position.y + ball.direction.y * ball.velocity.y;
    move_ball(position_x, position_y);
}
