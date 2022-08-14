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

        void detectCollisions();

        void renderString(int, int, void *font, const char* , int, int, int);

        bool isGameOver();

        void start();

        void showMenu();

        void end();

        ~Game() = default;

    private:
        std::vector<Star> stars_;
        std::vector<Obstacle> obstacles_;
        Battleship battleship_;
        bool gameOver_ = true;
        int score_;

};