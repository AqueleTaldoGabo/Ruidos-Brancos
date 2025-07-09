#include "include/raylib.h"
#include "include/inimigo.h"
#include "include/player.h"


const int screenWidth = 800;
const int screenHeight = 450;

int main(void)
{
    inimig *inim = new inimig;
    player *play = new player;
    int vida = 3;


    setVida(3, inim);
    setInimigoX(screenWidth/1.5, inim);
    setInimigoY(screenHeight/2, inim);

    setVida(vida, play);
    setPlayerX(screenWidth/4, play);
    setPlayerY(screenHeight/2, play);
    setSpeedX(4, play);
    setSpeedY(4, play);


    InitWindow(screenWidth, screenHeight, "TESTE-TESTE");
    SetTargetFPS(60);
    Texture2D projetil = LoadTexture("assets/projetil/projetil_mago_tileset.png");
    animation anim = (animation){
        .first = 0,
        .last = 3,
        .cur = 0,
        .speed = 0.1,
        .duration_left = 0.1
    };
    while (!WindowShouldClose())   
    {
        // Update
        //----------------------------------------------------------------------------------
        updatePlayer(play);
        animation_update(&anim);
        play->tir = updateBala(play->tir, inim);
        inim->combo[inim->numCombo].tir = updateBalaINI(inim->combo[inim->numCombo].tir, play->x, play->y, &vida);
        inim = updateInimigo(inim);
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            drawInimigo(inim);
            drawPlayer(play);
            drawBalaP(play->tir, projetil, anim);
            for(int i = 0; i<5; i++)
                drawBala(inim->combo[i].tir);
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    UnloadTexture(projetil);
    CloseWindow();

    return 0;
}

