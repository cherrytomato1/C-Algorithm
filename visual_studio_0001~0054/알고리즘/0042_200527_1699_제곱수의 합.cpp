/*
	제곱수의 하ㅣㅂ
	1. 제곱수의 합으로 나타내었을 때 가장 큰 제곱수가 더해진다고 가장 적은 횟수만큼 더하는게 아닐 수 있다
	 ex) 12 = 3^2 +1^2+1^2+^2 = 4^2 + 4^2 + 4^2
	2. 따라서 해당 값을 이룰 수 있는 제곱수들을 구하고 그 제곱수를 연산하게될 때 가장 적은 계산 수를 갖는 수를 찾는다
	 2.1 d[n] = min( d[n-1^2], d[n-2^2] ,d[n-3^2] .... d[n-i^2](단 n>= i^2))
	 2.2 ex) 12 = min(12-1, 12-4, 12-9) +1
	3. 해당 수보다 작은 제곱수부터 1까지 반복하여 가장 작은 연산항을 갖는 제곱수를 찾아 저장한다.이미 저장되어 있으면 그 값을 불러쓴다
	4. 추가설명 d[12] = 3 = d[12-4]+1 = d[8]+1
				d[8] = 2 = d[8-4] +1 = d[4] +1
				d[4] = 1 = d[4-4] +1 =d[0] +1
				d[0] = 0
*/


#include<iostream>
#include<algorithm>
#include<cmath>

#define MAX 1000000

using namespace std;


int d[100000] ;

int f(int n)
{
	int temp=1234123;

	if (n <= 3)
		return n;
	if (d[n] != 0)
		return d[n];

	for (int i = 1; i <= sqrt(n); i++)
		temp = min(temp, f(n-(i*i)));
	
	return d[n]=temp+1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, i,cnt=0;

	cin >> N;

	cout << f(N);
}