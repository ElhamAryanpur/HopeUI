#pragma once

#include "raylib.h"
#include "ECS.h"

// Label
static void HUI_Label(HUI_Element data)
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

// Button
static void HUI_Button(HUI_Element element, functiontype callback)
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

static void HUI_Render(HUI_Element element)
{
    if (element.style.visible == true)
    {
        if (strcmp(element.element, "Label") == 0)
        {
            HUI_Label(element);
        }
        else if (strcmp(element.element, "Button") == 0)
        {
            HUI_Button(element, element.callback);
        }
    }
}

// Renderer class
struct HUI_Renderer
{
    void (*Label)(HUI_Element data);
    void (*Button)(HUI_Element data, functiontype callback);
    void (*Render)(HUI_Element data);
} HUI_Renderer;

// This will initialize main things
#define HUI_Window_Start(width, height, title, background) \
    {                                                      \
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);             \
        SetTraceLogLevel(LOG_ERROR);                       \
        InitWindow(width, height, title);                  \
        SetTargetFPS(60);                                  \
        while (!WindowShouldClose())                       \
        {                                                  \
            BeginDrawing();                                \
            ClearBackground(background);                   \
            DrawFPS(10, 10);

// And to end the drawing and window
#define HUI_Window_End \
    EndDrawing();      \
    }                  \
    CloseWindow();     \
    }
