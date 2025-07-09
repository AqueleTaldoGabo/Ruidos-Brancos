#pragma once
#include "raylib.h"
#include "animation.h"
#include <cstddef>

#include <iostream>
using namespace std;



struct tiroIni{
    float x, y;
    
    int speedX = -6, speedY= 0;
    tiroIni *prox;
    tiroIni *prev;
};

tiroIni *deleteBala(tiroIni *tiro, tiroIni *tir){
    tiroIni *Aux = tir;
    tiroIni *aux = tiro;
    tiroIni *Pro = tiro->prox;
    tiroIni *Ant = tiro->prev;
    while(aux != Aux){
        Ant = aux;
        aux = aux->prox;
        Pro = Pro->prox;
    }
    if(aux->prev == NULL){
        if(aux->prox != NULL){
            aux = aux->prox;
        }else{
            delete Aux;
            return NULL;
        }
        aux->prev = NULL;
        tiro = aux;
        
    }
    else if(aux->prox == NULL){
        if(aux->prev != NULL){
            aux = Ant;
        }else{
            delete Aux;
            return NULL;
        }
        aux->prox = NULL;
    }
    else{
        aux = Ant;
        aux->prox = Pro;
        Pro->prev = aux;
    }

    delete Aux;
    
    return tiro;
}

tiroIni *updateBalaINI(tiroIni *tir, float x, float y, int *vida){
    tiroIni *l = tir;
    while(l != NULL){
        l->x = l->x + l->speedX;
        l->y = l->y + l->speedY;

        if(CheckCollisionCircles(Vector2 {l->x, l->y}, 10, Vector2{x, y}, 25)){
            *vida = *vida-1;
            tir = deleteBala(tir, l);
            if(tir == NULL)
                break;
        }
        else if(l->x + 10 < 0){
            tir = deleteBala(tir, l);
            if(tir == NULL)
                break;
        }
        
        l = l->prox;
    }
    
    return tir;
}

void setBalaX(float X, tiroIni *tir){
    tir->x = X;
}

void setBalaY(float Y, tiroIni *tir){
    tir->y = Y;
}

tiroIni *criaBala(float x, float y, tiroIni *tir, int speedy, int speedx){
    tiroIni *n = new tiroIni();
    tiroIni *l = tir;
    n->prev = NULL;
    n->prox = NULL;
    setBalaX(x, n);
    n->speedY = speedy;
    n->speedX = speedx;
    setBalaY(y, n);
    if(tir == NULL){
        tir = n;
    }
    else{
        n->prev = l;
        while (l->prox != NULL){
            l = l->prox;
        }
        l->prox = n;
    }
    return tir;
}

void setSpeedX(int x, tiroIni *tir){
    tir->speedX = x;
}


void setSpeedY(int x, tiroIni *tir){
    tir->speedY = x;
}

void drawBala(tiroIni *tir, Texture2D texture2d, animation anim){
    tiroIni *l = tir;
    while(l != NULL){
        DrawTexturePro(texture2d, animation_frame(&anim, 2), {l->x-17, l->y-17, 35, 35}, {0, 0}, 0, WHITE);
        l = l->prox;
    }
}
