//
//  Player.cpp
//  Engine
//
//  Created by Mebin Skaria on 9/22/18.
//

#include "Player.hpp"

Player::Player(string x, SpriteSystem* y)
{
    name = x;
    sys = y;
    gun = new Emitter("Player's Gun", sys);
    rate = 260;
    speed = 40;
    ofVec2f bullet_velocity = ofVec2f(0,-330);
    player_sprites[0].load("images/player_1.png");
    player_sprites[1].load("images/player_2.png");
    player_sprites[2].load("images/player_3.png");
    player_sprites[3].load("images/player_4.png");
    bullet.load("images/bullet.png");
    bullet_sound.load("sound/bullet_sound.wav");
    player_sprite = player_sprites[0];
    gun-> setRate(rate);
    gun-> setChildImage(bullet);
    gun-> setSound(bullet_sound);
    gun-> setVelocity(bullet_velocity);
}

void Player::update()
{
   // cout << velocity << endl;
    gun-> setPosition(trans);
    gun-> update();
    Sprite::update();
    movement_animation();
    window_bound_check();
    movement_decay();
}
void Player::draw()
{
    player_sprite.draw(trans, 50,110);
}

void Player::movement_animation()
{
    if((ofGetCurrentTime().getAsMilliseconds()- flame_animation_last_change) > flame_animation_rate)
    {
        flame_animation_last_change = ofGetCurrentTime().getAsMilliseconds();
        if(player_movement_animation_index+1 > 3)
        {
            player_movement_animation_index = 0;
        }
        else
        {
            player_movement_animation_index++;
        }
        player_sprite = player_sprites[player_movement_animation_index];
    }
    
}
void Player::keypressed_logic(int key)
{
    switch(key)
    {
        case '[':{bullet_velocity = bullet_velocity + ofVec2f(0, 10);     gun-> setVelocity(bullet_velocity); cout << bullet_velocity << endl; }
            break;
        case ']':{bullet_velocity = bullet_velocity + ofVec2f(0,-10);     gun-> setVelocity(bullet_velocity);cout << bullet_velocity << endl;}
            break;
        case '-': {rate += 10; gun->setRate(rate); cout << rate << endl;}
            break;
        case '=': {rate -= 10; gun->setRate(rate); cout << rate << endl;}
            break;
        case 'w': up();
            break;
        case 's': down();
            break;
        case 'a': left();
            break;
        case 'd': right();
            break;
        case ' ': gun->start();
            break;
    }
}
void Player::keyreleased_logic(int key)
{
    switch(key)
    {
        case ' ': gun->stop();
            break;
    }
}
void Player::window_bound_check()
{
    if(trans.y <= 0)
    {
        velocity.y = 0;
        trans.y = 0;
    }
    if(trans.y + height >= ofGetWindowHeight())
    {
        velocity.y = 0;
        trans.y = ofGetWindowHeight() - height;
    }
    if(trans.x + width >= ofGetWindowWidth())
    {
        velocity.x = 0;
        trans.x = ofGetWindowWidth() - width;
    }
    if(trans.x <= 0)
    {
        trans.x = 0;
        velocity.x = 0;
    }
    
}

void Player::up(){
       velocity= velocity - ofVec2f(0,speed);
}
void Player::down(){
     velocity= velocity - ofVec2f(0, -speed);
}
void Player::left(){
    velocity= velocity - ofVec2f(speed, 0);
};
void Player::right(){
    velocity= velocity - ofVec2f(-speed, 0);
};

void Player::movement_decay()
{
    if(velocity.x > 0)
    {
        velocity.x = velocity.x - 10/ofGetFrameRate();
    }
    if(velocity.y > 0)
    {
        velocity.y = velocity.y - 10/ofGetFrameRate();
    }
    if(velocity.x < 0)
    {
        velocity.x = velocity.x + 10/ofGetFrameRate();
    }
    if(velocity.y < 0)
    {
        velocity.y = velocity.y + 10/ofGetFrameRate();
    }
}


