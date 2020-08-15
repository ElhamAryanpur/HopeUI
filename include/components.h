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
    Color background = {r : 255, g : 255, b : 255, a : 255};
    Color foreground = {r : 0, g : 0, b : 0, a : 255};

    HUI_Style style = {
        x : 0,
        y : 0,
        width : 100,
        height : 50,
        background : background,
        foreground : foreground,
        font : GetFontDefault(),
        fontSize : 25,
        spacing : 2,
        visible : true
    };

    HUI_Element e = {
        id : "undefined",
        element : name,
        content : "",
        style : style,
        zIndex : 0,
        callback : &HUI_null
    };

    return e;
}

HUI_Element HUI_SetColor(HUI_Element element, Color background, Color foreground)
{
    element.style.background = background;
    element.style.foreground = foreground;
    return element;
}

HUI_Element HUI_SetPosition(HUI_Element element, int x, int y)
{
    element.style.x = x;
    element.style.y = y;
    return element;
}

HUI_Element HUI_SetContent(HUI_Element element, char *text)
{
    element.content = text;
    return element;
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

    DrawRectangle(
        element.style.x,
        element.style.y,
        element.style.width,
        element.style.height,
        element.style.background);
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
            DrawRectangle(
                x, y, width, height,
                element.style.foreground);
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
        if (element.element == "Label")
        {
            HUI_Label(element);
        }
        else if (element.element == "Button")
        {
            HUI_Button(element, element.callback);
        }
    }
}