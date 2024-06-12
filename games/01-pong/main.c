#include <gb/gb.h>
#include "global/screen.h"
#include "player/render.h"
#include "player/move.h"
#include "assets/Ball.h"

void main(void)
{
    render_player();

    while (1)
    {
        move_player();

        delay(3);
    }
}