#pragma once

#include <raylib.h>

#include <string>
#include <vector>

#include "pointer.h"

class SNode
{
private:
    Vector2 position;
    Color color;
    std::string name;
    std::vector<Pointer> pointer_list;
public:
    SNode(Vector2 position, std::string name, Color color);
    void Update();
    void Draw();

    void AddPointer(Pointer pointer);
};