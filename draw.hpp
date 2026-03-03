#include <raylib.h>
#include <iostream>

typedef struct spriteSheet {
    Texture2D sprite;
    float width;
    float height;
    float rows = 1; //just defaults the sprite sheet to single row and column
    float columns = 1;

} Sprite;

void drawSpriteRaw(spriteSheet sprite, float x, float y, float indexX = 0.f, float indexY = 0.f, float scale = 1.f, float rotation = 0.f, Color tint = WHITE);