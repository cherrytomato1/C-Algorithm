#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> M;

	cin >> N;

	vector<int> s(N+1);

	for (int i = 2; i <= N; i++)
		s[i] = i;

	for (int i = 2; i <= N; i++)
	{
		if (s[i] == 0)
			continue;
		for (int j = i * 2; j <= N; j += i)
		{
			if (j > N)
				break;
			s[j] = 0;
		}
	}

	for (int i = M; i<=N; i++)
		if(s[i]!=0)
			cout << s[i] << " ";

}

//소수 구하기 - 에라토스테네스의 체