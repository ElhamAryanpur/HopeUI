#pragma once

#include "helper.h"
#include "renderer.h"

#define HUI_Init                      \
    HUI_Renderer.Label = HUI_Label;   \
    HUI_Renderer.Button = HUI_Button; \
    HUI_Renderer.Render = HUI_Render;