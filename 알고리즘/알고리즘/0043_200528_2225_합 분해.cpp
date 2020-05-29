
/*
	합분해
	1. 합 N을 만들기 위해서 0~N의 정수를 사용해서 만듬
	2. K개의 항을 이용해서 정수를 만드는 경우는 K-1의 경우의 수에서 0~N의 값이 더해지는 경우의 수
	3. 따라서 d[n][k] = ∑(d[i][k-1) / 0 <=i <=n
*/

#include<iostream>
#include<algorithm>

#define mod 1000000000
#define MAX 200

using namespace std;

unsigned long long d[MAX + 1][MAX + 1];

int f(int n, int k)
{
	int temp = 0;
	if(k == 1)
		return 1;

	if (d[n][k])
		return d[n][k];

	for (int i = n; i >= 0; i--)
	{

		temp += f(i, k - 1);
		temp %= mod;
	}

	return d[n][k] = temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	        

	int N, K;

	cin >> N;
	cin >> K;

	cout << f(N, K);

}