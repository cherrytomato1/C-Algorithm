/*
	1. 골드바흐의 추측을 이루는 수의 개수가 파티션 
	1-1. N까지의 모든 소수를 구한다 - 에라토스테네스의 체
	1-2. 구해진 소수들을 벡터에 따로 저장한다
	2. 골드바흐의 추측에 해당하는 값을 구하기 위해서 각각의 N에서 소수 벡터를 통과시키면서 그 차가 소수인 경우의 수를 구한다


	시간복잡도 O(N)
*/





#include<iostream>
#include<vector>

#define MAX 1000000 +1			//입력값이 백만, 백만개의 값에 각각 해당하는 배열 인덱스를 할당하기 위해 배열 최댓값 백만1

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T,N,cnt;

	vector<int> num,s;


	cin >> T;										//테스트 케이스 수
	
	for (int i = 0; i < MAX; i++)					//배열의 인덱스와 맞는 값을 넣어줌		
		num.push_back(i);

	for (int i = 2; i < MAX; i++)					//소수 구하기 - 에라토스테네스의 체 
	{
		if (!num[i])								//1~MAX-1까지의 수를 검사하면서 검사하는 수의 MAX까지의 모든 배수를 0으로 만듬
			continue;								//0으로 변경된 수는 소수가 아니므로 검사하지 않음
		for (int j = i*2; j < MAX ; j+=i)
			num[j] = 0;
	}

	for (int i = 2; i < MAX; i++)					//2부터의 0이 아닌수 (소수) 를 소수 벡터에 저장
		if (num[i])
			s.push_back(num[i]);


	while (T--)
	{
		cin >> N;
		cnt = 0;
		//cout << s.size();
		for (int i = 0; i < s.size()&&s[i]<=N/2; i++)	//소수 벡터 인덱스 0~부터 N/2까지 검사( 중복 검사를 피하기 위해)
		{
			if (num[N - s[i]] != 0)						//N- 소수[i]를 했을 때 그 차가 소수일 경우 (num벡터에 값이 0이 아닐 경우) 두 소수의 합인것으로 판단
				cnt++;
		}
		cout <<cnt << "\n";
	}

}