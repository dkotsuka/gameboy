#include "start_game.h"

void start_game(Object *ball, Object *player)
{
    control_player(player);
    move_ball(ball, player);
}
