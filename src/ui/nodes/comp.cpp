#include "comp.h"
#include "../utils.h"

CompNode::CompNode(Vector2 position) : Node({0.0, 0.0}, "Compounded Instruction", MY_RED) {
    this->position = position;
    this->AddPointer({
        "First Instruction",
        INSTRUCTION,
        MY_RED,
        [this](void* node) {
            this->first = (Node*)node;
        }
    });
    this->AddPointer({
        "Second Instruction",
        INSTRUCTION,
        MY_RED,
        [this](void* node) {
            this->second = (Node*)node;
        }
    });
}

void CompNode::Update() {
    if (this->first != nullptr) this->first->Update();
    if (this->second != nullptr) this->second->Update();
}

void CompNode::Draw() {
    Node::Draw();

    if (this->first != nullptr) this->first->Draw();
    if (this->second != nullptr) this->second->Draw();
}