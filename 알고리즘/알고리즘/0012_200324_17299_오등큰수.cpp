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

	cin >> N;

	stack<int> stk;

	vector<int> V(N), nNum(1000001,0), res(N);

	for (int i = 0; i < N; i++)
		cin >> V[i];

	for (int i = 0; i < N; i++)
		nNum[V[i]]++;

	for (int i = N - 1; i >= 0; i--)
	{
		while (!stk.empty() && nNum[stk.top()] <= nNum[V[i]])
			stk.pop();

		if (stk.empty())
			res[i] = -1;
		else
			res[i] = stk.top();
		stk.push(V[i]);
	}

	for (int i = 0; i < N; i++)
		cout << res[i] << " ";
}