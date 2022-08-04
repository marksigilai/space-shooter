#include "../include/star.hpp"
#include "../include/battleship.hpp"
#include "../include/obstacle.hpp"

#include <vector>

class Game {

    public:
        Game();

        void draw();

        Battleship& getBattleShip();

        void init();

        void dropObstacle();

    private:
        std::vector<Star> stars_;
        std::vector<Obstacle> obstacles_;
        Battleship battleship_;



};