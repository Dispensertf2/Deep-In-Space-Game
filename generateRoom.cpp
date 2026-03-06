#include <vector>
#include <raylib.h>

#include "draw.hpp"
#include "tile.hpp"
#include "generateRoom.hpp"




//generates square room
std::vector<tile> generateRoom(spriteSheet texture, float startX, float startY, int width, int height, int doorFacing = 0) {
    std::vector<tile> roomBuffer;
    spriteSheet textureBuffer = texture;
    
    for (int y=0;y<height;y++) { //for loop to generate the floor
        for (int x=0;x<width;x++) {
            roomBuffer.push_back(generateTile(textureBuffer,startX+(x*32),startY+(y*32)));
        }
    }

    if (textureBuffer.columns > 1) { //a sort of wall check almost for tiles because every single wall tile will be on index 1
        textureBuffer.indexX += 1;
        for (int y=0;y<height+2;y++) { //for loop to generate the floor
            for (int x=0;x<width+2;x++) {
                if (y == 0 || y == height+1) {

                    roomBuffer.push_back(generateTile(textureBuffer,(startX-32)+(x*32),(startY-32)+(y*32)));
                }
                else {
                    if (x == 0 || x == width+1) {
                        roomBuffer.push_back(generateTile(textureBuffer,(startX-32)+(x*32),(startY-32)+(y*32)));
                    }
                }
                
                
            }
        }
        if (textureBuffer.columns > 2) {
            textureBuffer.indexX += 1;
            if (doorFacing == 0) { //north goes clock wise
                roomBuffer.push_back(generateTile(textureBuffer,startX+((width)/2)*32,(startY-1)*32));

            }
            if (doorFacing == 2) {
                roomBuffer.push_back(generateTile(textureBuffer,startX+((width)/2)*32,startY+(height)*32));
            }
        }
    }


    return roomBuffer;
}