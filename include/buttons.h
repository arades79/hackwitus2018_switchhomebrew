

#pragma once

#include <stdio.h>

#include <switch.h>

// functions to handle button presses 


s8 buttonHandler(void)
{
    // Scan all the inputs. This should be done once for each frame
    hidScanInput();

    // hidKeysDown returns information about which buttons have been
    // just pressed in this frame compared to the previous one
    u64 button = hidKeysDown(CONTROLLER_P1_AUTO);

    if (button & KEY_PLUS)
        return -1;
    else if (button & KEY_DUP)
        printf("d-up ");

    else if (button & KEY_DOWN)
        printf("d-down ");

    else if (button & KEY_LEFT)
        printf("d-left ");

    else if (button & KEY_RIGHT)
        printf("d-right ");

    else if (button & KEY_A)
        printf("A ");

    else if (button & KEY_B)
        printf("B ");

    else if (button & KEY_Y)
        printf("Y ");

    else if (button & KEY_X)
        printf("X ");

    else if (button & KEY_R)
        printf("R ");

    else if (button & KEY_L)
        printf("L ");

    else if (button & KEY_ZR)
        printf("ZR ");

    else if (button & KEY_ZL)
        printf("ZL ");
    else 
        return 0;

    return 0;        
}