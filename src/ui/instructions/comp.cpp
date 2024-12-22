#include "comp.h"
#include "../utils.h"

CompNode::CompNode(Vector2 position, Node* parent) : InstructionNode({0.0, 0.0}, "Compounded Instruction", parent) {
    this->position = position;
    this->AddPointer({
        "First Instruction",
        INSTRUCTION,
        MY_RED,
        [this](void* node) {
            this->first = (Node*)node;
            this->first->parent = this;
            // TODO: FREE OLD IF NEEDED
        }
    });
    this->AddPointer({
        "Second Instruction",
        INSTRUCTION,
        MY_RED,
        [this](void* node) {
            this->second = (Node*)node;
            this->second->parent = this;
            // TODO: FREE OLD IF NEEDED
        }
    });
}

void CompNode::Update() {
    Node::Update();

    if (this->first != nullptr) this->first->Update();
    if (this->second != nullptr) this->second->Update();
}

void CompNode::Draw() {
    Node::Draw();

    if (this->first != nullptr) this->first->Draw();
    if (this->second != nullptr) this->second->Draw();
}

void CompNode::Draw2() {
    Node::Draw2();

    if (this->first != nullptr) {
        this->first->Draw2();
        DrawConnection(this->first, 0);
    }

    if (this->second != nullptr) {
        this->second->Draw2();
        DrawConnection(this->second, 1);
    }
}