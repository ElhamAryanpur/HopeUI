#pragma once

#include "raylib.h"
#include "components.h"

// This will initialize main things
void HUI_Init(int width, int height, char* title, Color background, functiontype callback){

    // This flag allows window resize
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    // Change log level
    SetTraceLogLevel(LOG_ERROR);

    // init Window and settings
    InitWindow(width, height, title);
    SetTargetFPS(1000);

    // Listen for window closing
    while (!WindowShouldClose()){

        // Start drawing things on screen
        BeginDrawing();

        // Clean background
        ClearBackground(background);

        DrawFPS(10, 10);

        // Rest of code
        callback();

        // Don't draw anymore
        EndDrawing();
    }

    // Close window when done
    CloseWindow();
}