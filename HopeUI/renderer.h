#pragma once

/* Function Type */
typedef void (*functiontype)();

/* Structure for styling of elements */
typedef struct hrs
{
    int x;
    int y;
    int width;
    int height;
    int *background;
    int *foreground;
    int fontSize;
    int spacing;
    int visible;
    float border_roundness;
} hrs;

/* Element Structure */
typedef struct HUI_Element
{
    char *id;
    char *element;
    char *content;
    hrs style;
    int zIndex;
    functiontype callback;
} HUI_Element;

/* HopeUI Creates New Element */
HUI_Element hrne(char *name);

/* HopeUI Label Element */
void hrl(HUI_Element data);

/* HopeUI Button Element */
void hrb(HUI_Element element, functiontype callback);

/* HopeUI Element Rendering */
void hrr(HUI_Element element);

/* HopeUI Initializes New Window */
void hri(int width, int height, char *title);

/* HopeUI Game Loop */
void hrgl(functiontype callback);

/* HopeUI Close Window */
void hrc();
