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
	
		if(select==1) // �ż��Է�
		{
			InputBuyInform(&tradDate, &stockNum, &InPutAmount);
			scanf("%d", &select);
			system("cls");
			}

		if (select == 2) //�ŵ��Է�
		{
			InputSellInform(&tradDate, &stockNum, &OutPutAmount);
			scanf("%d", &select);
			system("cls");
		}

		if (select == 3)
		{
						FILE *f;		// �Ѹ��Աݾ�
						f = fopen("005380.txt", "r");
						while (1)
						{
							fscanf(f, "%d%d", &searchForDate, &stockPrice);
							if (tradDate == searchForDate || tradDate == 0) break;
						}

						AllAmount = AllAmount + InPutAmount - OutPutAmount;  // �ż�����

						AllBuyPrice = ( InPutAmount > OutPutAmount )? AllBuyPrice + (InPutAmount * stockPrice) : (AllBuyPrice / AllAmount) * ( AllAmount - OutPutAmount);
						AmountStorage = InPutAmount;

																				// ���򰡱ݾ�
						while (1)
						{
							fscanf(f, "%d%d", &searchForDate, &stockPrice);
							if ( YMD == searchForDate) break;
						}
						
						ValuationProfitLoss = (stockPrice - (AllBuyPrice / AllAmount)) * AllAmount; //�򰡼��� = (�ֱ��ְ� - ��ո��Աݾ�  ) * ��������

						AllEvaluatedPrice = AllEvaluatedPrice + (InPutAmount * stockPrice);

						EvaluationRate = ((double)AllEvaluatedPrice / (double)AllBuyPrice) *100 -100;

						printf("���� : %d\n", AllAmount);

						printf("�Ѹ��Աݾ� : %d \n", AllBuyPrice);

						printf("���򰡱ݾ� : %d\n", AllEvaluatedPrice);

						printf("�򰡼��� : %d\n", ValuationProfitLoss);

						printf("�򰡼��ͷ�: %.2lf \n", EvaluationRate);
			
						InPutAmount = 0;
						OutPutAmount = 0;
						fclose(f);
						printf("�ڷΰ��� --> 0\n");
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

