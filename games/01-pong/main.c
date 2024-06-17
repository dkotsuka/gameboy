#include <gb/gb.h>
#include "game/init_objects.h"
#include "game/start_game.h"
#include "globaldefs/globaldefs.h"

Object ball;
Object player;

void main(void)
{
    init_objects(&ball, &player);

    while (1)
    {
        start_game(&ball, &player);
        vsync();
    }
}