#include "../include/bullet.hpp"
#include <vector>

class Battleship{

    public:

        Battleship();

        void moveRight();
        void moveLeft();

        void draw();
        void init();

        void shoot();
        std::vector<Bullet>& getBullets();
        
    private:
        int x_;
        int y_;
        std::vector<Bullet> bullets_;

};