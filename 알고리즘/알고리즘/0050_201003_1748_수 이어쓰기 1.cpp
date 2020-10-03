/*
	1740 수 이어 쓰기
 
	1부터 N까지의 수를 이어서 쓰면 다음과 같이 새로운 하나의 수를 얻을 수 있다.

	1234567891011121314151617181920212223...

	이렇게 만들어진 새로운 수는 몇 자리 수일까? 이 수의 자릿수를 구하는 프로그램을 작성하시오.


	시간 제한 1초 1<N<1,000,000,000

	1~9			1		9			9
	10~99		2		90			180
	100~999		3		900			2700
	1000~9999	4		9000		36000
	

	1. 1~9 1의자리는 9개, 10~99는 90개, 100~999는 900개...
	2. 입력값의 자릿수를 구하여 3자리 수면 99를 미리 더한다.
	3. N의 자릿수에 맞게 N의 값에서 이하 자릿수를 뺀 값을 곱하여 ans에 더한다
*/

#include<iostream>

#define MAX 1000000000

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,length=0, ans=0, val= 1;

	cin >> N;

	for (int i = 1; N / i > 0; i *= 10)
		length++;

	for (int i = 1; i < length; i++, val *= 10)
		ans += (val*9*i);

	ans += length * (N - (val - 1));

	cout << ans;
}