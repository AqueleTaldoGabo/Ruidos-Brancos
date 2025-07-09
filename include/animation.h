#pragma once

#include <raylib.h>

typedef struct animation{
    int first;
    int last;
    int cur;

    float speed;
    float duration_left;
};

Rectangle animation_frame(animation *anima, int num_frames){
    float x = (anima->cur % num_frames) * 16;
    float y = (anima->cur / num_frames) * 16;

    return (Rectangle){
        .x = x,
        .y = y,
        .width = 16,
        .height = 16
    };
}
Rectangle animation_frame2(animation *anima, int num_frames){
    float x = (anima->cur % num_frames) * 128;
    float y = (anima->cur / num_frames) * 128;

    return (Rectangle){
        .x = x,
        .y = y,
        .width = 128,
        .height = 128
    };
}

void animation_update(animation *anima){
    float dt = GetFrameTime();
    anima->duration_left -= dt;

    if(anima->duration_left <= 0){
        anima->duration_left = anima->speed;
        anima->cur++;
        if(anima->cur > anima->last){
            anima->cur = anima->first;
        }
    }
}