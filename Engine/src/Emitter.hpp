//
//  Emitter.hpp
//  Engine
//
//  Created by Mebin Skaria on 9/21/18.
//
#pragma once
#include "BaseObject.hpp"
#include "ofMain.h"
#include "SpriteSystem.hpp"

class Emitter: public BaseObject{
public:
    Emitter(string name, SpriteSystem *);
    SpriteSystem *sys;
    void update();
    void draw();
    void setLifespan(float);
    void setVelocity(ofVec3f);
    void setChildImage(ofImage);
    void setImage(ofImage);
    void setRate(float);
    void start();
    void stop();
    void setSound(ofSoundPlayer);
    ofSoundPlayer emitter_sound;
    string name;
    float rate;
    ofImage emitterImage;
    ofImage childImage;
    ofVec3f velocity;
    float lifespan;
    bool spawning;
    bool haveSound = false;
    float last_spawn_time;
    bool haveChildImage;
    bool haveImage;
    float width,height; 
    
};
