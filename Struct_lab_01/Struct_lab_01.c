#include "Structures.h"

/// <summary>
/// запись варианта
/// </summary>
/// <param name="conf"></param>

void save(configuration* conf)
{
	char filename[21];
	int menu_selected_num = -1;
	FILE* file;

	menu_selected_num = -1;
	filename[0] = '\0';
	system("cls");
	printf(SAVE_TYPE);
save_start:
	scanf("%20s%*[^\n]%*c", filename);
	file = fopen(filename, "r");
	if (file == NULL)
	{
		file = fopen(filename, "w");
		if (file == NULL)
		{
			clearRowScreen(3);
			printf(SAVE_ERR2);
			goto save_start;
		}
		else
		{
			fprintf(file, "%llu %llu", conf->male, conf->save);
			fclose(file);
		}
	}
	else
	{
	save_start2:
		printf(SAVE_ERR1);
		char c[3] = { NULL, NULL, '\0' };
		scanf("%2s%*[^\n]%*c", &c);
		if (c[1] == NULL) {
			if (c[0] == 'y')
			{
				fclose(file);
				file = fopen(filename, "w");
				if (file == NULL)
				{
					clearRowScreen(3);
					printf(SAVE_ERR2);
					goto save_start;
				}
				else
				{
					fprintf(file, "%llu %llu", conf->male, conf->save);
					fclose(file);
				}
			}
			else
			{

			}
		}
		else
		{
			clearRowScreen(3);
			goto save_start2;
		}
	}
}

void load(configuration* conf)
{
	char filename[21];
	int menu_selected_num = -1;
	FILE* file;

	menu_selected_num = -1;
	filename[0] = '\0';
	system("cls");
	printf(SAVE_TYPE);
load_start:
	scanf("%20s%*[^\n]%*c", filename);
	file = fopen(filename, "r");
	if (file == NULL)
	{
		clearRowScreen(3);
		printf(SAVE_ERR2);
		goto load_start;
	}
	else
	{
		fscanf(file, "%llu %llu", &(conf->male), &(conf->save));
		fclose(file);
	}
}

int see_config(configuration* conf)
{
	int menu_selected_num = -1;

	menu_selected_num = -1;
	system("cls");

	switch (conf->male)
	{
	case 0:
		printf(TSHIRT_SEE_MAN, "T-shirt", ts_names.ts_cost, ts_names.males[conf->male], ts_names.sizes[conf->t_man.size], ts_names.sizes_cost[conf->t_man.size], 
			ts_names.prints[conf->t_man.print], ts_names.prints_cost[conf->t_man.print], ts_names.colors[conf->t_man.color], ts_names.colors_cost[conf->t_man.color]);
		break;
	case 1:
		printf(TSHIRT_SEE_WOMAN, "T-shirt", ts_names.ts_cost, ts_names.males[conf->male], ts_names.sizes[conf->t_woman.size], ts_names.sizes_cost[conf->t_woman.size],
			ts_names.prints[conf->t_woman.print], ts_names.prints_cost[conf->t_woman.print], ts_names.colors[conf->t_woman.color], ts_names.colors_cost[conf->t_woman.color],
			ts_names.rhinestones[conf->t_woman.rhinestones], ts_names.rhinestones_cost[conf->t_woman.rhinestones]);
		break;
	}
	while (menu_selected_num < 0 || menu_selected_num > 2)
	{
		menu_selected_num = read_num();
		switch (menu_selected_num)
		{
		case 0:
			return 0;
		default:
			clearRowScreen(8);
			printf(WRONG_NUMBER);
			break;
		}
	}
	return 0;
}

