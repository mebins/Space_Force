//
//  BaseObject.cpp
//  Engine
//
//  Created by Mebin Skaria on 9/22/18.
//

#include "BaseObject.hpp"

BaseObject::BaseObject()
{
    trans = ofVec2f();
    scale = ofVec2f(60,60);
    bSelected = false;
    rot = 0;
}

