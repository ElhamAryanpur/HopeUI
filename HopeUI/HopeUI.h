#pragma once

#include "renderer.h"

struct HopeUI
{
    struct Renderer
    {
        HUI_Element Element;
        HUI_Element (*NewElement)();
        void (*Label)(HUI_Element);
        void (*Button)(HUI_Element, functiontype);
        void (*Render)(HUI_Element);
        void (*Init)(int, int, char *);
        void (*GameLoop)(functiontype);
        void (*Close)();
    } Renderer;
} HopeUI = {
    .Renderer = {
        .NewElement = hrne,
        .Label = hrl,
        .Button = hrb,
        .Render = hrr,
        .Init = hri,
        .GameLoop = hrgl,
        .Close = hrc}};
