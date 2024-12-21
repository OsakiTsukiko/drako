#pragma once
#include <string>
#include <raylib.h>

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
};