#pragma once
#include <string>

enum PType {
    STATEMENT,
    EXPRESSION,
    STRING,
    INTEGER,
    BOOLEAN,
};

struct Pointer
{
    std::string name;
    PType type;
};