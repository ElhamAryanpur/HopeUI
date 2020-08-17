#pragma once
#include <stdio.h>
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
    char id;
    char element;
    char content;
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

void HUI_Label(HUI_Element data)
{
    HUI_Style ds = data.style;
    Color color = data.style.foreground;
    Vector2 pos;
    pos.x = (float)ds.x;
    pos.y = (float)ds.y;

    DrawTextEx(
        ds.font,
        data.content,
        pos,
        (float)ds.fontSize,
        (float)ds.spacing,
        color);
}

void HUI_Button(HUI_Element element, functiontype callback)
{
    int width = element.style.width;
    int height = element.style.height;

    Vector2 textSize = MeasureTextEx(
        element.style.font,
        element.content,
        (float)element.style.fontSize,
        (float)element.style.spacing);

    int targetX = 0;
    int targetY = 0;
    if ((int)textSize.x < width)
    {
        targetX = width / 2 - (int)textSize.x / 2;
        targetX = element.style.x + targetX;
    }
    else
    {
        targetX = element.style.x;
    }

    if ((int)textSize.y < height)
    {
        targetY = height / 2 - (int)textSize.y / 2;
        targetY = element.style.y + targetY;
    }
    else
    {
        targetY = element.style.y;
    }

    const Rectangle rec = {
        element.style.x,
        element.style.y,
        element.style.width,
        element.style.height};

    DrawRectangleRounded(
        rec,
        element.style.border_roundness,
        24, element.style.background);

    HUI_Element button_text = element;
    button_text.style.x = targetX;
    button_text.style.y = targetY;
    HUI_Label(button_text);

    Vector2 mousePos = GetMousePosition();
    int mx = (int)mousePos.x;
    int my = (int)mousePos.y;
    int x = element.style.x;
    int y = element.style.y;

    if (mx > x && mx < x + width && my > y && my < y + height)
    {
        if (IsMouseButtonDown(0) == true)
        {
            DrawRectangleRounded(
                rec,
                element.style.border_roundness,
                24, element.style.foreground);
            HUI_Element new_button_text = button_text;
            new_button_text.style.foreground = element.style.background;
            HUI_Label(new_button_text);
        }
        if (IsMouseButtonReleased(0) == true)
        {
            callback();
        }
    }
}

void HUI_Render(HUI_Element element)
{

    if (element.style.visible == true)
    {
        if (strcmp(element.element, "Label") == 0)
        {
            printf("Label!");
            HUI_Label(element);
        }
        else if (strcmp(element.element, "Button") == 0)
        {
            HUI_Button(element, element.callback);
        }
    }
}