

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
    { 
        // printf("d-up ");
        // move cursor up
    }


    else if (kDown & KEY_DOWN)
    {
       // printf("d-down ");
       // move cursor down
    }

    else if (kDown & KEY_LEFT)
    {        
        // printf("d-left ");
        // move cursor left
    }

    else if (kDown & KEY_RIGHT)
    {
        // printf("d-right ");
        // move cursor right
    }

    else if (kDown & KEY_A)
    {
        // printf("A ");
        // increment right digit of byte by one
    }

    else if (kDown & KEY_B)
    {
        // printf("B ");
        // decrement right digit of byte by one
    }

    else if (kDown & KEY_Y)
    {
        // printf("Y ");
        // decrement left digit of byte by one
    }

    else if (kDown & KEY_X)
    {
        // printf("X ");
        // decrement left digit of byte by one
    }

    else if (kDown & KEY_R)
    {
        // printf("R ");
        // increment address by 0x800
    }

    else if (kDown & KEY_L)
    {
        // printf("L ");
        // decrement address by 0x800
    }

    else if (kDown & KEY_ZR)
    {
        // printf("ZR ");
        // increment address by 0x10000000
    }

    else if (kDown & KEY_ZL)
    {
        // printf("ZL ");
        // decrement address by 0x10000000
    }
    else 
        return 0;

    return 0;        
}