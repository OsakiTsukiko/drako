#pragma once
#include "../node.h"
#include "../instruction.h"

class CompNode : public InstructionNode {
    private:
        Node* first = nullptr;
        Node* second = nullptr;
    public:
        CompNode(Vector2 position, Node* parent);
        void Update() override;
        void Draw() override;
        void Draw2() override;
};