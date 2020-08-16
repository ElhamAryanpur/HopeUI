#include "HopeUI.h"
#include <stdio.h>

void event()
{
    printf("CLICKED!");
}

void gameLoop()
{
    HUI_Element L = NewElement("Button");

    // L = HUI_SetContent(L, "Hello World!");
    // L = HUI_SetPosition(L, 50, 50);

    Color textColor = {141, 189, 255, 255};
    L.style.foreground = textColor;
    L.content = "Hello World!";
    L.style.x = 50;
    L.style.y = 50;
    L.style.width = 200;
    L.style.height = 100;
    L.callback = &event;

    HUI_Render(L);
}

int main(void)
{
    functiontype callback = &gameLoop;
    Color background = {18, 25, 32, 255};

    HUI_Init(800, 600, "Hope", background, callback);

    return 0;
}
