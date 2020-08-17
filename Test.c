#include "HopeUI.h"
#include <stdio.h>

void event()
{
    printf("CLICKED!");
}

int main(void)
{
    Color background = {18, 25, 32, 255};

    // Begin window and drawing loop
    WINDOW_START(800, 600, "Hope", background);

    HUI_Element L = NewElement("Button");
    Color textColor = {141, 189, 255, 255};
    L.style.foreground = textColor;
    L.content = "Hello World!";
    L.style.x = 50;
    L.style.y = 50;
    L.style.width = 200;
    L.style.height = 100;
    L.callback = &event;

    HUI_Render(L);

    const Rectangle rec = {300, 300, 150, 150};
    DrawRectangleRounded(rec, 0.2, 2, textColor);

    WINDOW_END; // End the window and drawing loop
    return 0;
}
