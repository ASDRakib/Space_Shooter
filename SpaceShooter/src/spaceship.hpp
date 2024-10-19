#pragma once
#include<raylib.h>
#include "laser.hpp"
#include<vector>

class Spaceship{
    public:
    Spaceship();
    ~Spaceship();
    void Draw();
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
    void FireLaser();
    void Update();
    Rectangle  GetRect();
    void Reset();
    
    std::vector<Laser> lasers;
    private:
    Texture2D image;
    Vector2 position;
    double lastFireTime;
    float lastPowerUpTime; 
    bool isPoweredUp; 
    Sound laserSound;
};