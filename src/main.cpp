#include <iostream>
#include <raylib.h>

#include "ui/brick.h";
#include "ui/bricks/nop.h";
#include "ui/bricks/print.h";

int main() {
    std::cout << "Hello Drako!\n";

    InitWindow(800, 450, "Drako");
    SetTargetFPS(60);
    SetTextureFilter(GetFontDefault().texture, TEXTURE_FILTER_BILINEAR);

    NopBrick nop = NopBrick();
    PrintBrick pb = PrintBrick(&nop);
    PrintBrick pb2 = PrintBrick(&pb);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            
            ClearBackground(RAYWHITE);
            // DrawText("Hello Drako!", 10, 10, 20, LIGHTGRAY);

            pb2.update();
            pb2.draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}