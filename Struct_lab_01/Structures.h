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

typedef struct{
	int  ts_cost;
	char males[2][7];
	int  males_cost[2];
	char colors[3][6];
	int  colors_cost[3];
	char sizes[4][3];
	int  sizes_cost[4];
	char prints[5][10];
	char prints_texts[5][20];
	int  prints_cost[5];
}TSHIRT_NAMES;

typedef union
{
	struct
	{
		uint64_t save1;
		uint64_t save2;
		uint64_t save3;
	};
	uint64_t save[3];
	struct {
		uint8_t word[20];
		uint8_t arg4;
		uint8_t arg3;
		uint8_t arg2;
		uint8_t arg1;
		//uint32_t type;
	};
}configuration;

typedef enum
{
	/// <summary>
	/// Type: T-shirt
	/// Arg1: Male
	/// </summary>
	TSHIRT_MAN,
	TSHIRT_WOMAN
}T_SHIRT_MALE;

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
	/// <summary>
	/// Type: Pillow
	/// Arg1: Typeof
	/// </summary>
	PILLOW_DAKIMAKURA,
	PILLOW_DEFAULT
}PILLOW_TYPE;

typedef enum
{
	/// <summary>
	/// Type: Pillow
	/// Arg2: Color
	/// </summary>
	PILLOW_RED,
	PILLOW_WHITE
}PILLOW_DEF_COLOR;

typedef enum
{
	/// <summary>
	/// Type: Pillow
	/// Arg3: Print
	/// </summary>
	PILLOW_FLOWERS,
	PILLOW_HEART,
	PILLOW_EMPTY
}PILLOW_DEF_PRINT;

typedef enum
{
	/// <summary>
	/// Type: Pillow
	/// Arg2: Size
	/// </summary>
	PILLOW_DM_L,
	PILLOW_DM_S
}PILLOW_DM_SIZE;

typedef enum
{
	/// <summary>
	/// Type: Pillow
	/// Arg3: Print
	/// </summary>
	PILLOW_DM_REM,
	PILLOW_DM_RAM,
	PILLOW_DM_HITAGI,
	PILLOW_DM_MAI
}PILLOW_DM_PRINT;

TSHIRT_NAMES ts_names;