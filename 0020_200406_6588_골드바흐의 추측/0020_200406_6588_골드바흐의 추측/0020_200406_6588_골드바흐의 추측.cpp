#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N=1000000;
	int T=1,sum=0;



	vector<int> num(N + 1);
	vector<int> s;
	vector<int> res;

	for (int i = 2; i <= N; i++)
		num[i] = i;

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (num[i] == 0)
			continue;
		for (int j = i * 2; j <= N; j += i)
			num[j] = 0;
	}
	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] != 0)
			s.push_back(num[i]);
	}

	

	while (T)
	{
		cin >> T;
		sum = 0;
		for (int i = 0; s[i] <= T && sum !=T; i++)
		{
			for (int j = 0; s[j] <= T; j++)
			{
				sum = s[i] + s[j];
				if (sum > T)
					break;
				if (sum == T)
				{
					cout <<T<<" = "<< s[i] << " + " << s[j] << "\n";
					break;
				}
			}
		}
	}
}

//소수 구하기 - 에라토스테네스의 체 https://hellowoori.tistory.com/36 시간복잡도 http://doocong.com/algorithm/sieve-of-eratosthenes/
//소수는 루트N의 경우까지 계산하면 된다 (소수가 아닌 수는 루트N이하의 약수를 갖게된다 3*3 = 9(제일 큰 경우))