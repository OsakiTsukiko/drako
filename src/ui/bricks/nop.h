#pragma once

#include "../brick.h"

class NopBrick : public Brick {
    private:
        Vector2 position;
    public:
        NopBrick() {
            this->position.x = 0;
            this->position.y = 0;
        }
        
        Vector2 getSize();
        void update();
        void draw();
};