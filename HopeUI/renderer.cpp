#include "renderer.hpp"
#include "string.h"

using namespace Renderer;

int Background[4] = {18, 25, 32, 255};
void HUI_null() {}

rl::Color NewColor(int *rgba)
{
    rl::Color c;

    c.r = rgba[0];
    c.g = rgba[1];
    c.b = rgba[2];
    c.a = rgba[3];

    return c;
}

Element Renderer::NewElement(char *name)
{
    int background[4] = {255, 255, 255, 255};
    int foreground[4] = {0, 0, 0, 255};

    Style style = {0, 0, 100, 50,
                   background, foreground,
                   rl::GetFontDefault(),
                   25, 2, true, 0};

    Element e = {(char *)"undefined", name, (char *)"",
                 style, 0, &HUI_null};

    return e;
}

// Label
void Renderer::Label(Element data)
{
    Style ds = data.style;
    rl::Color color = NewColor(data.style.foreground);
    rl::Vector2 pos;
    pos.x = (float)ds.x;
    pos.y = (float)ds.y;

    //rl::DrawText(data.content, ds.x, ds.y, ds.fontSize, color);

    rl::DrawTextEx(
        ds.font,
        data.content,
        pos,
        (float)ds.fontSize,
        (float)ds.spacing,
        color);
}

// Button
void Renderer::Button(Element element, functiontype callback)
{
    int width = element.style.width;
    int height = element.style.height;

    rl::Vector2 textSize = rl::MeasureTextEx(
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

    const rl::Rectangle rec = {
        (float)element.style.x,
        (float)element.style.y,
        (float)element.style.width,
        (float)element.style.height};

    rl::DrawRectangleRounded(
        rec,
        element.style.border_roundness,
        24, NewColor(element.style.background));

    Element button_text = element;
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
            Element new_button_text = button_text;
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
void Renderer::Render(Element element)
{
    if (element.style.visible == true)
    {
        if (strcmp(element.element, (char *)"Label") == 0)
        {
            Label(element);
        }
        else if (strcmp(element.element, (char *)"Button") == 0)
        {
            Button(element, element.callback);
        }
    }
}

void Renderer::Window::Init(int width, int height, char *title)
{
    SetConfigFlags(rl::FLAG_WINDOW_RESIZABLE);
    rl::SetTraceLogLevel(rl::LOG_ERROR);
    rl::SetTargetFPS(60);
    rl::InitWindow(width, height, title);
}

void Renderer::Window::GameLoop(functiontype callback)
{
    while (!rl::WindowShouldClose())
    {
        rl::BeginDrawing();
        rl::ClearBackground(NewColor(Background));
        rl::DrawFPS(10, 10);
        callback();
        rl::EndDrawing();
    }
}

void Renderer::Window::Close()
{
    rl::CloseWindow();
}