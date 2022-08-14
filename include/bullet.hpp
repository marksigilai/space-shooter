class Bullet {

    public:

        Bullet(int x, int y);

        void moveUp();

        int getX();
        
        int getY();

        void draw();

        void destroy();

        bool isLive();

        ~Bullet() = default;

    private:
        int x_;
        int y_;
        int W_;
        int H_;
        bool isLive_;
};