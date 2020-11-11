/*

2xn 크기의 직사각형에 1x2, 2x1 타일로 채우는 방법

n의 크기가 하나씩 증가할 때마다 늘어나는 채우는 방법의 수는

이전까지 모든 경우의 수에서 ㅣ 타일을 추가시키거나 = 타일을 추가시키는 방법

두가지 타일을 놓기 위해선 각각 n-1 , n-2 의 직사각형이 필요하며 n-1, n-2를 이루는데 필요한 경우의 수를 합해주면 구할 수 있다.

*/



#include<iostream>
#include<vector>

using namespace std;

int box[1000 + 1] = { 0 };

int makeBox(int num)
{
	if (num == 1)	return 1;										// 상자 길이가 1일 경우 1가지
	if (num == 2)	return 2;										// 상자 길이가 2일 경우 2가지
	if (box[num] != 0) return box[num];								// 이미 해당상자길이에 해당하는 경우의 수가 구해진 경우 바로 리턴함!!!!!

	return box[num]=(makeBox(num-1)+makeBox(num-2))%10007;			// 상자 길이가 구해지지 않은 경우 n-1 와 n-2의 경우의 수를 합해서 배열에 넣고 리턴시킴
}

int main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	cout << makeBox(N);
}