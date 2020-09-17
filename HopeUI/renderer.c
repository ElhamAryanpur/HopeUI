#include "renderer.h"
#include "raylib.h"
#include <string.h>

int Background[4] = {18, 25, 32, 255};
char *HUI_Font = "default";
void HUI_null() {}

Color NewColor(int *rgba)
{
    Color c;

    c.r = rgba[0];
    c.g = rgba[1];
    c.b = rgba[2];
    c.a = rgba[3];

    return c;
}

Font GetFont()
{
    if (strcmp(HUI_Font, "default") == 0)
    {
        return GetFontDefault();
    }
}

HUI_Element hrne(char *name)
{
    int background[4] = {255, 255, 255, 255};
    int foreground[4] = {0, 0, 0, 255};

    hrs style = {0, 0, 100, 50,
                 background, foreground,
                 25, 2, 1, 0};

    HUI_Element e = {(char *)"undefined", name, (char *)"",
                     style, 0, &HUI_null};

    return e;
}

// Label
void hrl(HUI_Element data)
{
    hrs ds = data.style;
    Color color = NewColor(data.style.foreground);
    Vector2 pos;
    pos.x = (float)ds.x;
    pos.y = (float)ds.y;

    //DrawText(data.content, ds.x, ds.y, ds.fontSize, color);

    DrawTextEx(
        GetFont(),
        data.content,
        pos,
        (float)ds.fontSize,
        (float)ds.spacing,
        color);
}

// Button
void hrb(HUI_Element element, functiontype callback)
{
    int width = element.style.width;
    int height = element.style.height;

    Vector2 textSize = MeasureTextEx(
        GetFont(),
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
        (float)element.style.x,
        (float)element.style.y,
        (float)element.style.width,
        (float)element.style.height};

    DrawRectangleRounded(
        rec,
        element.style.border_roundness,
        24, NewColor(element.style.background));

    HUI_Element button_text = element;
    button_text.style.x = targetX;
    button_text.style.y = targetY;
    hrl(button_text);

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
                24, NewColor(element.style.foreground));
            HUI_Element new_button_text = button_text;
            new_button_text.style.foreground = element.style.background;
            hrl(new_button_text);
        }
        if (IsMouseButtonReleased(0) == true)
        {
            callback();
        }
    }
}

// Render
void hrr(HUI_Element element)
{
    if (element.style.visible == 1)
    {
        if (strcmp(element.element, (char *)"Label") == 0)
        {
            hrl(element);
        }
        else if (strcmp(element.element, (char *)"Button") == 0)
        {
            hrb(element, element.callback);
        }
    }
}

void hri(int width, int height, char *title)
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTraceLogLevel(LOG_ERROR);
    SetTargetFPS(60);
    InitWindow(width, height, title);
}

void hrgl(functiontype callback)
{
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(NewColor(Background));
        DrawFPS(10, 10);
        callback();
        EndDrawing();
    }
}

void hrc()
{
    CloseWindow();
}