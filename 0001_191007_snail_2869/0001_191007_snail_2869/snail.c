/*
문제 2869 . 달팽이는 올라가고 싶다

땅 위에 달팽이가 있다. 이 달팽이는 높이가 V미터인 나무 막대를 올라갈 것이다.

달팽이는 낮에 A미터 올라갈 수 있다. 하지만, 밤에 잠을 자는 동안 B미터 미끄러진다. 또, 정상에 올라간 후에는 미끄러지지 않는다.

달팽이가 나무 막대를 모두 올라가려면, 며칠이 걸리는지 구하는 프로그램을 작성하시오.
*/
#include<stdio.h>


/* 오답 1 . for 루프 사용시 큰 입력 시 계산 제한 시간 촟과
int main()
{
	unsigned int a, b, v,pv=0, day=1;

	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &v);

	for (; pv < v; day++,pv -= b)
		if ((pv+=a) >= v)
			break;

	printf("%d", day);
	return 0;
}*/

int main()
{
	unsigned int a, b, v, pv = 0, day = 1;
	float tmp_day = 0;

	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &v);
	
	tmp_day = (float)(v-b) / (a - b);
	
		
	
	//day = (v / a) - (v / b + 1);

	printf("%f",tmp_day);
	return 0;
}