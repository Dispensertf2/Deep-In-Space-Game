#include <raylib.h>



typedef struct object {
    spriteSheet sprite; 
    float x;
    float y;

    //properties
    float health = 10.f;
    
} object;

object generateObject(spriteSheet sprite, float x, float y);