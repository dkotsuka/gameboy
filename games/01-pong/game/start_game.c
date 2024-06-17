#include "start_game.h"

void start_game(Object *ball)
{
    control_player();
    start_ball_movement(ball);
}