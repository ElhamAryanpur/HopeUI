#include "renderer.hpp"

void test()
{
    Renderer::Element Text = Renderer::NewElement("Label");
    Text.content = "Hello World!";
    Text.style.y = 50;
    Text.style.x = 50;
    int color[4] = {255, 255, 255, 255};
    Text.style.foreground = color;

    Renderer::Render(Text);
}

int main()
{
    Renderer::Init(800, 600, (char *)"Hello World!");
    Renderer::GameLoop(&test);
    Renderer::Close();

    // TODO: Make a way for the fonts
}