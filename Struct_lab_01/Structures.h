#pragma once
#include "help.h"

typedef enum
{
	CREATE_CONFIG,
	SAVE_CONFIG,
	IMPORT_CONFIG,
	VIEW_CONFIG,
	CHECK_PRICE
}MENU_TYPE;

typedef enum
{
	/// <summary>
	/// Type: T-shirt
	/// Arg1: Male
	/// Arg2: Color
	/// Arg3: Size
	/// Arg4: Print
	/// </summary>
	TSHIRT,
	TSHIRT_MAN,
	TSHIRT_WOMAN,
	TSHIRT_RED,
	TSHIRT_WHITE,
	TSHIRT_BLACK,
	TSHIRT_SIZE_S,
	TSHIRT_SIZE_M,
	TSHIRT_SIZE_L,
	TSHIRT_SIZE_XL,
	TSHIRT_PRINT_EMPTY,
	TSHIRT_PRINT_CARS,
	TSHIRT_PRINT_GUNS,
	TSHIRT_PRINT_ROSES,
	TSHIRT_PRINT_HEART,
	/// <summary>
	/// Type: Cup
	/// Arg1: Color
	/// Arg2: Size
	/// </summary>
	CUP,
	CUP_WHITE,
	CUP_BLACK,
	CUP_RED,
	CUP_BLUE,
	CUP_GREEN,
	CUP_ORANGE,
	CUP_L,
	CUP_M,
	CUP_S,
	/// <summary>
	/// Type: Pillow
	/// Arg1: p_type
	/// Arg2: if DM: DM_hero
	/// Arg2: if U:  Color
	/// Arg3: if U:  Print
	/// </summary>
	PILLOW,
	PILLOW_DAKIMAKURA,
	PILLOW_DM_L,
	PILLOW_DM_S,
	PILLOW_DM_REM,
	PILLOW_DM_RAM,
	PILLOW_DM_HITAGI,
	PILLOW_DM_MAI,
	PILLOW_DEFAULT,
	PILLOW_RED,
	PILLOW_WHITE,
	PILLOW_FLOWERS,
	PILLOW_HEART,
	PILLOW_EMPTY
}COMP_NUM;

typedef struct
{
	int component_price;
	int component_lvl;
	char* component_name;
}component;

typedef struct
{
	int components_count;
	component* components_array;
}database;

typedef union
{
	uint64_t save;
	uint8_t type;
	uint8_t arg1;
	uint8_t arg2;
	uint8_t arg3;
}configuration;