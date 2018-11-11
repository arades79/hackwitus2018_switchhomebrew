

#pragma once

#include <stdio.h>

#include <switch.h>

// functions to handle kDown presses 

typedef struct Cursor
{
    u8 X;
    u8 Y;
} Cursor;


s8 buttonHandler(Cursor)
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
		if (cursor.Y>0)
		{
			cursor.Y-1;
		}
    }


    else if (kDown & KEY_DOWN)
    {
       // printf("d-down ");
       // move cursor down
        printf("[[D^");
		if (cursor.Y<29 && cursor.X<20)
		{
			cursor.Y+1;
		}
    }

    else if (kDown & KEY_LEFT)
    {        
        // printf("d-left ");
        // move cursor left
		if (cursor.X>0)
		{
			cursor.X-1;
		}
    }

    else if (kDown & KEY_RIGHT)
    {
        // printf("d-right ");
        // move cursor right
		if (cursor.X<40)
		{
			cursor.X+1;
		}
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

    return 1;        
}