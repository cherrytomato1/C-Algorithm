/*
		이분탐색 배우고 해보자ㅣ
*/


#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1000000
#define NUM 0
#define CNT 1
//#define nextIND 2

using namespace std;

//vector < vector<int> > V(MAX, vector<int>(3));
vector < vector<int> > V(MAX, vector<int>(2));
int res[2] ;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> V[i][NUM];

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = i; j < N; j++)
		{
			if (V[j][NUM] > V[i][NUM] && V[j][CNT]>V[i][CNT])
			{
				V[i][CNT] = V[j][CNT];
	//			V[i][nextIND] = j;
			}
		}

		V[i][CNT]++;

		if (res[CNT] < V[i][CNT])
		{
			res[CNT] = V[i][CNT];
	//		res[nextIND] = V[i][nextIND];
		}
		
	}

	cout << res[CNT];
	//vector< vector<int> >().swap(V);
	return 0;
}