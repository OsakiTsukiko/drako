#pragma once

#include <raylib.h>

class Brick
{
public:
    virtual Vector2 getSize() = 0;    
    virtual void update() = 0;
    virtual void draw() = 0;
};