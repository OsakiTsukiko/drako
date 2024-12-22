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
    Node* parent = nullptr;
    Node(Vector2 position, std::string name, Color color, Node* parent);
    virtual void Update();
    virtual void Draw();
    virtual void Draw2();
    
    Vector2 GetDockerPos();
    Vector2 GetPointerPos(int index);
    void DrawConnection(Node* node, int port_index);

    void AddPointer(Pointer pointer);
};