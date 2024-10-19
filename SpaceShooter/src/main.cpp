#include<raylib.h>
#include "game.hpp"
#include<string>

std::string FormatWidthleadingZeros(int number,  int width) {
  std::string numberText = std::to_string(number);
       int leadingZeros =  width - numberText.length();
      return  numberText = std ::string(leadingZeros,'0') + numberText;

}


int main(){
    Color grey = {29,29,27,255};
    Color yellow = {243,216,63,255};
    int offset  = 50;
    int windowwidth = 750;
    int windowheight = 700;

    InitWindow(windowwidth + offset ,  windowheight + 2 * offset , "SpaceShooter");
    InitAudioDevice();
    Font font =  LoadFontEx("Font/monogram.ttf",64,0,0);
    Texture2D spaceshipImage = LoadTexture("Graphics/spaceship.png");

    SetTargetFPS(60);

    Game game;
    
  

  
    while(WindowShouldClose()== false){
        UpdateMusicStream(game.music);
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        DrawRectangleRoundedLines({10,10,780,780}, 0.18f, 20, 2, yellow);
        DrawLineEx({25,730},{775,730},3,yellow);
        if(game.run){
        DrawTextEx(font, "LEVEL 01", {570,740},34,2,yellow);
        }
        else{
          DrawTextEx(font, "GAME OVER", {350,740},34,2,yellow);
        }
        
       float x = 50.0;
       for(int i = 0; i < game.lives; i++ ){
          DrawTextureV(spaceshipImage, {x,745},  WHITE);
           x += 50;

       }

       DrawTextEx(font, "SCORE", {50,15},34,2,yellow);
       std::string scoreText  = FormatWidthleadingZeros(game.score, 5);
       DrawTextEx(font, scoreText.c_str(),{50,40},34,2,yellow);
       
       DrawTextEx(font,"HIGH-SCORE", {570,15},34,2,yellow);
       std::string highscoreText  = FormatWidthleadingZeros(game.highscore, 5);
       DrawTextEx(font, highscoreText.c_str(),{655,40},34,2,yellow);


        game.Draw();
        EndDrawing();
    }
  CloseWindow();
  CloseAudioDevice();
}