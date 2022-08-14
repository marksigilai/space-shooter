class Star {

    public:

        Star();
        
        void draw();

        Star init();

        void animate();

        ~Star() = default;
        
    private:
        int x_;
        int y_;

};

