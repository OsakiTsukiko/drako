#include <iostream>
#include <raylib.h>

int main() {
    std::cout << "Hello Drako!\n";

    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RED);
            DrawText("Hello Drako!", 10, 10, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}