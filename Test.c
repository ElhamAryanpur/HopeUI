#include "HopeUI.h"
#include <stdio.h>

void event()
{
    printf("CLICKED!");
}

int main(void)
{
    Color background = {18, 25, 32, 255};

    HUI_Setup();
    getchar();
    return 0;
}
