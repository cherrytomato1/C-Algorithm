/*
	0. 가장 긴 증가하는 부분수열에서 수열의 길이를 수열의 합으로 바꾸면 된다


	1.가장 큰 증가하는 부분수열은 증가하는 부분수열의 집합에서 합이 가장 큰 부분수열의 합을 출력한다
	2.마지막 인덱스부터 증가하는 부분수열임을 검사하여 증가하는 부분수열일 경우 증가하는 수열 중 합이 가장 큰 값을 현재 검사하는 수에 저장한다.
*/



#include<iostream>
#include<algorithm>
#include<vector>


#define NUM 0
#define SUM 1

using namespace std;

int d[1000][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, res = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> d[i][NUM];

	for (int i = N - 1; i >= 0; i--)
	{
		if (i == N - 1)
			d[i][SUM] = d[i][NUM];
		else
		{
			for (int j = i; j < N; j++)
				if (d[j][NUM] > d[i][NUM])
					d[i][SUM] = max(d[j][SUM], d[i][SUM]);

			d[i][SUM] += d[i][NUM];
		}
		res = max(res, d[i][SUM]);
	}

	cout << res;
}