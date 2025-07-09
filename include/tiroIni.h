#pragma once
#include "raylib.h"
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

        if(CheckCollisionCircles(Vector2 {l->x, l->y}, 10, Vector2{x, y}, 50)){
            *vida = *vida-1;
            cout << *vida << endl;
            tir = deleteBala(tir, l);
            if(tir == NULL)
                break;
            cout << "vapo" << endl;
        }
        else if(l->x + 10 < 0){
            tir = deleteBala(tir, l);
            if(tir == NULL)
                break;
            cout << "vambora" << endl;
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

void drawBala(tiroIni *tir){
    tiroIni *l = tir;
    while(l != NULL){
        DrawCircle(l->x, l->y, 10, YELLOW);
        l = l->prox;
    }
}
