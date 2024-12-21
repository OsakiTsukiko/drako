#include <iostream>
#include <raylib.h>

#include "ui/utils.h"
#include "ui/snode.h"
#include "ui/pointer.h"

int main() {
    std::cout << "Hello Drako!\n";

    InitWindow(1080, 720, "Drako");
    SetTargetFPS(60);
    SetTextureFilter(GetFontDefault().texture, TEXTURE_FILTER_BILINEAR);

    Vector2 pos = {100, 100};
    SNode s = SNode(pos, "TEST", MY_RED);
    s.AddPointer({std::string("idk"), STRING});
    s.AddPointer({std::string("idk2"), STRING});
    s.AddPointer({std::string("my very cool field that is very cool"), STRING});

    Vector2 pos2 = {300, 300};
    SNode s2 = SNode(pos2, "TEST 2", ORANGE);
    s2.AddPointer({std::string("idk 2"), STRING});
    s2.AddPointer({std::string("idk2 2"), STRING});
    s2.AddPointer({std::string("my very cool field that is very cool 2"), STRING});

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(MY_DARKESTGRAY);
            // DrawText("Hello Drako!", 10, 10, 20, LIGHTGRAY);
            s.Update();
            s.Draw();

            s2.Update();
            s2.Draw();

            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}