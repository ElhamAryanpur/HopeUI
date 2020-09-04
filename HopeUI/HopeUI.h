#pragma once

#include "helper.h"
#include "ECS.h"
#include "renderer.h"

#define HUI_Init                      \
    HUI_Renderer.Label = r1;   \
    HUI_Renderer.Button = r2; \
    HUI_Renderer.Render = r3; \
    HUI_Renderer.NewElement = NewElement;