#pragma once
#include "../node.h"

class CompNode : public Node {
    private:
        Node* first = nullptr;
        Node* second = nullptr;
    public:
        CompNode(Vector2 position);
        void Update() override;
        void Draw() override;
};