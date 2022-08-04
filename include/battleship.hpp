class Battleship{

    public:

        Battleship();

        void moveRight();
        void moveLeft();

        void draw();
        void init();
        
    private:
        int x_;
        int y_;
};