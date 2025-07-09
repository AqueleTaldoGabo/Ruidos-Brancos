#include "include/raylib.h"
#include "include/inimigo.h"
#include "include/player.h"


const int screenWidth = 800;
const int screenHeight = 450;

void menu(){
    DrawText("Ruidos brancos", (screenWidth/2)-(screenWidth/5), screenHeight/4, 40, WHITE);
    DrawText("Aperte espaço para continuar", (screenWidth/2)-(screenWidth/4.7), screenHeight/1.5, 20, WHITE);
}
void morte1(){
    DrawText("MORREU", (screenWidth/2)-(screenWidth/6.2), screenHeight/2.75, 60, WHITE);
    
    ClearBackground(BLACK);

}
void morte2(){
    DrawText("DERROTOU", (screenWidth/2)-(screenWidth/5), screenHeight/2.75, 60, WHITE);
    
    ClearBackground(BLACK);

}

int main(void)
{
    srand(time(NULL));
    inimig *inim = new inimig;
    player *play = new player;
    int vida = 3;
    bool começo = true;
    bool morte = false;
    bool morteBoss = false;
    clock_t start_time = clock();

    InitWindow(screenWidth, screenHeight, "TESTE-TESTE");
    SetTargetFPS(60);
    Texture2D projetilMago = LoadTexture("assets/mago/projetil_mago_tileset.png");
    Texture2D mago = LoadTexture("assets/mago/mago_tileset.png");
    Texture2D boss = LoadTexture("assets/boss/boss_tileset.png");
    Texture2D projetilBoss = LoadTexture("assets/boss/projetil_boss_1.png");
    Texture2D espelhoBoss = LoadTexture("assets/boss/espelho_tileset.png");
    animation anim = (animation){
        .first = 0,
        .last = 3,
        .cur = 0,
        .speed = 0.1,
        .duration_left = 0.2
    };
    animation anim2 = (animation){
        .first = 0,
        .last = 2,
        .cur = 0,
        .speed = 0.1,
        .duration_left = 0.3
    };
    animation anim3 = (animation){
        .first = 0,
        .last = 5,
        .cur = 0,
        .speed = 0.1,
        .duration_left = 0.5
    };
    animation anim4 = (animation){
        .first = 0,
        .last = 1,
        .cur = 0,
        .speed = 0.1,
        .duration_left = 0.2
    };
    animation anim5 = (animation){
        .first = 0,
        .last = 5,
        .cur = 0,
        .speed = 0.1,
        .duration_left = 0.7
    };
    while (!WindowShouldClose())   
    {
        

        // Update
        //----------------------------------------------------------------------------------
        if(!começo){
            updatePlayer(play);
            animation_update(&anim);
            animation_update(&anim2);
            animation_update(&anim3);
            animation_update(&anim4);
            animation_update(&anim5);
            play->tir = updateBala(play->tir, inim);
            inim->combo[inim->numCombo].tir = updateBalaINI(inim->combo[inim->numCombo].tir, play->x, play->y, &vida);
            inim = updateInimigo(inim);
            if(vida <= 0){
                começo = !começo;
                morte = !morte;
                start_time = clock();
            }
            if(inim->vida <= 0){
                começo = !começo;
                morteBoss = !morteBoss;
                start_time = clock();
            }
        }else{
            if(IsKeyDown(KEY_SPACE) && !morte && !morteBoss){
                começo = !começo;
                vida = 3;
                setVida(vida, play);
                setVida(25, inim);
                setInimigoX((float)(screenWidth - 180), inim);
                setInimigoY((float)(screenHeight/2), inim);

                
                setPlayerX(screenWidth/4, play);
                setPlayerY(screenHeight/2, play);
                setSpeedX(4, play);
                setSpeedY(4, play);
                while(inim->combo[inim->numCombo].tir != NULL)
                    inim->combo[inim->numCombo].tir = deleteBala(inim->combo[inim->numCombo].tir, inim->combo[inim->numCombo].tir);
            }
        }
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            if(começo){
                ClearBackground(BLACK);
                if(morte){

                    morte1();
                    if(clock() > start_time + 3000)
                        morte = !morte;
                }else if(morteBoss){
                    morte2();
                    if(clock() > start_time + 3000)
                        morteBoss = !morteBoss;
                }else{
                    menu();
                }
            }else{
                ClearBackground(BLACK);
                drawInimigo(inim, boss, anim3, espelhoBoss, anim5);
                drawPlayer(play, mago, anim2);
                drawBalaP(play->tir, projetilMago, anim);
                for(int i = 0; i<5; i++)
                    drawBala(inim->combo[i].tir, projetilBoss, anim4);
            }
        EndDrawing();
        //----------------------------------------------------------------------------------
    
    }

    UnloadTexture(projetilMago);
    UnloadTexture(mago);
    UnloadTexture(boss);
    UnloadTexture(projetilBoss);
    UnloadTexture(espelhoBoss);
    CloseWindow();

    return 0;
}

