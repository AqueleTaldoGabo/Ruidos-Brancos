#include "include/raylib.h"
#include "include/inimigo.h"
#include "include/player.h"

const int screenWidth = 800;
const int screenHeight = 450;

int main(void)
{
    inimigo *inim = new inimigo;
    player *play = new player;


    setVida(3, inim);
    setX(screenWidth/1.5, inim);
    setY(screenHeight/2, inim);

    setVida(3, play);
    setX(screenWidth/4, play);
    setY(screenHeight/2, play);


    InitWindow(screenWidth, screenHeight, "TESTE-TESTE");
    SetTargetFPS(60);

    while (!WindowShouldClose())   
    {
        // Update
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("TESTEEEEEEEE!", 190, 200, 20, LIGHTGRAY);
            drawInimigo(inim);
            drawPlayer(play);
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    CloseWindow();

    return 0;
}

