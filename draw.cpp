#include "draw.hpp"


void drawSpriteRaw(spriteSheet sprite, float x, float y, float indexX, float indexY, float scale, float rotation, Color tint) {
    DrawTexturePro(
        sprite.sprite, //gets sprite info from sprite structure
        {(sprite.width * indexX), (sprite.height * indexY), sprite.width, sprite.height}, //gets the sprite from sprite sheet
        {x,y,sprite.width*scale, sprite.height*scale}, //position to display sprite on screen
        {0,0}, //sprite origin
        rotation, //self explanitory
        tint // yada yada

    );
}