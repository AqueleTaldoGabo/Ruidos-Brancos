#include "raylib.h"

struct inimigo{
    int vida;
    float x, y;
    int speedX, speedY;
    //no *Ataque;
};


void setVida(int vida, inimigo *inimigo){
    inimigo->vida = vida;
}

void setX(float X, inimigo *inimigo){
    inimigo->x = X;
}

void setY(float Y, inimigo *inimigo){
    inimigo->y = Y;
}

void drawInimigo(inimigo *inimigo){
    DrawCircle(inimigo->x, inimigo->y, 100, BLUE);
}
