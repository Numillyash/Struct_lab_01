#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "help.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <stdint.h>
#include <locale.h>

void setPos(int row);

void clearRowScreen(int row);

int read_num();

void init();

//int t_shirt_prices[] = { 1 };
//int cup_prices[] = { 1 };
//int pillow_prices[] = { 1 };

typedef struct {
	int  ts_cost;
	char males[2][7];
	char colors[3][6];
	int  colors_cost[3];
	char sizes[4][3];
	int  sizes_cost[4];
	char prints[5][10];
	char prints_texts[5][20];
	int  prints_cost[5];
	char rhinestones[2][4];
	int rhinestones_cost[2];
}TSHIRT_NAMES;

typedef enum
{
	/// <summary>
	/// Type: T-shirt
	/// Arg2: Color
	/// </summary>
	TSHIRT_COLOR_RED,
	TSHIRT_COLOR_WHITE,
	TSHIRT_COLOR_BLACK
}T_SHIRT_COLOR;

typedef enum
{
	/// <summary>
	/// Type: T-shirt
	/// Arg3: Size
	/// </summary>
	TSHIRT_SIZE_S,
	TSHIRT_SIZE_M,
	TSHIRT_SIZE_L,
	TSHIRT_SIZE_XL
}T_SHIRT_SIZE;

typedef enum
{
	/// <summary>
	/// Type: T-shirt
	/// Arg4: Print
	/// </summary>
	TSHIRT_PRINT_EMPTY,
	TSHIRT_PRINT_CARS,
	TSHIRT_PRINT_GUNS,
	TSHIRT_PRINT_ROSES,
	TSHIRT_PRINT_HEART
}T_SHIRT_PRINT;

typedef enum
{
	TSHIRT_RHINESTONES_NO,
	TSHIRT_RHINESTONES_YES
}T_SHIRT_RHINESTONES;

typedef struct {
	uint8_t color;
	uint8_t size;
	uint8_t print;
} TSHIRT_MAN;

typedef struct {
	uint8_t rhinestones;
	uint8_t color;
	uint8_t size;
	uint8_t print;
} TSHIRT_WOMAN;

typedef struct
{
	uint64_t male;
	union
	{
		uint64_t save;
		TSHIRT_MAN t_man;
		TSHIRT_WOMAN t_woman;
	};
	
}configuration;

TSHIRT_NAMES ts_names;