int check_price(configuration* conf)
{
	int price = 0;
	switch (conf->male)
	{
	case 0:
		price += ts_names.ts_cost;
		price += ts_names.prints_cost[conf->t_man.print];
		price += ts_names.colors_cost[conf->t_man.color];
		price += ts_names.sizes_cost[conf->t_man.size];
	case 1:
		price += ts_names.ts_cost;
		price += ts_names.prints_cost[conf->t_woman.print];
		price += ts_names.colors_cost[conf->t_woman.color];
		price += ts_names.sizes_cost[conf->t_woman.size];
		price += ts_names.rhinestones_cost[conf->t_woman.rhinestones];
	}


	int menu_selected_num = -1;

t_menu_start:
	menu_selected_num = -1;
	system("cls");
	printf(COST_SEE, price);
	while (menu_selected_num < 0 || menu_selected_num > 0)
	{
		menu_selected_num = read_num();
		switch (menu_selected_num)
		{
		case 0:
			return 0;
		default:
			clearRowScreen(4);
			printf(WRONG_NUMBER);
			break;
		}
	}
	return 0;

}

int pillow_menu(configuration* conf)
{
	int menu_selected_num = -1;

p_menu_start:
	menu_selected_num = -1;
	system("cls");
	printf("Unaviable\n\n0: Back\n\nType a number here to choose\n> ");
	while (menu_selected_num < 0 || menu_selected_num > 0)
	{
		menu_selected_num = read_num();
		switch (menu_selected_num)
		{
		case 0:
			return 0;
		default:
			goto p_menu_start;
		}
	}
	return 0;
}

int t_shirt_menu_color(configuration* conf)
{
	int menu_selected_num = -1;

t_menu_color_start:
	menu_selected_num = -1;
	system("cls");
	switch (conf->male)
	{
	case 0:
		printf(TSHIRT_MENU_COLOR, ts_names.colors[conf->t_man.color], ts_names.colors_cost[conf->t_man.color], ts_names.colors_cost[TSHIRT_COLOR_RED], ts_names.colors_cost[TSHIRT_COLOR_WHITE], ts_names.colors_cost[TSHIRT_COLOR_BLACK]);
		while (menu_selected_num < 0 || menu_selected_num > 3)
		{
			menu_selected_num = read_num();
			switch (menu_selected_num)
			{
			case 0:
				return 0;
			case 1:
				conf->t_man.color = TSHIRT_COLOR_RED;
				goto t_menu_color_start;
			case 2:
				conf->t_man.color = TSHIRT_COLOR_WHITE;
				goto t_menu_color_start;
			case 3:
				conf->t_man.color = TSHIRT_COLOR_BLACK;
				goto t_menu_color_start;
			default:
				clearRowScreen(8);
				printf(WRONG_NUMBER);
				break;
			}
		}
		break;
	case 1:
		printf(TSHIRT_MENU_COLOR, ts_names.colors[conf->t_woman.color], ts_names.colors_cost[conf->t_woman.color], ts_names.colors_cost[TSHIRT_COLOR_RED], ts_names.colors_cost[TSHIRT_COLOR_WHITE], ts_names.colors_cost[TSHIRT_COLOR_BLACK]);
		while (menu_selected_num < 0 || menu_selected_num > 3)
		{
			menu_selected_num = read_num();
			switch (menu_selected_num)
			{
			case 0:
				return 0;
			case 1:
				conf->t_woman.color = TSHIRT_COLOR_RED;
				goto t_menu_color_start;
			case 2:
				conf->t_woman.color = TSHIRT_COLOR_WHITE;
				goto t_menu_color_start;
			case 3:
				conf->t_woman.color = TSHIRT_COLOR_BLACK;
				goto t_menu_color_start;
			default:
				clearRowScreen(8);
				printf(WRONG_NUMBER);
				break;
			}
		}
		break;
	}
	return 0;
}

