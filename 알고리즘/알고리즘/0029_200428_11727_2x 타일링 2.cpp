/*

1. 2xn 타일링의 점화식에서 한가지 경우의 수가 추가됨
 1-1. ㅣ가 추가될 경우 - > a[n] = a[n-1]
 1-2   =가 추가될 경우 - > a[n] = a[n-2]
 1-3  ㅁ가 추가될 경우 - > a[n] = a[n-2]		:: 새로 추가될 점화식

2. 2x2 타일에서의 경우의 수도 1가지 추가됨 a[2] = 3


*/


#include<iostream>

using namespace std;

int a[1001];

int makeBox2(int N)
{
	if (N == 1)		return 1;					//1 및 2의 경우의 수는 바로 리턴
	if (N == 2)		return 3;					
	
	if (a[N] != 0)	return a[N];				//이미 한 번 구했던 값인 경우 그 값을 리턴

	return a[N] = (makeBox2(N - 1) + makeBox2(N - 2) * 2)%10007;		//점화식에 따른 값 재귀함수 사용 
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	cout << makeBox2(N);
}