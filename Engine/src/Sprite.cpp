//
//  Sprite.cpp
//  Engine
//
//  Created by Mebin Skaria on 9/21/18.
//

#include "Sprite.hpp"

Sprite::Sprite()
{
    width = 50;
    height = 110;
    lifespan = 1000;
    speed = 0;
    velocity = ofVec2f(0,0);
    birthtime = ofGetCurrentTime().getAsMilliseconds();
    has_image = false;
    name = "unset name";
}

void Sprite::draw(){
        if(has_image)
        {
            image.draw(trans,width,height);
        }
        else
        {
            ofDrawRectangle(trans,width,height);
        }
    
}

void Sprite::update(){
    trans+= velocity / ofGetFrameRate();
}

float Sprite::age(){
    return ofGetCurrentTime().getAsMilliseconds() - birthtime;
}
