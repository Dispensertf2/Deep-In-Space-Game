#include "draw.hpp"
#include "entity.hpp"

object generateObject(spriteSheet sprite, float x, float y) {
    object newObject;
    newObject.sprite = sprite;
    newObject.x = x;
    newObject.y = y;

    return newObject;
}

npc generateNPC(spriteSheet sprite, float x, float y) {
    npc newNPC;
    newNPC.sprite = sprite;
    newNPC.x = x;
    newNPC.y = y;

    return newNPC;
}