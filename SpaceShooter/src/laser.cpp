#include "laser.hpp"
#include<iostream>
Laser::Laser(Vector2 position, int speed){
    this->position = position;
    this->speed = speed;
    active  = true;
    
}


void Laser::Draw(){
    if(active){
    DrawRectangle(position.x,position.y, 4, 15,{255,165,0,255});
  
}
}

Rectangle Laser::GetRect()
{
    Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.width = 4;
    rect.height = 15;
    return rect;
}

void Laser::Update(){
    
    position.y += speed;
    if(position.y > GetScreenHeight() -100 || position.y < 25){
        active = false;

    }

}



