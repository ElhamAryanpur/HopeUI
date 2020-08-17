#pragma once

#include "raylib.h"
#include "components.h"

// This will initialize main things
#define WINDOW_START(width, height, title, background) \
    {                                                  \
        SetConfigFlags(FLAG_WINDOW_RESIZABLE);         \
        SetTraceLogLevel(LOG_ERROR);                   \
        InitWindow(width, height, title);              \
        SetTargetFPS(60);                              \
        while (!WindowShouldClose())                   \
        {                                              \
            BeginDrawing();                            \
            ClearBackground(background);               \
            DrawFPS(10, 10);

// And to end the drawing and window
#define WINDOW_END \
    EndDrawing();  \
    }              \
    CloseWindow(); \
    }
