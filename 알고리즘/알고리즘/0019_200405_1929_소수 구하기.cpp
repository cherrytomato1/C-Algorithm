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

	int N, M;

	cin >> M;

	cin >> N;

	vector<int> s(N+1);

	for (int i = 2; i <= N; i++)
		s[i] = i;

	for (int i = 2; i <= sqrt(N); i++)
	{
		if (s[i] == 0)
			continue;
		for (int j = i * 2; j <= N; j += i)
			s[j] = 0;
	}

	for (int i = M; i<=N; i++)
		if(s[i]!=0)
			cout << s[i] << " ";

}

//소수 구하기 - 에라토스테네스의 체 https://hellowoori.tistory.com/36 시간복잡도 http://doocong.com/algorithm/sieve-of-eratosthenes/
//소수는 루트N의 경우까지 계산하면 된다 (소수가 아닌 수는 루트N이하의 약수를 갖게된다 3*3 = 9(제일 큰 경우))