// standard C library includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// switch library includes
#include <switch.h>

#define BUF_PAGE_SIZE 2048

// Main program entrypoint
// project includes
#include "../include/buttons.h"

int main(int argc, char* argv[])
{
	
	// PrintConsole defaultConsole =
	// {
	// 	//Font:
	// 	{
	// 		NULL, //font gfx
	// 		0, //first ascii character in the set
	// 		256, //number of characters in the font set
	// 		16, //tile width
	// 		16, //tile height
	// 	},
	// 	NULL, //renderer
	// 	10,10, //cursorX cursorY
	// 	10,10, //prevcursorX prevcursorY
	// 	80, //console width
	// 	45, //console height
	// 	0,  //window x
	// 	0,  //window y
	// 	80, //window width
	// 	45, //window height
	// 	3, //tab size
	// 	7, // foreground color
	// 	0, // background color
	// 	0, // flags
	// 	false //console initialized
	// };

    //PrintConsole * console = NULL;
    consoleInit(NULL);
    printf(CONSOLE_MAGENTA);

    Cursor cursor = {0,0};

    // u64 out[3];
    // // Other initialization goes here. As a demonstration, we print hello world.
    // if (envIsSyscallHinted(0x54))
    // {
    //     u32 W0 = svcQueryPhysicalAddress(out, 0x1000);
    //     printf("Ret: %u", W0);
    //     printf("PhysAddr: %lu", out[0]);
    //     printf("KernelAddr: %lu", out[1]);
    //     printf("Size: %lu", out[2]);
    // }
    // else
    //     printf("Insufficient priviledges for needed svcQueryPhysicalAddress\n");

    if (envIsSyscallHinted(0x74))
    {
        Handle han = envGetMainThreadHandle();
        u64 addr = 0x0;
        u8 buff[BUF_PAGE_SIZE];
        svcMapProcessMemory(buff, han, addr, BUF_PAGE_SIZE);
        printf("handle: %u, address: %lx\n", han, addr);
        for (int i = 0; i < BUF_PAGE_SIZE; i++)
        {
            printf("%x", buff[i]);
        }
    }
    else
        printf("Insufficient priviledges for needed svcMapProcessMemory\n\n");


    // Main loop
    while (appletMainLoop())
    {
        s8 buttonState = buttonHandler();

        if (buttonState == -1)
            break;
        else if (buttonState == 1) 
        {
            consoleClear();
        
            Handle han = envGetMainThreadHandle();
            u64 addr = 0x0;
            u8 buff[BUF_PAGE_SIZE];
            svcMapProcessMemory(buff, han, addr, BUF_PAGE_SIZE);
            printf("handle: %u, address: %lx\n", han, addr);
            for (int i = 0; i < BUF_PAGE_SIZE; i++)
            {
                if (i == cursor.X || i - 1 == cursor.X)
                    printf(CONSOLE_YELLOW);
                else if (i - 2 == cursor.X)
                    printf(CONSOLE_MAGENTA);
                printf("%x", buff[i]);
            }
        }
    

        // Your code goes here

        // Update the console, sending a new frame to the display
        // console->cursorX = 1;
        // console->cursorY = 1;
        // console->windowX = 1;
        // console->windowY = 1;
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}