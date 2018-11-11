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
    consoleInit(NULL);

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