//libraries
#include <raylib.h>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>


//local headers
#include "draw.hpp"
#include "tile.hpp"
#include "entity.hpp"

const int tileScreenWidth = 25;
const int tileScreenHeight = 14;
const int tileSize = 32;

std::vector<tile> world; //array for world tiles and nothing else
std::vector<object> objects; //array for objects such as plants and work benches 

bool getCollision(Rectangle a, Rectangle b) { //obviously copied collision code
    if (a.x + a.width >= b.x &&     // r1 right edge past r2 left
        a.x <= b.x + b.width &&       // r1 left edge past r2 right
        a.y + a.height >= b.y &&       // r1 top edge past r2 bottom
        a.y <= b.y + b.height) {       // r1 bottom edge past r2 top
        return true;
    }
    return false;

}


int main(void) {
    
    
    const int screenWidth = 800;
    const int screenHeight = 450;

    int currentScene = 0; //0 = world

    InitWindow(screenWidth, screenHeight, "Deep In Space - InDev");

    //initializes camera
    Camera2D camera = { 0 };
    camera.target = {0,0};
    camera.offset = {screenWidth/2.0f,screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    //loads in null texture not final
    spriteSheet newSprite;
    newSprite.sprite = LoadTexture("./Assets/null.png");
    newSprite.width = tileSize;
    newSprite.height = tileSize;

    spriteSheet cursorSprite;
    cursorSprite.sprite = LoadTexture("./Assets/cursor.png");
    cursorSprite.width = tileSize;
    cursorSprite.height = tileSize;

    spriteSheet plant;
    plant.sprite = LoadTexture("./Assets/testentity.png");
    plant.width = tileSize;
    plant.height = tileSize;

    //just for testing world array
    world.push_back(generateTile(newSprite,0,0));

    objects.push_back(generateObject(plant, 32, 0));

    float cameraX = 0.0f;
    float cameraY = 0.0f;
    float cameraSpeed = 200.0f;

    float dt = GetFrameTime();

    Rectangle cursorRect = {0,0,32,32};

    

    while (!WindowShouldClose())   
    {
        dt = GetFrameTime();


        if (currentScene == 0) { //all world controls go in here
            if (IsKeyDown(KEY_LEFT)) cameraX -= dt*cameraSpeed;
            else if (IsKeyDown(KEY_RIGHT)) cameraX += dt*cameraSpeed;
            if (IsKeyDown(KEY_UP)) cameraY -= dt*cameraSpeed;
            else if (IsKeyDown(KEY_DOWN)) cameraY += dt*cameraSpeed;

            if (IsKeyPressed(KEY_LEFT_BRACKET)) camera.zoom -= 0.5;
            else if (IsKeyPressed(KEY_RIGHT_BRACKET)) camera.zoom += 0.5;

            

        }
        
        Rectangle cursorRect = { (round(cameraX/tileSize)*tileSize)+1,(round(cameraY/tileSize)*tileSize)+1,30,30};
        
        camera.target = {cameraX, cameraY};
       
        BeginDrawing();

            ClearBackground(BLACK);

            BeginMode2D(camera); //Everything that needs to be rendered by camera is done in here
                if (currentScene == 0) {
                    for (int t=0;t<world.size();t++) { //iterates through each tile and draws it
                        drawSpriteRaw(world[t].tileSprite,world[t].x,world[t].y);
                        
                    }
                    for (int o=0;o<objects.size();o++) { //iterates through each object and draws it
                        drawSpriteRaw(objects[o].sprite,objects[o].x,objects[o].y);
                        
                    }
                    drawSpriteRaw(cursorSprite,cursorRect.x-1,cursorRect.y-1);

                }
            

            EndMode2D();
            

            std::cout << GetFPS() << std::endl;



        EndDrawing();
       
    }

    

    CloseWindow();       
    

    return 0;
}



