#include "main.h"


void	InputBuyInform(int tradDate, int stockNum, int InPutAmount)
{

	printf("매매날짜 : \n");
	scanf("%d", tradDate);
	getwchar();
	printf("종목번호 : \n");
	scanf("%d", stockNum);
	getwchar();
	printf("매매수량 : \n");
	scanf("%d", InPutAmount);
	getwchar();
	printf("뒤로가기 --> 0\n");

}