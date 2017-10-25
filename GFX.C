#include <stdio.h>
#include <stdlib.h>
#include <alloc.h>
#include <conio.h>
#include <graphics.h>

#include "gfx.h"

int gfxDriver 	= CGA;
int gfxMode 	= 0;
int gfxError;

void GFX_Init()
{
	if (registerbgidriver(CGA_driver) < 0)
	{
		printf("Error initializing graphics driver!\n");
		exit (-1);
	}
	
	if (registerbgifont(small_font) < 0)
	{
		printf("Error initializing font!\n");
		exit (-1);
	}
	
	initgraph( &gfxDriver, &gfxMode, "");
	if( graphresult() != grOk)
	{
		printf("Error initializing graphics mode!\n");
		exit(-1);
	}
}

void GFX_Free()
{
	closegraph();
	restorecrtmode();
}


