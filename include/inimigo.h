#pragma once
#include "raylib.h"
#include "tiroIni.h"
#include <time.h>


struct combos{
    tiroIni *tir;
};

struct inimig{
    
    int vida;
    float x, y;
    clock_t start_time = clock();
    int speedX, speedY;
    combos combo[5];
    int numCombo = 0;
 
};



inimig *listaCombos(inimig *inim){
    int x = rand()%3;
    //for(int j = 0; j<5; j++){
            tiroIni *tiro = new tiroIni; 
        
        switch (x){

        case 0:
            tiro = NULL;
            for(int i = 0; i<rand()%5+1; i++){
                tiro = criaBala(inim->x-130, inim->y-90, tiro, 0+i, -6+i);
            }
            inim->combo[0].tir = tiro;
            break;
        case 1:
            tiro = NULL;
            for(int i = 0; i<rand()%5+1; i++){
                tiro = criaBala(inim->x-130, inim->y+90, tiro, 0-i, -6+i);
            }
            inim->combo[0].tir = tiro;
            break;
        case 2:
            tiro = NULL;
            for(int i = 0; i<rand()%5+1; i++){
                int y = rand()%2;
                if(y){
                    tiro = criaBala(inim->x-130, inim->y+15+45*i, tiro, 0, -6);
                }else{
                    tiro = criaBala(inim->x-130, inim->y-15-45*i, tiro, 0, -6);
                }
            }
            inim->combo[0].tir = tiro;
        }
    //}
    return inim;
}

inimig *updateInimigo(inimig *inim){
    if (clock() > inim->start_time + 2500){
        inim = listaCombos(inim);
        inim->start_time = clock();
    }
    return inim;
}


void setVida(int vida, inimig *inimigo){
    inimigo->vida = vida;
}

void setInimigoX(float X, inimig *inimigo){
    inimigo->x = X;
}

void setInimigoY(float Y, inimig *inimigo){
    inimigo->y = Y;
}

void drawInimigo(inimig *inimigo, Texture2D texture2d, animation anim, Texture2D text, animation ani){
    DrawTexturePro(texture2d, animation_frame2(&anim, 5), {inimigo->x-90, inimigo->y-174, 400, 400}, {0, 0}, 0, WHITE);
    DrawTexturePro(text, animation_frame2(&ani, 6), {inimigo->x-330, inimigo->y-204, 400, 400}, {0, 0}, 0, WHITE);
}

