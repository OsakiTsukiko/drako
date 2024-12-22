#pragma once
#include <vector>
#include <string>
#include <functional>

#include "ui/node.h"

void OpenMenu(std::vector<std::string>* options, std::vector<std::function<void(Pointer, Vector2)>>* actions, Pointer pointer);
void UpdateMenu();
void DrawMenu();