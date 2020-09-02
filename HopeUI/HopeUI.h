#pragma once

#include "raylib.h"
#include "helper.h"
#include "renderer.h"

// Renderer class
struct HUI_Renderer
{
    void (*Label)(HUI_Element data);
    void (*Button)(HUI_Element data, functiontype callback);
    void (*Render)(HUI_Element data);
} HUI_Renderer;

#define Init                          \
    HUI_Renderer.Label = HUI_Label;   \
    HUI_Renderer.Button = HUI_Button; \
    HUI_Renderer.Render = HUI_Render;