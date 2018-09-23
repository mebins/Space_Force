//
//  Sprite.hpp
//  Engine
//
//  Created by Mebin Skaria on 9/21/18.
//
#pragma once
#include "ofMain.h"
#include "BaseObject.hpp"

class Sprite: public BaseObject{
public:
    Sprite();
    Sprite(float,float);
    float width, height;
    float lifespan, birthtime;
    float speed;
    ofVec2f velocity;
    bool has_image;
    ofImage image;
    string name;
    
    void set_name(string x) {name = x;}
    void set_width(float x) {width = x;}
    void set_height(float x){height = x;}
    void set_lifespan(float x){lifespan = x;}
    void set_birthtime(float x){birthtime = x;}
    void set_speed(float x) {speed = x;}
    void set_velocity(ofVec2f x) {velocity = x;}
    void set_image(ofImage x) {image = x; has_image = true;}
    bool get_hasImage() {return has_image;}
    void draw();
    void update();
    float age();
};

