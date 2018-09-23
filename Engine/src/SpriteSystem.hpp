//
//  SpriteSystem.hpp
//  Engine
//
//  Created by Mebin Skaria on 9/21/18.
//

#pragma once
#include "Sprite.hpp"

class SpriteSystem {
public:
    int object_count;
    string name; 
    SpriteSystem(string);
    void add(Sprite);
    void remove(int);
    void update();
    void draw();
    vector<Sprite> sprites;
};
