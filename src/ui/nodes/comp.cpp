#include "comp.h"
#include "../utils.h"

CompNode::CompNode(Vector2 position) : Node({0.0, 0.0}, "Compounded Instruction", MY_RED) {
    this->position = position;
    this->AddPointer({
        "First Instruction",
        INSTRUCTION,
        MY_RED,
    });
    this->AddPointer({
        "Second Instruction",
        INSTRUCTION,
        MY_RED,
    });
}