int t_shirt_menu_print(configuration* conf)
{
	int menu_selected_num = -1;

t_menu_print_start:
	menu_selected_num = -1;
	system("cls");
	if (conf->male)
	{
		printf(TSHIRT_MENU_PRINT_FEMALE, ts_names.prints[conf->t_woman.print], ts_names.prints_texts[conf->t_woman.print], ts_names.prints_cost[conf->t_woman.print], ts_names.prints_cost[TSHIRT_PRINT_EMPTY], ts_names.prints_cost[TSHIRT_PRINT_ROSES], ts_names.prints_cost[TSHIRT_PRINT_HEART]);
		while (menu_selected_num < 0 || menu_selected_num > 3)
		{
			menu_selected_num = read_num();
			switch (menu_selected_num)
			{
			case 0:
				return 0;
			case 1:
				conf->t_woman.print = TSHIRT_PRINT_EMPTY;
				goto t_menu_print_start;
			case 2:
				conf->t_woman.print = TSHIRT_PRINT_ROSES;
				goto t_menu_print_start;
			case 3:
				conf->t_woman.print = TSHIRT_PRINT_HEART;
				goto t_menu_print_start;
			default:
				clearRowScreen(8);
				printf(WRONG_NUMBER);
				break;
			}
		}
	}
	else
	{
		printf(TSHIRT_MENU_PRINT_MALE, ts_names.prints[conf->t_man.print], ts_names.prints_texts[conf->t_man.print], ts_names.prints_cost[conf->t_man.print], ts_names.prints_cost[TSHIRT_PRINT_EMPTY], ts_names.prints_cost[TSHIRT_PRINT_CARS], ts_names.prints_cost[TSHIRT_PRINT_GUNS]);
		while (menu_selected_num < 0 || menu_selected_num > 3)
		{
			menu_selected_num = read_num();
			switch (menu_selected_num)
			{
			case 0:
				return 0;
			case 1:
				conf->t_man.print = TSHIRT_PRINT_EMPTY;
				goto t_menu_print_start;
			case 2:
				conf->t_man.print = TSHIRT_PRINT_CARS;
				goto t_menu_print_start;
			case 3:
				conf->t_man.print = TSHIRT_PRINT_GUNS;
				goto t_menu_print_start;
			default:
				clearRowScreen(8);
				printf(WRONG_NUMBER);
				break;
			}
		}
	}

	return 0;
}

int t_shirt_menu_size(configuration* conf)
{
	int menu_selected_num = -1;

t_menu_size_start:
	menu_selected_num = -1;
	system("cls");
	switch (conf->male)
	{
	case 0:
		printf(TSHIRT_MENU_SIZE, ts_names.sizes[conf->t_man.size], ts_names.sizes_cost[conf->t_man.size], ts_names.sizes_cost[TSHIRT_SIZE_S], ts_names.sizes_cost[TSHIRT_SIZE_M], ts_names.sizes_cost[TSHIRT_SIZE_L], ts_names.sizes_cost[TSHIRT_SIZE_XL]);
		while (menu_selected_num < 0 || menu_selected_num > 4)
		{
			menu_selected_num = read_num();
			switch (menu_selected_num)
			{
			case 0:
				return 0;
			case 1:
				conf->t_man.size = TSHIRT_SIZE_S;
				goto t_menu_size_start;
			case 2:
				conf->t_man.size = TSHIRT_SIZE_M;
				goto t_menu_size_start;
			case 3:
				conf->t_man.size = TSHIRT_SIZE_L;
				goto t_menu_size_start;
			case 4:
				conf->t_man.size = TSHIRT_SIZE_XL;
				goto t_menu_size_start;
			default:
				clearRowScreen(9);
				printf(WRONG_NUMBER);
				break;
			}
		}
		break;
	case 1:
		printf(TSHIRT_MENU_SIZE, ts_names.sizes[conf->t_woman.size], ts_names.sizes_cost[conf->t_woman.size], ts_names.sizes_cost[TSHIRT_SIZE_S], ts_names.sizes_cost[TSHIRT_SIZE_M], ts_names.sizes_cost[TSHIRT_SIZE_L], ts_names.sizes_cost[TSHIRT_SIZE_XL]);
		while (menu_selected_num < 0 || menu_selected_num > 4)
		{
			menu_selected_num = read_num();
			switch (menu_selected_num)
			{
			case 0:
				return 0;
			case 1:
				conf->t_woman.size = TSHIRT_SIZE_S;
				goto t_menu_size_start;
			case 2:
				conf->t_woman.size = TSHIRT_SIZE_M;
				goto t_menu_size_start;
			case 3:
				conf->t_woman.size = TSHIRT_SIZE_L;
				goto t_menu_size_start;
			case 4:
				conf->t_woman.size = TSHIRT_SIZE_XL;
				goto t_menu_size_start;
			default:
				clearRowScreen(9);
				printf(WRONG_NUMBER);
				break;
			}
		}
		break;
	}
	return 0;
}

