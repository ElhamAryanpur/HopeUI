#pragma once

#include "raylib.h"

typedef void (*functiontype)();

typedef struct HUI_Style
{
    int x;
    int y;
    int width;
    int height;
    Color background;
    Color foreground;
    Font font;
    int fontSize;
    int spacing;
    bool visible;
    float border_roundness;
} HUI_Style;

typedef struct HUI_Element
{
    char *id;
    char *element;
    char *content;
    HUI_Style style;
    int zIndex;
    functiontype callback;
} HUI_Element;

void HUI_null() {}

HUI_Element NewElement(char *name)
{
    Color background = {255, 255, 255, 255};
    Color foreground = {0, 0, 0, 255};

    HUI_Style style = {0, 0, 100, 50,
                       background, foreground,
                       GetFontDefault(),
                       25, 2, true, 0};

    HUI_Element e = {"undefined", name, "",
                     style, 0, &HUI_null};

    return e;
}