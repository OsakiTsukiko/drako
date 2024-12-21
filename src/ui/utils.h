#pragma once

 #define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

const int MARGIN = 10;
const int GAP = 10;
const int FONT_SIZE = 16;