int t_shirt_menu_male(configuration* conf)
{
	int menu_selected_num = -1;

t_menu_male_start:
	menu_selected_num = -1;
	system("cls");
	printf(TSHIRT_MENU_MALE, ts_names.males[conf->male]);
	while (menu_selected_num < 0 || menu_selected_num > 2)
	{
		menu_selected_num = read_num();
		switch (menu_selected_num)
		{
		case 0:
			return 0;
		case 1:
			conf->male = 0;
			goto t_menu_male_start;
		case 2:
			conf->male = 1;
			goto t_menu_male_start;
		default:
			clearRowScreen(7);
			printf(WRONG_NUMBER);
			break;
		}
	}
	return 0;
}

int t_shirt_menu_rhine(configuration* conf) 
{
	int menu_selected_num = -1;

t_menu_rhine_start:
	menu_selected_num = -1;
	system("cls");
	printf(TSHIRT_MENU_RHINE, ts_names.rhinestones[conf->t_woman.rhinestones],
		ts_names.rhinestones[TSHIRT_RHINESTONES_YES], ts_names.rhinestones_cost[TSHIRT_RHINESTONES_YES],
		ts_names.rhinestones[TSHIRT_RHINESTONES_NO], ts_names.rhinestones_cost[TSHIRT_RHINESTONES_NO]);
	while (menu_selected_num < 0 || menu_selected_num > 2)
	{
		menu_selected_num = read_num();
		switch (menu_selected_num)
		{
		case 0:
			return 0;
		case 1:
			conf->t_woman.rhinestones = TSHIRT_RHINESTONES_YES;
			goto t_menu_rhine_start;
		case 2:
			conf->t_woman.rhinestones = TSHIRT_RHINESTONES_NO;
			goto t_menu_rhine_start;
		default:
			clearRowScreen(7);
			printf(WRONG_NUMBER);
			break;
		}
	}
	return 0;
}

