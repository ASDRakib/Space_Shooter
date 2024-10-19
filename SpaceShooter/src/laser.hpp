#pragma once
#include<raylib.h>

class Laser{
    public:
      Laser(Vector2 position, int speed);
      void Draw();
      void  Update();
      Rectangle GetRect();
      bool active;
      float lastTime;

    private:
       Vector2 position;
       int speed;


       
};