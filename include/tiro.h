#pragma once
#include "raylib.h"
#include "inimigo.h"
#include "animation.h"
#include <cstddef>
#include <iostream>
using namespace std;



struct tiro{
    float x, y;
    int speedX = 6, speedY= 0;
    tiro *prox;
    
};

tiro *deleteBala(tiro *tir){
    tiro *Aux = tir;
    tir = tir->prox;
    cout << Aux << " " << tir << endl;
    delete Aux;

    return tir;
}

tiro *updateBala(tiro *tir, inimig *inim){
    tiro *l = tir;
    while(l != NULL){
        l->x = l->x + l->speedX;
        l->y = l->y - l->speedY;
        if(CheckCollisionCircles(Vector2 {tir->x, tir->y}, 10, Vector2{inim->x, inim->y}, 100)){
            inim->vida--;
            cout << inim->vida << endl;
            tir = deleteBala(tir);
        }
        if(l->x - 10 > GetScreenWidth()){
            tir = deleteBala(tir);
        }
        
        l = l->prox;
    }
    return tir;
}

void setBalaX(float X, tiro *tir){
    tir->x = X;
}

void setBalaY(float Y, tiro *tir){
    tir->y = Y;
}

tiro *criaBala(float x, float y, tiro *tir){
    tiro *n = new tiro();
    tiro *l = tir;
    setBalaX(x, n);
    setBalaY(y, n);

    if(tir == NULL){
        tir = n;
    }
    else{
        while (l->prox != NULL){
            l = l->prox;
        }
        l->prox = n;
        
    }
    return tir;
}

void setSpeedX(int x, tiro *tir){
    tir->speedX = x;
}


void setSpeedY(int x, tiro *tir){
    tir->speedY = x;
}

void drawBalaP(tiro *tir, Texture2D texture2d, animation anim){
    tiro *l = tir;
    while(l != NULL){
        DrawTexturePro(texture2d, animation_frame(&anim, 4), {tir->x, tir->y-5, 35, 35}, {0, 0}, 0, WHITE);
        l = l->prox;
    }
}
