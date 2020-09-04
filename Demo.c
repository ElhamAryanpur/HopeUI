// Include the header
#include "HopeUI.h"

int main()
{
    // Define a background color. (RGBA)
    Color background = {100, 100, 100, 255};

    // Initialize required stuff
    HUI_Init;

    // Initialize Window. (width, height, title, background)
    HUI_Window_Start(800, 600, "Hi", background);

    HUI_Element Label = HUI_Renderer.NewElement("Label"); // Initialize
    Label.content = "Hello World!";                       // The content or text
    Label.style.x = 50;                                   // X on screen
    Label.style.y = 50;                                   // Y on screen

    HUI_Renderer.Render(Label); // Render it

    HUI_Window_End; // And when the window is closed
}