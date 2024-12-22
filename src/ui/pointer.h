#pragma once
#include <string>
#include <raylib.h>
#include <functional>

enum PType {
    INSTRUCTION,
    EXPRESSION,
    STRING,
    INTEGER,
    BOOLEAN,
};

struct Pointer
{
    std::string name;
    PType type;
    Color color;
    std::function<void(void*)> callback;
};