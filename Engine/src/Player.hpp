//
//  Player.hpp
//  Engine
//  I decided the player should have an Emitter, instead of being a emitter.
//  This just seems like the most "natural and realistic" way to make the relationship
//  Created by Mebin Skaria on 9/22/18.
//

#pragma once

#include "BaseObject.hpp"
#include "Emitter.hpp"
#include "SpriteSystem.hpp"
#include "ofMain.h"
class Player: public Sprite {
public:
    string name;
    Player(string, SpriteSystem*);
    ofImage player_sprite;
    Emitter* gun;
    ofImage bullet;
    ofSoundPlayer bullet_sound;
    ofVec2f bullet_velocity;
    void up();
    void down();
    void left();
    void right();
    void keypressed_logic(int key);
    void keyreleased_logic(int key);
    void update();
    void draw();
    SpriteSystem* sys;
    ofImage player_sprites[4];
    float flame_animation_rate = 50;
    float flame_animation_last_change= 0;
    float rate;
    void movement_animation();
    int player_movement_animation_index = 4;
    void window_bound_check();
    void movement_decay();
};


