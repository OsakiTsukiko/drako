#pragma once

#include <raylib.h>

class Brick
{
public:
    virtual void setPosition(Vector2 position) = 0;
    virtual Vector2 getSize() = 0;    
    virtual void update() = 0;
    virtual void draw() = 0;
};