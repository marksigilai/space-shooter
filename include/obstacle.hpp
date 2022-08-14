class Obstacle {
    public:
        Obstacle();

        void reset();
        void drop();
        void increaseSpeed();
        void draw();
        void destroy();
        int getRadius();
        int getX();
        int getY();
        bool isDropping();

        ~Obstacle() = default;

    private:
        int x_;
        int y_;
        int speed_;
        int radius_;
        bool isDropping_;
};