int t_shirt_menu(configuration* conf)
{
	int menu_selected_num = -1;

t_menu_start:
	menu_selected_num = -1;
	system("cls");
	switch (conf->male)
	{
	case 0:
		printf(TSHIRT_MENU_MAN, "T-shirt", 10, ts_names.males[conf->male], 
			ts_names.sizes[conf->t_man.size], ts_names.sizes_cost[conf->t_man.size],
			ts_names.prints[conf->t_man.print], ts_names.prints_cost[conf->t_man.print],
			ts_names.colors[conf->t_man.color], ts_names.colors_cost[conf->t_man.color]);
		while (menu_selected_num < 0 || menu_selected_num > 2)
		{
			menu_selected_num = read_num();
			switch (menu_selected_num)
			{
			case 0:
				return 0;
			case 1:
				t_shirt_menu_male(conf);
				goto t_menu_start;
			case 2:
				t_shirt_menu_size(conf);
				goto t_menu_start;
			case 3:
				t_shirt_menu_print(conf);
				goto t_menu_start;
			case 4:
				t_shirt_menu_color(conf);
				goto t_menu_start;
			default:
				clearRowScreen(9);
				printf(WRONG_NUMBER);
				break;
			}
		}
		break;
	case 1:
		printf(TSHIRT_MENU_WOMAN, "T-shirt", 10, ts_names.males[conf->male],
			ts_names.sizes[conf->t_woman.size], ts_names.sizes_cost[conf->t_woman.size],
			ts_names.prints[conf->t_woman.print], ts_names.prints_cost[conf->t_woman.print],
			ts_names.colors[conf->t_woman.color], ts_names.colors_cost[conf->t_woman.color],
			ts_names.rhinestones[conf->t_woman.rhinestones], ts_names.rhinestones_cost[conf->t_woman.rhinestones]);
		
		while (menu_selected_num < 0 || menu_selected_num > 2)
		{
			menu_selected_num = read_num();
			switch (menu_selected_num)
			{
			case 0:
				return 0;
			case 1:
				t_shirt_menu_male(conf);
				goto t_menu_start;
			case 2:
				t_shirt_menu_size(conf);
				goto t_menu_start;
			case 3:
				t_shirt_menu_print(conf);
				goto t_menu_start;
			case 4:
				t_shirt_menu_color(conf);
				goto t_menu_start;
			case 5:
				t_shirt_menu_rhine(conf);
				goto t_menu_start;
			default:
				clearRowScreen(9);
				printf(WRONG_NUMBER);
				break;
			}
		}
		break;
	}
	
	return 0;
}

int choose_type_menu(configuration* conf)
{
	int menu_selected_num = -1;
ct_start:
	menu_selected_num = -1;
	system("cls");
	printf(CREATE_MENU);
	while (menu_selected_num < 0 || menu_selected_num > 2)
	{
		menu_selected_num = read_num();
		switch (menu_selected_num)
		{
		case 0:
			return 0;
		case 1:
			t_shirt_menu(conf);
			goto ct_start;
		case 2:
			pillow_menu(conf);
			goto ct_start;
		default:
			clearRowScreen(6);
			printf(WRONG_NUMBER);
			break;
		}
	}
	return 0;
}

MENU_TYPE start_menu()
{
	int menu_selected_num = -1;

	system("cls");
	printf(START_WINDOW);
	printf(START_MENU);

	while (menu_selected_num < 0 || menu_selected_num > 5)
	{
		menu_selected_num = read_num();
		if (menu_selected_num == -1)
		{
			clearRowScreen(9);
			printf(WRONG_NUMBER);
		}
		else if (menu_selected_num == 0)
			return 0;
		else {
			if (menu_selected_num > 0 && menu_selected_num < 6)
				return menu_selected_num;
			else
			{
				clearRowScreen(9);
				printf(WRONG_NUMBER);
			}
		}
	}
	return 0;
}

int main()
{
	configuration config;

	configuration* conf = &config;
	init();
	conf->male = 0;
	conf->t_man.color = TSHIRT_COLOR_RED;
	conf->t_man.size = TSHIRT_SIZE_S;
	conf->t_man.print = TSHIRT_PRINT_EMPTY;
	conf->t_woman.color = TSHIRT_COLOR_RED;
	conf->t_woman.size = TSHIRT_SIZE_S;
	conf->t_woman.print = TSHIRT_PRINT_EMPTY;
	conf->t_woman.rhinestones = TSHIRT_RHINESTONES_NO;


	MENU_TYPE st_men;

start:
	st_men = start_menu();
	switch (st_men)
	{
	case EXIT:
		return 0;
	case CREATE_CONFIG:
		choose_type_menu(conf);
		goto start;
	case VIEW_CONFIG:
		see_config(conf);
		goto start;
	case CHECK_PRICE:
		check_price(conf);
		goto start;
	case SAVE_CONFIG:
		save(conf);
		goto start;
	case IMPORT_CONFIG:
		load(conf);
		goto start;
	default:
		break;
	}

}