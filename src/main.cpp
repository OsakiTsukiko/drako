#include "main.h"

#include <iostream>
#include <raylib.h>

#include "ui/utils.h"
#include "ui/node.h"
#include "ui/pointer.h"
#include "menu.h"

#include "ui/instructions/nop.h"
#include "ui/instructions/comp.h"

int main() {
    InitWindow(1080, 720, "Drako");
    SetTargetFPS(120);
    SetTextureFilter(GetFontDefault().texture, TEXTURE_FILTER_BILINEAR);

    CompNode root = CompNode({50, 50}, nullptr);

    while (!WindowShouldClose())
    {
        UpdateMenu();
        root.Update();

        BeginDrawing();
            ClearBackground(MY_DARKESTGRAY);
            // DrawText("Hello Drako!", 10, 10, 20, LIGHTGRAY);

            root.Draw();
            root.Draw2();
            DrawMenu();

            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}