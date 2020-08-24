#include<iostream>
#include<vector>
#include<algorithm>

#define rMAX 100
#define cMAX 100*2-1

using namespace std;

int d[cMAX][rMAX];
int N,ans=0;

void f(int col, int row, int val)
{
	val += d[col][row];

	

	if (col < N-1)
	{
		f(col + 1, row, val);
		f(col + 1, row + 1, val);
	}
	else if (col == (N - 1) * 2)
		ans = max(val, ans);

	else if ((row == (N - 1) * 2 - col) && row != 0)
		f(col + 1, row - 1, val);
	else if (row == 0)
		f(col + 1, row, val);
	else
	{
		f(col + 1, row, val);
		f(col + 1, row - 1, val);
	}
	
	return;

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> d[i][j];

	for (int i = N; i < N * 2 - 1; i++)
		for (int j = 0; j < N*2 - 1 -i; j++)
			cin >> d[i][j];

/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
			cout << d[i][j] << " ";
		cout << "\n";
	}

	for (int i = N; i <N*2 - 1; i++)
	{
		for (int j = 0; j < N*2 -1 - i; j++)
			cout <<  d[i][j] << " ";
		cout << "\n";
	}
*/

	f(0, 0, 0);

	cout << ans;


}