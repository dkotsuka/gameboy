#include <gb/gb.h>

extern const uint8_t SCREEN_H;
extern const uint8_t SCREEN_W;
extern const uint8_t DEATH_ZONE_H;

typedef struct
{
    uint8_t x;
    uint8_t y;
} Vector2D;

typedef struct
{
    int8_t x;
    int8_t y;
} IVector2D;

typedef struct
{
    Vector2D position;
    Vector2D velocity;
    int8_t direction_x;
    uint8_t sprite_ids[3];
    uint8_t width;
    uint8_t height;
} Player;

typedef struct
{
    Vector2D position;
    Vector2D velocity;
    IVector2D direction;
    uint8_t sprite_id;
    uint8_t width;
    uint8_t height;
} Ball;