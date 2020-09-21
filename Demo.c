#include "HopeUI.h"
#include <stdio.h>

int x = 0; // Define an X variable

// This will be the game loop function.
// Everything inside will run on gameloop
void loop()
{
    // Let's make a label element
    HUI_Element Text = HopeUI.Renderer.NewElement((char *)"Button");

    // Have it say hello World!
    Text.content = (char *)"Hello World!";
    Text.style.width = 300;
    Text.style.height = 150;
    Text.style.y = HopeUI.Renderer.GetWindowHeight() / 2 - 150 / 2;
    Text.style.x = HopeUI.Renderer.GetWindowWidth() / 2 - 150;
    Text.style.fontSize = 50;
    Text.style.border_roundness = 0.5;

    int color[4] = {141, 189, 255, 255};
    Text.style.foreground = color;

    int background[4] = {60, 125, 217, 255};
    Text.style.background = background;

    // Finally give it to render
    HopeUI.Renderer.Render(Text);
}

int main()
{
    // Let's make the window first
    // With 800 width, 600 height, and that title
    HopeUI.Renderer.Init(800, 600, (char *)"Hello World!");

    // And slap our gameloop
    HopeUI.Renderer.GameLoop(&loop);

    // And cleanup after window is closed
    HopeUI.Renderer.Close();

    // finally close up everything
    return 0;
}