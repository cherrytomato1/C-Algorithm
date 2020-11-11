/*
	1. 점화식 -> d[N][0] = d[n-1][0] + d[n-1][1]
	             d[N][1] = d[n-1][0]

	2. 이를 정리하면		d[N] = d[N][0]+d[N][1] = d[N][1]+ d[N-1][0] + d[N-1][1]
								 = d[N][1]+ d[N-1][1] + d[N-2][1] ....
		초기값인 d[1],d[2]가 각각 1,1 이므로 이는 피보나치 수열이다.
		따라서 피보나치 수열 방식으로도 해결할 수 있다

*/



#include<iostream>

using namespace std;

unsigned long long d[90 + 1][2];

unsigned long long f(int N, int a)
{
	if (N == 1)
		return 1;

	if (d[N][a])		return d[N][a];

	if (a == 1)
		return d[N][a] = f(N - 1, 0);

	else
		return d[N][a] = f(N - 1, 0) + f(N - 1, 1);
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	cout << f(N, 1);
}