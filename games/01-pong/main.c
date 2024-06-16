#include <gb/gb.h>
#include "game/init_objects.h"
#include "game/start_game.h"

void main(void)
{
    init_objects();

    while (1)
    {
        start_game();
        vsync();
    }
}