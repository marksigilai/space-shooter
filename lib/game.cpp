#include "../include/game.hpp"

//initialize stars, battleship, score to 0
Game::Game(){
    
    for(int i = 0; i < 100; i++){
        stars_.push_back(Star());
    }

    for(int i = 0; i < 10; i++){
        obstacles_.push_back(Obstacle());
    }

}

void Game::draw(){

    for(int i = 0; i < stars_.size(); i++){
        stars_[i].draw();
    }

    for(int i = 0; i < obstacles_.size(); i++){

        if(obstacles_[i].isDropping()){
            obstacles_[i].drop();
        }

        obstacles_[i].draw();
    }

    battleship_.draw();

    for(int i = 0; i < battleship_.getBullets().size(); i++){
        battleship_.getBullets()[i].moveUp();
        battleship_.getBullets()[i].draw();
    }

}

Battleship& Game::getBattleShip(){
    return battleship_;
}

void Game::init(){

    for(int i = 0; i < stars_.size(); i++){
        stars_[i].init();
    }

    for(int i = 0; i < obstacles_.size(); i++){
        obstacles_[i].init();
    }

    battleship_.init();


}

void Game::dropObstacle(){

    for(int i = 0; i < obstacles_.size(); i++){
        
        if( !obstacles_[i].isDropping() ){
            obstacles_[i].drop();
            return;
        }

    }
}