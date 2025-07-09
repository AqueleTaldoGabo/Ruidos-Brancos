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
    }
    if(IsKeyDown(KEY_D)){
        p->x = p->x + p->speedX;
    }
    if(IsKeyDown(KEY_W)){
        p->y = p->y - p->speedY;
    }
    if(IsKeyDown(KEY_S)){
        p->y = p->y + p->speedY;
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

void drawPlayer(player *player){
    DrawCircle(player->x, player->y, 50, GREEN);
}