#pragma once

/* HopeUI Renderer */
namespace Renderer
{
    typedef void (*functiontype)();

    typedef struct Style
    {
        int x;
        int y;
        int width;
        int height;
        int *background;
        int *foreground;
        int fontSize;
        int spacing;
        bool visible;
        float border_roundness;
    } Style;

    typedef struct Element
    {
        char *id;
        char *element;
        char *content;
        Style style;
        int zIndex;
        functiontype callback;
    } Element;

    /* HopeUI Creates New Element */
    Element NewElement(char *name);

    /* HopeUI Label Element */
    void Label(Element data);

    /* HopeUI Button Element */
    void Button(Element element, functiontype callback);

    /* HopeUI Element Rendering */
    void Render(Element element);

    /* HopeUI Initializes New Window */
    void Init(int width, int height, char *title);

    /* HopeUI Game Loop */
    void GameLoop(functiontype callback);

    /* HopeUI Close Window */
    void Close();

} // namespace Renderer