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
	int InPutAmount = 0;
	int OutPutAmount = 0;
	int AmountStorage = 0;
	int AllAmount = 0;
	int AllBuyPrice = 0;
	int AllEvaluatedPrice = 0;
	int EvaluatedPrice = 0;
	int ValuationProfitLoss = 0;
	double EvaluationRate = 0;
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
	
		if(select==1) // 매수입력
		{
			InputBuyInform(&tradDate, &stockNum, &InPutAmount);
			scanf("%d", &select);
			system("cls");
			}

		if (select == 2) //매도입력
		{
			InputSellInform(&tradDate, &stockNum, &OutPutAmount);
			scanf("%d", &select);
			system("cls");
		}

		if (select == 3)
		{
						FILE *f;		// 총매입금액
						f = fopen("005380.txt", "r");
						while (1)
						{
							fscanf(f, "%d%d", &searchForDate, &stockPrice);
							if (tradDate == searchForDate || tradDate == 0) break;
						}

						AllAmount = AllAmount + InPutAmount - OutPutAmount;  // 매수수량

						AllBuyPrice = ( InPutAmount > OutPutAmount )? AllBuyPrice + (InPutAmount * stockPrice) : (AllBuyPrice / AllAmount) * ( AllAmount - OutPutAmount);
						AmountStorage = InPutAmount;

																				// 총평가금액
						while (1)
						{
							fscanf(f, "%d%d", &searchForDate, &stockPrice);
							if ( YMD == searchForDate) break;
						}
						
						ValuationProfitLoss = (stockPrice - (AllBuyPrice / AllAmount)) * AllAmount; //평가손익 = (최근주가 - 평균매입금액  ) * 보유수량

						AllEvaluatedPrice = AllEvaluatedPrice + (InPutAmount * stockPrice);

						EvaluationRate = ((double)AllEvaluatedPrice / (double)AllBuyPrice) *100 -100;

						printf("수량 : %d\n", AllAmount);

						printf("총매입금액 : %d \n", AllBuyPrice);

						printf("총평가금액 : %d\n", AllEvaluatedPrice);

						printf("평가손익 : %d\n", ValuationProfitLoss);

						printf("평가수익률: %.2lf \n", EvaluationRate);
			
						InPutAmount = 0;
						OutPutAmount = 0;
						fclose(f);
						printf("뒤로가기 --> 0\n");
						scanf("%d", &select);
						system("cls");
		}

		if (select == 4)
		{
			FILE *F;
				F = fopen("memo.txt", "w");
				if ()
				{

				}

		
		
		
		
		
		}





		}




	}
	
	
	return 0;
}

