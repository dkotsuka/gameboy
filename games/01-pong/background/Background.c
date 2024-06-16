#include "Background.h"
#include "../assets/Wall.h"
#include "../assets/BackgroundMap.h"

void render_background(void)
{
    set_bkg_data(0, 6, Wall);
    set_bkg_tiles(0, 0, 20, 18, Background);

    SHOW_BKG;
    DISPLAY_ON;
}