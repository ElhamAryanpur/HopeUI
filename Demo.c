// Include the header
#include "HopeUI.h"

int main(){
    // Define a background color. (RGBA)
    Color background = {0, 0, 0, 255};
    
    // Initialize required stuff
    HUI_Init;

    // Initialize Window. (width, height, title, background)
    HUI_Window_Start(800, 600, "Hi", background);
    
    // Rest of code goes here

    HUI_Window_End; // And when the window is closed
}