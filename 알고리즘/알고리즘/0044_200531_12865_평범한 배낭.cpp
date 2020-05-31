#include<iostream>
#include<vector>
#include<algorithm>
/*

	0/1 냅색 알고리즘


*/


#define maxK 100000
#define maxN 100
#define val 0
#define maxVal 1

using namespace std;

int d[maxN + 1][2];
int K;

int f(int w)
{
	if (w == 1)
		return d[w][maxVal] = d[w][val];
	if (d[w][maxVal] != 0)
		return d[w][maxVal];

	for (int i = w; i <= 0; i--)
	{
		val[i] = max(f(i) + f(w - i), val[i]);
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,W,V;

	cin >> N;
	cin >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> W;
		cin >> V;
		d[W] = max(d[W], V);
	}


}


