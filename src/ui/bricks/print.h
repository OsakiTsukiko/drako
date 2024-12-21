#pragma once

#include "../brick.h"

class PrintBrick : public Brick {
    private:
        Vector2 position;
        Brick* child;
    public:
        PrintBrick(Brick* child) {
            this->position.x = 0;
            this->position.y = 0;
            this->child = child;
        }
        void setPosition(Vector2 position) {this->position = position;}
        
        Vector2 getSize();
        void update();
        void draw();
};