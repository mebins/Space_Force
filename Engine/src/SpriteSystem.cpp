//
//  SpriteSystem.cpp
//  Engine
//
//  Created by Mebin Skaria on 9/21/18.
//

#include "SpriteSystem.hpp"

SpriteSystem::SpriteSystem(string x)
{
    name = x;
}

void SpriteSystem::add(Sprite x)
{
    x.name = name;
    sprites.push_back(x);
}
void SpriteSystem::remove(int x)
{
    sprites.erase(sprites.begin() + x);
}

void SpriteSystem::update()
{
    if(sprites.size() == 0) return;
    vector<Sprite>::iterator s = sprites.begin();
    vector<Sprite>::iterator tmp;
    
    while(s != sprites.end())
    {
        if(s-> lifespan != -1 && s-> age() > 1000)
        {

            tmp = sprites.erase(s);
            s = tmp;
        }
        else
        {
            s->update();
            s++;
        }
    }
}

void SpriteSystem::draw()
{
    for(int i = 0; i < sprites.size(); i++)
    {
        sprites[i].draw();
    }
}
