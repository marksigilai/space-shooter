class Battleship{

    private:

        void moveLeft(){
            x_++;

            if( x_ > H_){
                x_++;
            }
        }

        void moveRight(){

            if( x_ < W_){
                x_--;
            }
        }

        void setViewport(int W, int H){
            W_ = W;
            H_ = H;
        }



    public:
        int x_;
        int y_;
        int W_;
        int H_;
        bool isAlive;

};