#include "../include/game.hpp"

#include <GLUT/glut.h>
#include <cstring>
#include <random>


Game::Game(){

}

void Game::init(){

    for(int i = 0; i < 100; ++i){
        stars_.push_back(Star());
        stars_[i].init();
    }

    for(int i = 0; i < 20; ++i){        
        obstacles_.push_back(Obstacle());
    }

    battleship_.init();

    gameOver_ = false;

    score_ = 0;

}

void Game::start(){

    if(!isGameOver()){
        return;
    }

    init();
    
}

void Game::showMenu(){

    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    char scr[10];
    sprintf(scr, "%d", score_);

    if(score_ != 0){
        renderString( w / 2 - 150, h - 150, GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER", rand() % 2, rand() % 2, rand() % 2);
        renderString( w / 2 - 150, h - 250, GLUT_BITMAP_TIMES_ROMAN_24, "SCORE: ", 1, 1, 0);
        renderString( w / 2 - 50, h - 250, GLUT_BITMAP_TIMES_ROMAN_24, scr, 1, 1, 0);
    }

    renderString( w / 2 - 150, h - 350, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'Q' or 'ESC' to exit", 1, 1, 1);
    renderString( w / 2 - 150, h - 400, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'ENTER' to start the game", 1, 1, 1);
    renderString( w / 2 - 150, h - 450, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'A' to move left", 1, 1, 1);
    renderString( w / 2 - 150, h - 500, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'D' to move right", 1, 1, 1);
    renderString( w / 2 - 150, h - 550, GLUT_BITMAP_TIMES_ROMAN_24, "Press 'SPACEBAR' to shoot", 1, 1, 1);


}

void Game::draw(){

    for(int i = 0; i < stars_.size(); ++i){
        stars_[i].animate();
        stars_[i].draw();
    }
    
    for(int i = 0; i < obstacles_.size(); ++i){
        if(obstacles_[i].isDropping()){
            obstacles_[i].drop();
        }

        obstacles_[i].draw();
    }

    battleship_.draw();

    for(int i = 0; i < battleship_.getBullets().size(); ++i){
        if( battleship_.getBullets()[i].isLive() ){
            battleship_.getBullets()[i].moveUp();
            battleship_.getBullets()[i].draw();
        }
    }


    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);

    char scr[10];
    sprintf(scr, "%d", score_);
    renderString( w - 150, h - 50, GLUT_BITMAP_TIMES_ROMAN_24, "SCORE: ", 1, 1, 0);
    renderString( w - 50, h - 50, GLUT_BITMAP_TIMES_ROMAN_24, scr, 1, 1, 0);


}

Battleship& Game::getBattleShip(){
    return battleship_;
}

void Game::dropObstacle(){

    obstacles_.push_back(Obstacle());
    
    for(int i = 0; i < obstacles_.size(); ++i){
        
        if( !obstacles_[i].isDropping() ){
            obstacles_[i].drop();
            return;
        }
    }
}

void Game::detectCollisions(){

    //detect bullet to obstacle collisions and obstacle to battleship collisions
    for (int i = 0; i < obstacles_.size(); ++i){
        
        for (int j = 0; j < battleship_.getBullets().size(); ++j){

            if (!battleship_.getBullets()[j].isLive()){
                continue;
            }
            
            if ((battleship_.getBullets()[j].getX() > (obstacles_[i].getX() - obstacles_[i].getRadius())) && (battleship_.getBullets()[j].getX() < (obstacles_[i].getX() + obstacles_[i].getRadius()))){

                if((battleship_.getBullets()[j].getY() > (obstacles_[i].getY() - obstacles_[i].getRadius())) && (battleship_.getBullets()[j].getY() < (obstacles_[i].getY() + obstacles_[i].getRadius()))){

                    obstacles_[i].destroy();
                    battleship_.getBullets()[j].destroy();
                    score_ += 1;
   
                }
            }
        }
    
        if ((battleship_.getX() + battleship_.getWidth() > (obstacles_[i].getX() - obstacles_[i].getRadius())) && (battleship_.getX() - battleship_.getWidth() < (obstacles_[i].getX() + obstacles_[i].getRadius()))){
            if ((battleship_.getY() + battleship_.getHeight() > (obstacles_[i].getY() - obstacles_[i].getRadius())) && (battleship_.getY() - battleship_.getHeight() < (obstacles_[i].getY() + obstacles_[i].getRadius()))){
                end();
            }
        }
    }   
}

void Game::renderString(int x, int y, void *font, const char* str, int r, int g, int b){  

    glColor3f(r, g, b); 
    glRasterPos2f(x, y);

    int len = (int)strlen(str);
    for (int i = 0; i < len; ++i) {
        glutBitmapCharacter(font, str[i]);
    }

}

bool Game::isGameOver(){
    return gameOver_;
}

void Game::end(){
    gameOver_ = true; 
    stars_.clear();
    obstacles_.clear();
    battleship_.getBullets().clear();
}