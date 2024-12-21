#include "menu.h"

#include <raylib.h>
#include <vector>
#include <functional>
#include <string>

#include "ui/utils.h"

#include "main.h"
#include "ui/nodes/nop.h"

bool is_menu_open = false;
Vector2 open_pos;

std::vector<std::string> menu_options = {
    std::string("No Instruction"),
};

std::vector<std::function<void()>> menu_actions = {
    []() { AddNode(NOPNode(open_pos)); }
};

void updateMenu() {
    if (IsKeyReleased(KEY_A)) if (!is_menu_open) {
        is_menu_open = true,
        open_pos = GetMousePosition();
    } else {
        is_menu_open = false;
    }

    int size = 0;
    for (std::string option : menu_options) {
        int txt_size = MeasureText(option.c_str(), FONT_SIZE);
        if (txt_size > size) size = txt_size;
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        if (!CheckCollisionPointRec(
            GetMousePosition(),
            {
                open_pos.x,
                open_pos.y,
                (float)size + MARGIN * 2,
                (float)menu_options.size() * (FONT_SIZE + MARGIN)
            }
        )) {
            is_menu_open = false;
        }
    }
}

void drawMenu() {
    if (!is_menu_open) return;

    int size = 0;
    for (std::string option : menu_options) {
        int txt_size = MeasureText(option.c_str(), FONT_SIZE);
        if (txt_size > size) size = txt_size;
    }

    int index = 0;
    for (std::string option : menu_options) {
        Rectangle optionRect = {
            open_pos.x,
            open_pos.y + (FONT_SIZE + MARGIN) * index,
            (float)size + MARGIN * 2,
            FONT_SIZE + MARGIN,
        };
        
        if (CheckCollisionPointRec(
            GetMousePosition(),
            optionRect
        )) {
            DrawRectangleRec(
                optionRect,
                RAYWHITE
            );
            DrawText(
                option.c_str(),
                optionRect.x + MARGIN,
                optionRect.y + MARGIN / 2,
                FONT_SIZE,
                MY_DARKESTGRAY
            );

            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                menu_actions.at(index)();
                is_menu_open = false;
            }
        } else {
            DrawRectangleRec(
                optionRect,
                MY_DARKESTGRAY
            );
            DrawRectangleLinesEx(
                optionRect,
                1,
                MY_GRAY
            );
            DrawText(
                option.c_str(),
                optionRect.x + MARGIN,
                optionRect.y + MARGIN / 2,
                FONT_SIZE,
                RAYWHITE
            );
        }

        index += 1;
    }    
}