#include "nop.h"
#include "../utils.h"

NOPNode::NOPNode(Vector2 position) : Node({0.0, 0.0}, "No Instruction", MY_RED) {
    this->position = position;
}