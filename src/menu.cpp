#include "menu.h"

#include "global.h"
#include "ui/utils.h"

bool is_menu_open = false;

Vector2 open_pos;
std::vector<std::string>* options;
std::vector<std::function<void(Pointer, Vector2)>>* actions;
Pointer pointer;

void OpenMenu(std::vector<std::string>* p_options, std::vector<std::function<void(Pointer, Vector2)>>* p_actions, Pointer p_pointer) {
    SetMouseDisabled(true);
    is_menu_open = true;
    open_pos = GetMousePosition();
    options = p_options;
    actions = p_actions;
    pointer = p_pointer;
}

void UpdateMenu() {
    if (is_menu_open) {
        int size = 0;
        for (std::string option : *options) {
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
                    (float)options->size() * (FONT_SIZE + MARGIN)
                }
            )) {
                is_menu_open = false;
                SetMouseDisabled(false);
            } else {
                int index = 0;
                for (std::string option : *options) {
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
                        actions->at(index)(pointer, open_pos);
                        is_menu_open = false;
                        SetMouseDisabled(false);
                    }
                    index += 1;
                }
            }
        }
    }
}

void DrawMenu() {
    if (!is_menu_open) return;

    int size = 0;
    for (std::string option : *options) {
        int txt_size = MeasureText(option.c_str(), FONT_SIZE);
        if (txt_size > size) size = txt_size;
    }

    int index = 0;
    for (std::string option : *options) {
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