#include "global.h"

bool mouse_disabled = false;

bool IsMouseDisabled() {
    return mouse_disabled;
};

void SetMouseDisabled(bool value) {
    mouse_disabled = value;
}