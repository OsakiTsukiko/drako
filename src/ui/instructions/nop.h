#pragma once
#include "../node.h"
#include "../instruction.h"

class NOPNode : public InstructionNode {
    private:
    public:
        NOPNode(Vector2 position, Node* parent);
};