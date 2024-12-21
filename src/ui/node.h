#pragma once

#include <raylib.h>

#include <string>
#include <vector>

#include "pointer.h"

class Node
{
protected:
    Vector2 position;
    Color color;
    std::string name;
    std::vector<Pointer> pointer_list;
public:
    Node(Vector2 position, std::string name, Color color);
    void Update();
    void Draw();

    void AddPointer(Pointer pointer);
};