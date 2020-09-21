#pragma once

#include "renderer.h"

struct HopeUI
{
    struct Renderer
    {
        HUI_Element Element;
        HUI_Element (*NewElement)(char *);
        void (*Label)(HUI_Element);
        void (*Button)(HUI_Element, functiontype);
        void (*Render)(HUI_Element);
        void (*Init)(int, int, char *);
        void (*GameLoop)(functiontype);
        void (*Close)();
        int (*GetWindowWidth)();
        int (*GetWindowHeight)();
        void (*SetWindowWidth)(int w);
        void (*SetWindowHeight)(int h);
    } Renderer;
} HopeUI = {
    .Renderer = {
        .NewElement = hrne,
        .Label = hrel,
        .Button = hreb,
        .Render = hrr,
        .Init = hri,
        .GameLoop = hrgl,
        .Close = hrc,
        .GetWindowWidth = hrgww,
        .GetWindowHeight = hrgwh,
        .SetWindowWidth = hrsww,
        .SetWindowHeight = hrswh}};
