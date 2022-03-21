#include "Structures.h"

#define filename "costs.cfg"

void get_costs()
{
	int xyz;
	FILE* file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Price file doesnt exist, check file \"costs.cfg\" in folder!");
		exit(-1);
	}
	else
	{
		xyz = fscanf(file, "T-Shirt cost: %d\n", &(ts_names.ts_cost));
		xyz = fscanf(file, "T-Shirt male cost: %d\n", &(ts_names.males_cost[0]));
		xyz = fscanf(file, "T-Shirt female cost: %d\n", &(ts_names.males_cost[1]));
		xyz = fscanf(file, "T-Shirt color red cost: %d\n", &(ts_names.colors_cost[0]));
		xyz = fscanf(file, "T-Shirt color white cost: %d\n", &(ts_names.colors_cost[1]));
		xyz = fscanf(file, "T-Shirt color black cost: %d\n", &(ts_names.colors_cost[2]));
		xyz = fscanf(file, "T-Shirt size S cost: %d\n", &(ts_names.sizes_cost[0]));
		xyz = fscanf(file, "T-Shirt size M cost: %d\n", &(ts_names.sizes_cost[1]));
		xyz = fscanf(file, "T-Shirt size L cost: %d\n", &(ts_names.sizes_cost[2]));
		xyz = fscanf(file, "T-Shirt size XL cost: %d\n", &(ts_names.sizes_cost[3]));
		xyz = fscanf(file, "T-Shirt print empty cost: %d\n", &(ts_names.prints_cost[0]));
		xyz = fscanf(file, "T-Shirt print cars cost: %d\n", &(ts_names.prints_cost[1]));
		xyz = fscanf(file, "T-Shirt print guns cost: %d\n", &(ts_names.prints_cost[2]));
		xyz = fscanf(file, "T-Shirt print roses cost: %d\n", &(ts_names.prints_cost[3]));
		xyz = fscanf(file, "T-Shirt print heart cost: %d\n", &(ts_names.prints_cost[4]));
	}
}

void init()
{
	get_costs();
	//ts_names.ts_cost = 10;
	strcpy(ts_names.males[0], "male  ");
	strcpy(ts_names.males[1],"female");
	//ts_names.males_cost[0] = 2;
	//ts_names.males_cost[1] = 3;
	strcpy(ts_names.colors[0] , "red  ");
	strcpy(ts_names.colors[1] , "white");
	strcpy(ts_names.colors[2] , "black");
	//ts_names.colors_cost[0] = 5;
	//ts_names.colors_cost[1] = 3;
	//ts_names.colors_cost[2] = 3;
	strcpy(ts_names.sizes[0] , "S ");
	strcpy(ts_names.sizes[1] , "M ");
	strcpy(ts_names.sizes[2] , "L ");
	strcpy(ts_names.sizes[3] , "XL");
	//ts_names.sizes_cost[0] = 10;
	//ts_names.sizes_cost[1] = 12;
	//ts_names.sizes_cost[2] = 14;
	//ts_names.sizes_cost[3] = 16;
	strcpy(ts_names.prints[0] , "empty");
	strcpy(ts_names.prints_texts[0], "              ");
	strcpy(ts_names.prints[1] , "cars ");
	strcpy(ts_names.prints_texts[1], "You drive it! ");
	strcpy(ts_names.prints[2] , "guns ");
	strcpy(ts_names.prints_texts[2], "Russian roulet");
	strcpy(ts_names.prints[3] , "roses");
	strcpy(ts_names.prints_texts[3], "Flowers!      ");
	strcpy(ts_names.prints[4] , "heart");
	strcpy(ts_names.prints_texts[4], "Believe in you");
	//ts_names.prints_cost[0] = 0;
	//ts_names.prints_cost[1] = 10;
	//ts_names.prints_cost[2] = 15;
	//ts_names.prints_cost[3] = 8;
	//ts_names.prints_cost[4] = 13;
}

void setPos(int row) {
	printf("\033[%d;%dH", row, 1);
}

void clearRowScreen(int row)
{
	printf("\033[%d;%dH", row, 1);
	printf("\033[J", row);
}

int read_num()
{
	char c[3] = { NULL, NULL, '\0' };
	scanf("%2s%*[^\n]%*c", &c);
	if (c[1] == NULL) {
		if (c[0] == '0')
		{
			return 0;
		}
		else if (c[0] == '1')
		{
			return 1;
		}
		else if (c[0] == '2')
		{
			return 2;
		}
		else if (c[0] == '3')
		{
			return 3;
		}
		else if (c[0] == '4')
		{
			return 4;
		}
		else if (c[0] == '5')
		{
			return 5;
		}
		else if (c[0] == '6')
		{
			return 6;
		}
		else if (c[0] == '7')
		{
			return 7;
		}
		else if (c[0] == '8')
		{
			return 8;
		}
		else if (c[0] == '9')
		{
			return 9;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return -1;
	}
}