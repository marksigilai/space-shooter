class Bullet {

    public:

        Bullet(int x, int y){
            x_ = x;
            y_ = y;
        }

        void moveUp(){

            if( y_ < W_){
                y_--;
            }
        }

        void setViewport(int W, int H){
            W_ = W;
            H_ = H;
        }


    private:
        int x_;
        int y_;
        int W_;
        int H_;

};