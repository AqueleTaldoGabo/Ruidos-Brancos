#pragma once
#include "raylib.h"
#include "tiro.h"
#include <time.h>
#include <iostream>
using namespace std;

struct player{
    int vida;
    clock_t start_time = clock();
    float x, y;
    int speedX, speedY;
    int dano;
    tiro *tir;
};

void updatePlayer(player *p){
    if(IsKeyDown(KEY_A)){
        p->x = p->x - p->speedX;
        if(p->x < 20){
            p->x = 20;
        }
    }
    if(IsKeyDown(KEY_D)){
        p->x = p->x + p->speedX;
        if(p->x + 20 > 480){
            p->x = 460;
        }
    }
    if(IsKeyDown(KEY_W)){
        p->y = p->y - p->speedY;
        if(p->y < 16){
            p->y = 16;
        }
    }
    if(IsKeyDown(KEY_S)){
        p->y = p->y + p->speedY;
        if(p->y + 20 > GetScreenHeight()){
            p->y = GetScreenHeight() - 20;
        }
    }
    if(IsKeyDown(KEY_J)){
        if (clock() > p->start_time + 750){
            p->tir = criaBala(p->x + 50, p->y, p->tir);
            p->start_time = clock();
        }
        
    }
    
    
}

void setVida(int vida, player *player){
    player->vida = vida;
    player->tir = NULL;
}

void setPlayerX(float X, player *player){
    player->x = X;
}

void setPlayerY(float Y, player *player){
    player->y = Y;
}
void setSpeedX(int X, player *player){
    player->speedX = X;
}

void setSpeedY(int Y, player *player){
    player->speedY = Y;
}

void drawPlayer(player *player, Texture2D texture2d, animation anim, Texture2D coracao, animation *anim2,int vida){
    DrawTexturePro(texture2d, animation_frame(&anim, 3), {player->x-25, player->y-25, 50, 50}, {0, 0}, 0, WHITE);
    int x = 20;
    for(int i = 0; i<vida; i++){
        x+=60;
        DrawTexturePro(coracao, animation_frame(anim2, 5), {GetScreenWidth()-x, 5, 50, 50}, {0, 0}, 0, WHITE);
    }
}