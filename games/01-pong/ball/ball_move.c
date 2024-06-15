#include <gb/gb.h>
#include "ball_move.h"

Position2D ball_pos = {80, 80};
Direction2D ball_dir = {1, 1};
Velocity2D ball_vel = {20, 10};

void move_ball(void)
{
    change_ball_direction_on_wall_collision();
    update_ball_position();

    move_sprite(0, ball_pos.x, ball_pos.y);
}

void update_ball_position(void)
{
    ball_pos.x += (ball_dir.x * ball_vel.x) / 10;
    ball_pos.y += (ball_dir.y * ball_vel.y) / 10;
}

void change_ball_direction_on_wall_collision(void)
{
    if (ball_pos.x > 160 || ball_pos.x < 8)
    {
        change_ball_direction_x();
    }
    if (ball_pos.y > 152 || ball_pos.y < 16)
    {
        change_ball_direction_y();
    }
}

void change_ball_direction_x(void)
{
    ball_dir.x *= -1;
}

void change_ball_direction_y(void)
{
    ball_dir.y *= -1;
}