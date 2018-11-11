// standard C library includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// switch library includes
#include <switch.h>

// project includes
#include "../include/buttons.h"

int main(int argc, char* argv[])
{
    consoleInit(NULL);

    // Other initialization goes here. As a demonstration, we print hello world.
    printf("Eat my ass!\n");

    // Main loop
    while (appletMainLoop())
    {
        if (buttonHandler())
            break;

        // Your code goes here

        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}