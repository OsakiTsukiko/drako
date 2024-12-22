#pragma once

#include "node.h"
#include "utils.h"

class InstructionNode : public Node {
    public:
        InstructionNode(Vector2 position, std::string name, Node* parent)
        : Node(position, name, MY_RED, parent) {
            
        }
};