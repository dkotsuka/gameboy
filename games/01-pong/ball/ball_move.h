#ifndef MOVE_BALL_H
#define MOVE_BALL_H

#include <gb/gb.h> // Inclui as funções do GBDK necessárias para set_sprite_tile e move_sprite

typedef struct
{
    uint8_t x;
    uint8_t y;
} Position2D;

typedef struct
{
    uint8_t x;
    uint8_t y;
} Velocity2D;

typedef struct
{
    int8_t x;
    int8_t y;
} Direction2D;

// Declaração da função render_ball
void move_ball(void);
void change_ball_direction_on_wall_collision(void);
void update_ball_position(void);
void change_ball_direction_x(void);
void change_ball_direction_y(void);

#endif // MOVE_BALL_H
