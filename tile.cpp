#include "draw.hpp"
#include "tile.hpp"

tile generateTile(spriteSheet tileSprite, float x, float y) {
    tile newTile;
    newTile.tileSprite = tileSprite;
    newTile.x = x;
    newTile.y = y;

    return newTile;
}