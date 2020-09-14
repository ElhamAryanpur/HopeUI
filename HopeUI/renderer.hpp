#pragma once

/* HopeUI Renderer */
namespace Renderer
{
    int Background[4] = {0, 0, 0, 255};

    typedef void (*functiontype)();

    typedef struct HUI_Style
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
    } HUI_Style;

    typedef struct HUI_Element
    {
        char *id;
        char *element;
        char *content;
        HUI_Style style;
        int zIndex;
        functiontype callback;
    } HUI_Element;

    void HUI_null() {}

    /* HopeUI Creates New Element */
    HUI_Element NewElement(char *name);

    /* HopeUI Label Element */
    void Label(HUI_Element data);

    /* HopeUI Button Element */
    void Button(HUI_Element element, functiontype callback);

    /* HopeUI Element Rendering */
    void Render(HUI_Element element);

    /* HopeUI Initializes New Window */
    void Init(int width, int height, char *title);

    /* HopeUI Game Loop */
    void GameLoop(functiontype callback);

    /* HopeUI Close Window */
    void Close();

} // namespace Renderer