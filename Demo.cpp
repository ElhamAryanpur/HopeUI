#include "renderer.hpp"

void test()
{
}

int main()
{
    Renderer::Init(800, 600, (char *)"Hello World!");
    Renderer::GameLoop(&test);
    Renderer::Close();
}