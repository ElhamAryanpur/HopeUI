#include "renderer.hpp"

int x = 0;

void test()
{
    auto Text = Renderer::NewElement((char *)"Label");
    Text.content = (char *)"Hello World!";
    Text.style.y = 100;
    Text.style.x = x;
    int color[4] = {255, 255, 255, 255};
    Text.style.foreground = color;

    Renderer::Render(Text);

    x += 1;
}

int main()
{
    Renderer::Init(800, 600, (char *)"Hello World!");
    Renderer::GameLoop(&test);
    Renderer::Close();
}