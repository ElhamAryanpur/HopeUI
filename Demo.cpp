#include "HopeUI.hpp"

int x = 0; // Define an X variable

// This will be the game loop function.
// Everything inside will run on gameloop
void loop()
{
    // Let's make a label element
    auto Text = Renderer::NewElement((char *)"Label");

    // Have it say hello World!
    Text.content = (char *)"Hello World!";

    // And at position 100 from top
    Text.style.y = 100;

    // And position according to variable x from left
    Text.style.x = x;

    // Let's color the font white
    // So gonna define an RGBA list of ints
    int color[4] = {255, 255, 255, 255};

    // And assign the color
    Text.style.foreground = color;

    // Finally give it to render
    Renderer::Render(Text);

    // And increase x by 1 so that it have something like an animation
    x += 1;
}

int main()
{
    // Let's make the window first
    // With 800 width, 600 height, and that title
    Renderer::Init(800, 600, (char *)"Hello World!");

    // And slap our gameloop
    Renderer::GameLoop(&loop);

    // And cleanup after window is closed
    Renderer::Close();

    // finally close up everything
    return 0;
}