#include <raylib.h>
#include <vector>
#include <iostream>

//I will do this later
/*
typedef struct item {

} Item;
*/


typedef struct object {
    spriteSheet sprite; 
    float x;
    float y;

    //properties
    float health = 10.f;
    
} object;

typedef struct npc {
    spriteSheet sprite; 
    float x;
    float y;

    //path finding junk
    Vector2 destination = {0, 0};
    std::string mode = "Roaming";

} npc;

object generateObject(spriteSheet sprite, float x, float y);

npc generateNPC(spriteSheet sprite, float x, float y);