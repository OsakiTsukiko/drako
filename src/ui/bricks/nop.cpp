#include "nop.h"
#include "../utils.h"

Vector2 NopBrick::getSize() {
    Vector2 res;
    res.x = MeasureText("No Instruction", FONT_SIZE) + MARGIN * 2;
    res.y = FONT_SIZE + MARGIN * 2;
    return res;
}

void NopBrick::update() {

}

void NopBrick::draw() {
    Vector2 size = this->getSize();
    DrawRectangleV(this->position, size, RED);
    DrawRectangleLines(
        this->position.x,
        this->position.y,
        size.x,
        size.y,
        BLACK
    );
    DrawText("No Instruction", this->position.x + MARGIN, this->position.y + MARGIN, FONT_SIZE, WHITE);
}