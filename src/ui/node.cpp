#include "node.h"

#include <vector>
#include <string>
#include <functional>

#include "utils.h"
#include "../global.h"
#include "../menu.h"

#include "nodes/comp.h"
#include "nodes/nop.h"

std::vector<std::string> options_instruction = {
    std::string("Compounded Instrunction"),
    std::string("No Instrunction"),
};
std::vector<std::function<void(Pointer, Vector2 pos)>> actions_instrunction = {
    [](Pointer p, Vector2 pos) {
        Node* comp = new CompNode(pos, nullptr);
        p.callback((void*)comp);
    },
    [](Pointer p, Vector2 pos) {
        Node* nop = new NOPNode(pos, nullptr);
        p.callback((void*)nop);
    },
};

Node::Node(Vector2 position, std::string name, Color color, Node* parent) {
    this->position = position;
    this->name = name;
    this->color = color;
    this->parent = parent;
}

void Node::Update() {
    int name_size = MeasureText(this->name.c_str(), FONT_SIZE);
    int text_size = 0;
    for (Pointer p : this->pointer_list) {
        int ts = MeasureText(p.name.c_str(), FONT_SIZE);
        if (ts > text_size) text_size = ts;
    }
    int size = std::max(std::max(name_size, text_size), MIN_WIDTH);

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        if (CheckCollisionPointRec(
            GetMousePosition(),
            {
                this->position.x,
                this->position.y,
                float(size) + MARGIN * 2,
                FONT_SIZE + MARGIN * 2,
            }
        )) {
            Vector2 delta = GetMouseDelta();
            this->position.x += delta.x;
            this->position.y += delta.y;
        }
    }
}

void Node::Draw() {
    int name_size = MeasureText(this->name.c_str(), FONT_SIZE);
    int text_size = 0;
    for (Pointer p : this->pointer_list) {
        int ts = MeasureText(p.name.c_str(), FONT_SIZE);
        if (ts > text_size) text_size = ts;
    }
    int size = std::max(std::max(name_size, text_size), MIN_WIDTH);
    // OUTPUT DOCKER
    DrawRectangle(
        this->position.x - (FONT_SIZE + MARGIN * 2),
        this->position.y,
        FONT_SIZE + MARGIN * 2,
        FONT_SIZE + MARGIN * 2,
        MY_DARKGRAY
    );
    DrawCircle(
        this->position.x - (FONT_SIZE + MARGIN * 2) / 2,
        this->position.y + (FONT_SIZE + MARGIN * 2) / 2,
        (FONT_SIZE + MARGIN * 2) / 3.5,
        MY_GRAY
    );
    
    // Draw Title
    DrawRectangle(
        this->position.x,
        this->position.y,
        size + MARGIN * 2,
        FONT_SIZE + MARGIN * 2,
        this->color
    );
    DrawText(this->name.c_str(), this->position.x + MARGIN, this->position.y + MARGIN, FONT_SIZE, MY_DARKGRAY);

    if (!this->pointer_list.empty()) {
        int gap_size = (this->pointer_list.size() - 1) * GAP;
        if (gap_size < 0) gap_size = 0; 
        // Draw Body
        DrawRectangle(
            this->position.x,
            this->position.y + FONT_SIZE + MARGIN * 2,
            size + MARGIN * 2,
            this->pointer_list.size() * (FONT_SIZE + MARGIN) + gap_size + MARGIN * 2,
            MY_DARKGRAY
        );
    }

    // Draw Pointers
    int index = 0;
    for (Pointer p : this->pointer_list) {
        // BOXES
        int l_text_size = MeasureText(p.name.c_str(), FONT_SIZE);
        DrawRectangle(
            this->position.x + size - (l_text_size + MARGIN) + MARGIN * 2,
            this->position.y + FONT_SIZE + MARGIN * 2 + MARGIN + (FONT_SIZE + MARGIN + GAP) * index,
            l_text_size + MARGIN,
            FONT_SIZE + MARGIN,
            MY_GRAY
        );

        // TEXT
        DrawText(
            p.name.c_str(),
            this->position.x + size - (l_text_size + MARGIN / 2) + MARGIN * 2,
            this->position.y + FONT_SIZE + MARGIN * 2 + MARGIN + (FONT_SIZE + MARGIN + GAP) * index + MARGIN / 2,
            FONT_SIZE,
            RAYWHITE
        );

        // POINTERS
        DrawRectangle(
            this->position.x + size + MARGIN * 2,
            this->position.y + FONT_SIZE + MARGIN * 2 + MARGIN + (FONT_SIZE + MARGIN + GAP) * index,
            FONT_SIZE + MARGIN,
            FONT_SIZE + MARGIN,
            p.color
        );

        // POINTR CIRCLE
        DrawCircle(
            this->position.x + size + MARGIN * 2 + (FONT_SIZE + MARGIN) / 2,
            this->position.y + FONT_SIZE + MARGIN * 2 + MARGIN + (FONT_SIZE + MARGIN + GAP) * index + (FONT_SIZE + MARGIN) / 2,
            (FONT_SIZE + MARGIN) / 3.5,
            MY_DARKGRAY
        );

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            if (CheckCollisionPointCircle(
                GetMousePosition(),
                {
                    this->position.x + size + MARGIN * 2 + (FONT_SIZE + MARGIN) / 2,
                    this->position.y + FONT_SIZE + MARGIN * 2 + MARGIN + (FONT_SIZE + MARGIN + GAP) * index + (FONT_SIZE + MARGIN) / 2
                },
                (FONT_SIZE + MARGIN) / 3.5
            )) {
                if (!IsMouseDisabled()) {
                    OpenMenu(&options_instruction, &actions_instrunction, p);
                }
            }
        }

        index += 1;
    }
}

void Node::Draw2() {

}

Vector2 Node::GetDockerPos() {
    return {
        this->position.x - (FONT_SIZE + MARGIN * 2) / 2,
        this->position.y + (FONT_SIZE + MARGIN * 2) / 2
    };
}

Vector2 Node::GetPointerPos(int index) {
    int name_size = MeasureText(this->name.c_str(), FONT_SIZE);
    int text_size = 0;
    for (Pointer p : this->pointer_list) {
        int ts = MeasureText(p.name.c_str(), FONT_SIZE);
        if (ts > text_size) text_size = ts;
    }
    int size = std::max(std::max(name_size, text_size), MIN_WIDTH);

    return {
        this->position.x + size + MARGIN * 2 + (FONT_SIZE + MARGIN) / 2,
        this->position.y + FONT_SIZE + MARGIN * 2 + MARGIN + (FONT_SIZE + MARGIN + GAP) * index + (FONT_SIZE + MARGIN) / 2,
    };
}

void Node::DrawConnection(Node* node, int port_index) {
    Vector2 pointer_pos = GetPointerPos(port_index);
    Vector2 docker_pos = node->GetDockerPos();

    DrawLineEx(pointer_pos, docker_pos, 2.0, CONNECTION_COLOR);
    DrawCircleV(pointer_pos, 3, RAYWHITE);
    DrawCircleV(docker_pos, 7, RAYWHITE);
}

void Node::AddPointer(Pointer pointer) {
    this->pointer_list.push_back(pointer);
}