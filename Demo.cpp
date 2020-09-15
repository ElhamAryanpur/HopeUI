#include "HopeUI.hpp"

int x = 0; // Define an X variable

// This will be the game loop function.
// Everything inside will run on gameloop
void loop()
{
    // Let's make a label element
    auto Text = Renderer::NewElement((char *)"Button");

    // Have it say hello World!
    Text.content = (char *)"Hello World!";
    Text.style.y = 100;
    Text.style.x = 100;
    Text.style.width = 300;
    Text.style.height = 150;
    Text.style.fontSize = 50;

    int color[4] = {141, 189, 255, 255};
    Text.style.foreground = color;

    int background[4] = {60, 125, 217, 255};
    Text.style.background = background;

    // Finally give it to render
    Renderer::Render(Text);
}

int main()
{
    // Let's make the window first
    Renderer::Window win;
    
    // With 800 width, 600 height, and that title
    win.Init(800, 600, (char *)"Hello World!");

    // And slap our gameloop
    win.GameLoop(&loop);

    // And cleanup after window is closed
    win.Close();

    // finally close up everything
    return 0;
}