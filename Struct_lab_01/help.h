#pragma once

#define START_WINDOW "In this app you can config your own product\n"

#define START_MENU "1: Create congig\n2: Save config\n3: Load config\n4: See config\n5: Check price\n\n0: Close app\n\nType a number here to choose\n> "

#define WRONG_NUMBER "\nYou typed wrong number!\nType a number here to choose\n> "

#define CREATE_MENU "What will we do?\n    1: T-SHIRT\n    2: Pillow (in progress)\n\n0: Back\n\nType a number here to choose\n> "

#define TSHIRT_MENU_MAN "Type: %s, cost: %d\n\n1:     Male: %s\n2:     Size: %s, cost: %d\n3:     Print: %s, cost: %d\n4:     Color: %s, cost: %d\n\n0:     Back\n\nType a number here to choose\n> "

#define TSHIRT_MENU_WOMAN "Type: %s, cost: %d\n\n1:     Male: %s\n2:     Size: %s, cost: %d\n3:     Print: %s, cost: %d\n4:     Color: %s, cost: %d\n5:     Rhinestones: %s, cost: %d\n\n0:     Back\n\nType a number here to choose\n> "

#define TSHIRT_MENU_MALE "Male: %s\n\n1:     male \n2:     female\n\n0:     Back\n\nType a number here to choose\n> "

#define TSHIRT_MENU_SIZE "Size: %s, cost: %d\n\n1:     S , cost: %d\n2:     M , cost: %d\n3:     L , cost: %d\n4:     XL, cost: %d\n\n0:     Back\n\nType a number here to choose\n> "

#define TSHIRT_MENU_PRINT_MALE   "Print: %s, text: %s, cost: %d\n\n1:     empty, text:               , cost: %d\n2:     cars , text: You drive it! , cost: %d\n3:     guns , text: Russian roulet, cost: %d\n\n0:     Back\n\nType a number here to choose\n> "

#define TSHIRT_MENU_PRINT_FEMALE "Print: %s, text: %s, cost: %d\n\n1:     empty, text:               , cost: %d\n2:     roses, text: Flowers!      , cost: %d\n3:     heart, text: Believe in you, cost: %d\n\n0:     Back\n\nType a number here to choose\n> "

#define TSHIRT_MENU_COLOR "Color: %s, cost: %d\n\n1:     red  , cost: %d\n2:     white, cost: %d\n3:     black, cost: %d\n\n0:     Back\n\nType a number here to choose\n> "

#define TSHIRT_SEE_MAN "Type: %s, cost: %d\nMale: %s\nSize: %s, cost: %d\nPrint: %s, cost: %d\nColor: %s, cost: %d\n\n0:     Back\n\nType 0 to exit\n> "

#define TSHIRT_SEE_WOMAN "Type: %s, cost: %d\nMale: %s\nSize: %s, cost: %d\nPrint: %s, cost: %d\nColor: %s, cost: %d\nRhinestones: %s, cost: %d\n\n0:     Back\n\nType 0 to exit\n> "

#define COST_SEE "Cost of your config: %d\n\n0: Back\n\nType 0 to exit\n> "

#define TSHIRT_MENU_RHINE "Rhinestones: %s\n\n1:     %s, cost: %d \n2:     %s, cost: %d\n\n0:     Back\n\nType a number here to choose\n> "

#define SAVE_TYPE "It's time to save your config!\n\nType your filename (up to 20 symbols, more will ignore)\n> "
#define SAVE_ERR1 "\nYou really want to overwrite save? (y/n)\n> "
#define SAVE_ERR2 "Filename is wrong, try again\n> "

typedef enum
{
	EXIT,
	CREATE_CONFIG,
	SAVE_CONFIG,
	IMPORT_CONFIG,
	VIEW_CONFIG,
	CHECK_PRICE
}MENU_TYPE;