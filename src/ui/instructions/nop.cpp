#include "nop.h"
#include "../utils.h"

NOPNode::NOPNode(Vector2 position, Node* parent) : InstructionNode({0.0, 0.0}, "No Instruction", parent) {
    this->position = position;
}