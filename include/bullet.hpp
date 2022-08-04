class Bullet {

    public:

        Bullet(int x, int y);

        void moveUp();

        void setViewport(int W, int H);

        void draw();
        
    private:
        int x_;
        int y_;
        int W_;
        int H_;

};