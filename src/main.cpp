#include "main.h"

#include <iostream>
#include <raylib.h>

#include "menu.h"

#include "ui/utils.h"
#include "ui/node.h"
#include "ui/pointer.h"

#include "ui/nodes/nop.h"

std::vector<Node> scene_nodes;

void AddNode(Node node) {
    scene_nodes.push_back(node);
}

int main() {
    InitWindow(1080, 720, "Drako");
    SetTargetFPS(60);
    SetTextureFilter(GetFontDefault().texture, TEXTURE_FILTER_BILINEAR);

    while (!WindowShouldClose())
    {
        updateMenu();

        BeginDrawing();
            ClearBackground(MY_DARKESTGRAY);
            // DrawText("Hello Drako!", 10, 10, 20, LIGHTGRAY);
            
            for (Node node : scene_nodes) {
                node.Update();
            }

            for (Node node : scene_nodes) {
                node.Draw();
            }

            drawMenu();

            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}