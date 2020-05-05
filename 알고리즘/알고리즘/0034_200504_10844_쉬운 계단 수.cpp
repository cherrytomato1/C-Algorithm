

/*
	1. 계단수는 연속된 수로 이루어진 정수
	2. 계단수 길이 N, 계단수의 시작이 a이라고 했을 때 각 계단수는 다음과 같은 점화식을 갖는다
	d[N][a] = d[N-1][a-1] + d[N-1][a+1] (a이 1~8일때)

	d[N][a] = d[N-1][a+1] (a이 0일때)

	d[N][a] = d[N-1][a-1] (a이 9일때)

*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define mod 1000000000

using namespace std;

unsigned long long dp[100+1][10];

unsigned long long f(int N, int a)
{

	if (dp[N][a])							//이미 한번 구한 계단수 N,a
		return dp[N][a];

	if (a == 0)								//0 및 9는 1 및 8로만 계단수를 이룰 수 있다
		return dp[N][a] = f(N - 1,a + 1);
	if (a == 9)
		return dp[N][a] = f(N - 1,a - 1);

	return dp[N][a] = (f(N - 1,a - 1) + f(N - 1,a + 1)) % mod;				//d[N][a] = d[N-1][a-1] + d[N-1][a+1] 구현
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 10; i++)				// 0~9의 모든 N==1(1자리)일 때 계단수는 단 하나이므로 초기화
		dp[1][i] = 1;
	int N,sum=0;

	cin >> N;

	for (int i = 1; i < 10; i++)				//0으로 시작하는 수는 없으므로 1부터 시작
	{
		sum += f(N, i);
		sum %= mod;
	}

	cout << sum;
}
