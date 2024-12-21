#include "print.h"
#include "../utils.h"

Vector2 PrintBrick::getSize() {
    Vector2 res;
    Vector2 child_size = child->getSize();
    res.x = max(MeasureText("Print", FONT_SIZE), child_size.x) + MARGIN * 2;
    res.y = FONT_SIZE + child_size.y + GAP + MARGIN * 2;
    return res;
}

void PrintBrick::update() {
    Vector2 new_pos = this->position;
    new_pos.x += MARGIN;
    new_pos.y += MARGIN + FONT_SIZE + GAP;
    this->child->setPosition(new_pos);

    this->child->update();
}

void PrintBrick::draw() {
    Vector2 size = this->getSize();
    
    DrawRectangleV(this->position, size, ORANGE);
    DrawRectangleLines(
        this->position.x,
        this->position.y,
        size.x,
        size.y,
        BLACK
    );
    DrawText("Print", this->position.x + MARGIN, this->position.y + MARGIN, FONT_SIZE, WHITE);
    
    this->child->draw();
}