/*

1. 세가지 연산을 사용하여 가장 적은 연산으로 입력 N이 1이 될수 있는 방법의 연산횟수
2. 연산에 따른 점화식을 구한다
 2-1 . X-1 ....  a[N-1] + 1의 연산횟수
 2-2 . X/2 ....  a[N/2] + 1의 연산횟수
 2-3 . X/3 ....  a[N/3] + 1의 연산횟수



*/




#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[1000001];

int make1(int N)						//재귀함수
{
	int div2,div3, sub;					//-1, /2, /3 의 결과를 담는 각각의 변수
	if (N == 1|| N==0)					// 0 및 1은 연산횟수가 0 ( /2, /3 으로는 0에 도달할 수 없으므로 연산횟수에 영향 X)
		return 0;
	if (a[N] != 0)						//이미 한번 구했던 값이라면 추가 연산을 하지 않고 배열에 저장된 값을 리턴
		return a[N];

	div2 = N;							//비교를 위한 초기화
	div3 = N;

	if (N % 3 == 0)		div2 = make1(N / 3) + 1;			//3으로 나누어 떨어진다면 /3 연산
	if (N % 2 == 0)		div3 = make1(N / 2) + 1;			//2로 나누어 떨어진다면 /2 연산
	sub = make1(N-1)+1;										//-연산

	
	return a[N] = min(min(div2,div3),sub);					//세가지 연산을 사용했을 때 가장 연산횟수가 적은 방법의 연산횟수를 리턴하고 해당하는 숫자 배열인덱스에 횟수 저장	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	cout << make1(N);
}