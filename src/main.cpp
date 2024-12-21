#include <iostream>
#include <raylib.h>

#include "ui/brick.h";
#include "ui/bricks/nop.h";

int main() {
    std::cout << "Hello Drako!\n";

    InitWindow(800, 450, "Drako");
    SetTargetFPS(60);
    SetTextureFilter(GetFontDefault().texture, TEXTURE_FILTER_BILINEAR);

    NopBrick nop = NopBrick();

    while (!WindowShouldClose())
    {
        BeginDrawing();
            
            ClearBackground(RAYWHITE);
            // DrawText("Hello Drako!", 10, 10, 20, LIGHTGRAY);

            nop.update();
            nop.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}