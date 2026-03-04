#include "draw.hpp"
#include "entity.hpp"

object generateObject(spriteSheet sprite, float x, float y) {
    object newObject;
    newObject.sprite = sprite;
    newObject.x = x;
    newObject.y = y;

    return newObject;
}