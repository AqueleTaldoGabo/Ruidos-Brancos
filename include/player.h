#include "raylib.h"

struct player{
    int vida;
    float x, y;
    int speedX, speedY;
    int dano;
};


void setVida(int vida, player *player){
    player->vida = vida;
}

void setX(float X, player *player){
    player->x = X;
}

void setY(float Y, player *player){
    player->y = Y;
}

void drawPlayer(player *player){
    DrawCircle(player->x, player->y, 50, GREEN);
}