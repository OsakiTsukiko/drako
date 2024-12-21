#include <iostream>
#include <raylib.h>

#include "ui/utils.h"
#include "ui/snode.h"
#include "ui/pointer.h"

int main() {
    std::cout << "Hello Drako!\n";

    InitWindow(800, 450, "Drako");
    SetTargetFPS(60);
    SetTextureFilter(GetFontDefault().texture, TEXTURE_FILTER_BILINEAR);

    Vector2 pos = {100, 100};
    SNode s = SNode(pos, "TEST", MY_RED);
    s.AddPointer({std::string("idk"), STRING});
    s.AddPointer({std::string("idk2"), STRING});
    s.AddPointer({std::string("my very cool field that is very cool"), STRING});

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(MY_DARKESTGRAY);
            // DrawText("Hello Drako!", 10, 10, 20, LIGHTGRAY);
            s.Update();
            s.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}