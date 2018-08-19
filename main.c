#include "main.h"
#include <time.h>



int main()
{
	int Year;
	int Mon;
	int Day;
	int YMD;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	printf("now: %d-%d-%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

	Year = (tm.tm_year - 100) * 10000;
	Mon = (tm.tm_mon + 1) * 100;
	Day = tm.tm_mday;
	YMD = Year + Mon + Day;
	
	
	

	int select = 0;
	int tradDate = 0;
	int stockNum = 0;
	int amount = 0;
	int AllAmount = 0;
	int AllBuyPrice = 0;
	int AllEvaluatedPrice = 0;
	int EvaluatedPrice = 0;
	int searchForDate=0;
	int stockPrice=0;
	int i = 0;

	while (1)
	{


		if (select==0) 
		{
			FirstScreen();
			scanf("%d", &select);
			if (select == 5) break;
			system("cls");
			}
	
		if(select==1)
		{
			InputBuyInform(&tradDate, &stockNum, &amount);
			scanf("%d", &select);
			system("cls");
			}

		if (select == 2)
		{
			InputSellInform(&tradDate, &stockNum, &amount);
			scanf("%d", &select);
			system("cls");
		}

		if (select == 3)
		{

			AllAmount += amount;  // 매수수량
			printf("수량 : %d\n", AllAmount);

			FILE *f;		// 총매입금액
			f = fopen("005380.txt", "r");
			while (1)
			{
				fscanf(f, "%d%d", &searchForDate, &stockPrice);
				if (tradDate == searchForDate || tradDate == 0) break;
			}
			fclose(f);
			AllBuyPrice = AllBuyPrice + (amount * stockPrice);
			printf("총매입금액 : %d \n", AllBuyPrice);
			f = fopen("005380.txt", "r");			// 총평가금액
			while (1)
			{
				fscanf(f, "%d%d", &searchForDate, &stockPrice);
				if ( YMD == searchForDate) break;
			}
			fclose(f);
			AllEvaluatedPrice = AllEvaluatedPrice + (amount * stockPrice);
			printf("총평가금액 : %d\n", AllEvaluatedPrice);
			printf("평가손익 : %d\n", AllEvaluatedPrice - AllBuyPrice);
			printf("평가수익률: %d\n", AllEvaluatedPrice / AllBuyPrice * 100);
			amount = 0;

			printf("뒤로가기 --> 0\n");
			scanf("%d", &select);
			system("cls");
		}
	}
	
	
	return 0;
}

