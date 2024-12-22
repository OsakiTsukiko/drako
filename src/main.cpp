#include "main.h"

#include <iostream>
#include <raylib.h>

#include "ui/utils.h"
#include "ui/node.h"
#include "ui/pointer.h"
#include "menu.h"

#include "ui/nodes/nop.h"
#include "ui/nodes/comp.h"

int main() {
    InitWindow(1080, 720, "Drako");
    SetTargetFPS(60);
    SetTextureFilter(GetFontDefault().texture, TEXTURE_FILTER_BILINEAR);

    CompNode cn = CompNode({50, 50});

    while (!WindowShouldClose())
    {
        UpdateMenu();
        cn.Update();

        BeginDrawing();
            ClearBackground(MY_DARKESTGRAY);
            // DrawText("Hello Drako!", 10, 10, 20, LIGHTGRAY);

            cn.Draw();
            DrawMenu();

            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}