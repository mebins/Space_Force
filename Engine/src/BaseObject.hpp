//
//  BaseObject.hpp
//  Engine
//
//  Created by Mebin Skaria on 9/21/18.
//
#pragma once
#include "ofMain.h"


class BaseObject {
public:
    BaseObject();
    ofVec2f trans, scale;
    float rot;
    bool bSelected;
    void setPosition(ofVec2f pos){trans = pos;}
    void setScale(ofVec2f scal){scale = scal;}
};

