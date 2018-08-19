#include "main.h"


int totalPurchase()
{
	int c;
	int searchForDate;
	int stockPrice;

	FILE *f;

	f = fopen("005380.txt", "r");

	fscanf(f, "%d%d", &searchForDate, &stockPrice);

	fclose(f);

	printf("%d%d\n", searchForDate, stockPrice);

	return c;
}
