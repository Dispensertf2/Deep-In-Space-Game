//libraries
#include <raylib.h>
#include <iostream>
#include <vector>


//local headers
#include "draw.hpp"

const int tileScreenWidth = 25;
const int tileScreenHeight = 14;


int main(void) {
    
    
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Deep In Space - InDev");


    spriteSheet newSprite;
    newSprite.sprite = LoadTexture("./Assets/null.png");
    newSprite.width = 32;
    newSprite.height = 32;
    

    while (!WindowShouldClose())   
    {
       
        BeginDrawing();

            ClearBackground(BLACK);

            for (int y=0;y<14;y++) {
                for (int x=0;x<25;x++) {
                    drawSpriteRaw(newSprite,x*32,y*32);
                }
            }

        EndDrawing();
       
    }

   
    CloseWindow();       
    

    return 0;
}