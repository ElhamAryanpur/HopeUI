#include "renderer.hpp"
#include "string.h"

using namespace Renderer;

namespace rl
{
#include "raylib.h"
}

rl::Font HUI_Font = rl::GetFontDefault();

rl::Color NewColor(int *rgba)
{
    rl::Color c;

    c.r = rgba[0];
    c.g = rgba[1];
    c.b = rgba[2];
    c.a = rgba[3];

    return c;
}

HUI_Element Renderer::NewElement(char *name)
{
    int background[4] = {255, 255, 255, 255};
    int foreground[4] = {0, 0, 0, 255};

    HUI_Style style = {0, 0, 100, 50,
                       background, foreground,
                       25, 2, true, 0};

    HUI_Element e = {(char *)"undefined", name, (char *)"",
                     style, 0, &HUI_null};

    return e;
}

// Label
void Renderer::Label(HUI_Element data)
{
    HUI_Style ds = data.style;
    rl::Color color = NewColor(data.style.foreground);
    rl::Vector2 pos;
    pos.x = (float)ds.x;
    pos.y = (float)ds.y;

    rl::DrawTextEx(
        HUI_Font,
        data.content,
        pos,
        (float)ds.fontSize,
        (float)ds.spacing,
        color);
}

// Button
void Renderer::Button(HUI_Element element, functiontype callback)
{
    int width = element.style.width;
    int height = element.style.height;

    rl::Vector2 textSize = rl::MeasureTextEx(
        HUI_Font,
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

    const rl::Rectangle rec = {
        (float)element.style.x,
        (float)element.style.y,
        (float)element.style.width,
        (float)element.style.height};

    rl::DrawRectangleRounded(
        rec,
        element.style.border_roundness,
        24, NewColor(element.style.background));

    HUI_Element button_text = element;
    button_text.style.x = targetX;
    button_text.style.y = targetY;
    Label(button_text);

    rl::Vector2 mousePos = rl::GetMousePosition();
    int mx = (int)mousePos.x;
    int my = (int)mousePos.y;
    int x = element.style.x;
    int y = element.style.y;

    if (mx > x && mx < x + width && my > y && my < y + height)
    {
        if (rl::IsMouseButtonDown(0) == true)
        {
            rl::DrawRectangleRounded(
                rec,
                element.style.border_roundness,
                24, NewColor(element.style.foreground));
            HUI_Element new_button_text = button_text;
            new_button_text.style.foreground = element.style.background;
            Label(new_button_text);
        }
        if (rl::IsMouseButtonReleased(0) == true)
        {
            callback();
        }
    }
}

// Render
void Renderer::Render(HUI_Element element)
{
    if (element.style.visible == true)
    {
        if (strcmp(element.element, "Label") == 0)
        {
            Label(element);
        }
        else if (strcmp(element.element, "Button") == 0)
        {
            Button(element, element.callback);
        }
    }
}

void Renderer::Init(int width, int height, char *title)
{
    SetConfigFlags(rl::FLAG_WINDOW_RESIZABLE);
    rl::SetTraceLogLevel(rl::LOG_ERROR);
    rl::SetTargetFPS(60);
    rl::InitWindow(width, height, title);
    while (!rl::WindowShouldClose())
    {
        rl::BeginDrawing();
        rl::DrawFPS(10, 10);

        rl::EndDrawing();
    }
    rl::CloseWindow();
}

void Renderer::GameLoop(functiontype callback)
{
    while (!rl::WindowShouldClose())
    {
        rl::BeginDrawing();
        rl::ClearBackground(NewColor(Background));
        callback();
        rl::DrawFPS(10, 10);
    }
}

void Renderer::Close()
{
    rl::CloseWindow();
}