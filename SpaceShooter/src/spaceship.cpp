#include "spaceship.hpp"
#include <iostream> 

Spaceship::Spaceship() {
    image = LoadTexture("Graphics/spaceship.png");
    position.x = (GetScreenWidth() - image.width) / 2;
    position.y = GetScreenHeight() - image.height - 100;
    lastFireTime = 0.0;
    lastPowerUpTime = 0.0; 
    isPoweredUp = false; 
    laserSound = LoadSound("Sounds/laser.ogg");
}

Spaceship::~Spaceship() {
    UnloadTexture(image);
    UnloadSound(laserSound);
}

void Spaceship::Draw() {
    DrawTextureV(image, position, WHITE);
}

void Spaceship::MoveLeft() {
    position.x -= 6;
    if (position.x < 25) {
        position.x = 25;
    }
}

void Spaceship::MoveRight() {
    position.x += 6;
    if (position.x > GetScreenWidth() - image.width - 25) {
        position.x = GetScreenWidth() - image.width - 25;
    }
}

void Spaceship::MoveUp() {
    position.y -= 6;

}

void Spaceship::MoveDown() {
    position.y += 6;
    if(position.y > GetScreenHeight() -  image.height - 70) {
        position.y = GetScreenHeight() - image.height - 70;
        }
}

void Spaceship::FireLaser() {
    if (GetTime() - lastFireTime >= (isPoweredUp ? 0.15 : 0.35)) { 
        lasers.push_back(Laser({position.x + image.width / 2 - 2, position.y}, -6)); 

        if (isPoweredUp) {
            lasers.push_back(Laser({position.x + image.width / 2 - 10, position.y}, -6)); 
        }

        lastFireTime = GetTime();
        PlaySound(laserSound);
    }
}

Rectangle Spaceship::GetRect() {
    return {position.x, position.y, float(image.width), float(image.height)};
}

void Spaceship::Reset() {
    position.x = (GetScreenWidth() - image.width) / 2;
    position.y = GetScreenHeight() - image.height - 100;
    lasers.clear();
}

void Spaceship::Update() {
    // Manage power-up state
    if (GetTime() - lastPowerUpTime >= 5) { 
        isPoweredUp = true; 
        lastPowerUpTime = GetTime(); 
    }
    
    if (isPoweredUp && GetTime() - lastPowerUpTime >= 2) { 
        isPoweredUp = false; 
    }
}
