

#pragma once

#include <stdio.h>

#include <switch.h>

// functions to handle kDown presses 


s8 buttonHandler(void)
{
    // Scan all the inputs. This should be done once for each frame
    hidScanInput();

    // hidKeysDown returns information about which buttons have been
    // just pressed in this frame compared to the previous one
    u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);

    if (kDown & KEY_PLUS)
        return -1;
    else if (kDown & KEY_DUP)
        printf("d-up ");

    else if (kDown & KEY_DOWN)
        printf("d-down ");

    else if (kDown & KEY_LEFT)
        printf("d-left ");

    else if (kDown & KEY_RIGHT)
        printf("d-right ");

    else if (kDown & KEY_A)
        printf("A ");

    else if (kDown & KEY_B)
        printf("B ");

    else if (kDown & KEY_Y)
        printf("Y ");

    else if (kDown & KEY_X)
        printf("X ");

    else if (kDown & KEY_R)
        printf("R ");

    else if (kDown & KEY_L)
        printf("L ");

    else if (kDown & KEY_ZR)
        printf("ZR ");

    else if (kDown & KEY_ZL)
        printf("ZL ");
    else 
        return 0;

    return 0;        
}