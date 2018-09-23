//
//  Emitter.cpp
//  Engine
//
//  Created by Mebin Skaria on 9/21/18.
//


#include "Emitter.hpp"
#include "ofMain.h"


Emitter::Emitter(string name, SpriteSystem* x)
{
    cout << "SPAWNED AN "+name+" IN COLLECTION : " + x-> name << endl;
    sys = x;
    last_spawn_time = 0;
    rate = 100;
}

void Emitter::update()
{
    if((ofGetCurrentTime().getAsMilliseconds()-last_spawn_time) >= rate)
    {
        last_spawn_time = ofGetCurrentTime().getAsMilliseconds();
        if(spawning)
        {
            Sprite* tmp = new Sprite();
            tmp -> set_image(childImage);
            tmp -> set_velocity(velocity);
            tmp -> set_lifespan(lifespan);
            tmp -> setPosition(trans);
            tmp -> setScale(ofVec2f(width,height));
            sys -> add(*(tmp));
            if(haveSound)
            {
              emitter_sound.play();
            }
            
        }
    }
}
void Emitter::draw()
{
    ofDrawRectangle(trans,50,50);
}
void Emitter::setLifespan(float x)
{
    lifespan = x;
}
void Emitter::setVelocity(ofVec3f x)
{
    velocity = x;
}
void Emitter::setRate(float x)
{
    rate = x;
}
void Emitter::start()
{
    spawning = true;
}
void Emitter::stop()
{
    spawning = false;
}
void Emitter::setChildImage(ofImage x)
{
    childImage = x;
}
void Emitter::setSound(ofSoundPlayer x)
{
    emitter_sound = x;
    haveSound = true;
}

