class Obstacle {
    public:
        Obstacle();

        void init();
        void drop();
        void increaseDroprate();
        void draw();
        bool isDropping();

    private:
        int x_;
        int y_;
        int dropRate_;
        int radius_;
        bool isDropping_;
};