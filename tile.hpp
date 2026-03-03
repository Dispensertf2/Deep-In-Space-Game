#include <raylib.h>
#include <iostream>

#include "draw.hpp"

typedef struct tile {
    //tile width and height are stored within sprite sheet
    spriteSheet tileSprite;
    float x; //position shit n what not 
    float y;

    //properties of tile
    float health = 10.f; //10 is highest health a tile can have
    float oxygen = 100.f; //100 is relative to 100%
    bool isDestroyed = false;
    bool isFlammable = false;


} tile;