#include <gb/gb.h>

#define SCREEN_H 160
#define SCREEN_W 168
#define DEATH_ZONE_H 8
#define SCREEN_LIMIT_T 20
#define SCREEN_LIMIT_L 12
#define SCREEN_LIMIT_R 164

#ifndef VECTOR2D_H
#define VECTOR2D_H
typedef struct
{
    int x;
    int y;
} Vector2D;
#endif // VECTOR2D_H

#ifndef IVECTOR2D_H
#define IVECTOR2D_H
typedef struct
{
    int8_t x;
    int8_t y;
} IVector2D;
#endif // IVECTOR2D_H

#ifndef AREAD2D_H
#define AREAD2D_H
typedef struct
{
    uint8_t x[2];
    uint8_t y[2];
} Area2D;
#endif // AREAD2D_H

#ifndef OBJECT_H
#define OBJECT_H
typedef struct
{
    Vector2D position;
    Vector2D velocity;
    IVector2D direction;
    uint8_t sprite_ids[3];
    uint8_t width;
    uint8_t height;
    uint8_t max_speed;
} Object;
#endif // OBJECT_H
