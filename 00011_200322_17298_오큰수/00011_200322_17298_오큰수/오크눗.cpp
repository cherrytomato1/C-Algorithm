/*

크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

17298 오큰수 1초
*/
#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	vector<int> V,resV;
	stack<int> stk;

	cin >> N;
	V.resize(N);

	for (int i=0; i < N; i++)
		cin >> V[i];

	resV.resize(N,-1);

	for (int i = N-1; i >= 0; i--)
	{
		while (!stk.empty() && stk.top() <= V[i])
			stk.pop();

		if (stk.empty())
			resV[i] = -1;
		else
			resV[i] = stk.top();

		stk.push(V[i]);
		
	}

	for (int i = 0; i < N; i++)
		cout << resV[i] << " ";
		
}

/*
2중반복시 O(N^2)이므로 초과

오른쪽 수 부터 검사한다 스택의 탑부터 비교하여 현재 인덱스보다 탑이 크면 탑이 오큰수가 된다

스택이 empty가 되면 그 인덱스는 자기 자신이 오큰수가 된다 (-1)

이후 검사가 끝난 수들은 스택에 쌓는다.

O(N)



*/