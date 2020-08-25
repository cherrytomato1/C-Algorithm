/*
	수들이 다이아몬드 형태로 배치되어 있을 때 각 가로줄에서 한 개씩의 루트를 따라서 맨 위칸에서 맨 아래칸으로 내려오는 경로를 찾고 싶습니다.

	다음 칸으로 이동할 때는 인접한 수들로만 이동할 수 있습니다. 예를 들어 아래의 그림에서 2번째 줄의 4는 다음 줄의 7또는 9로 이동해야만 합니다.

	경로에 포함된 숫자의 합이 가장 큰 경우의 값을 출력하는 프로그램을 작성하십시오.

	3
	4 1
	7 9 2
	2 7 9 6
	1 9 5
	7 3
	9

	가운데 줄까지 내려가는데는 d[c][a] -> d[c+1][a], d[c+1][a+1]가 있고
	가운데 줄부터는 -1, 0 이 있다. row의 인덱스가 0미만, row의 최대 개수를 초과하지 않게 예외처리를한다
	마지막 줄까지 합연산을 한 후 지금까지 나왔던 값과 최대값을 비교하여 답을 구한다.


*/


#include<iostream>
#include<vector>
#include<algorithm>

#define rMAX 100
#define cMAX 100*2-1

using namespace std;

int d[cMAX][rMAX];
int N,ans=0;

void f(int col, int row, int val)					//연산을 위한 재귀함수, col = 라인 수, row = 라인의 인덱스, val 연산을 지속하면서 얻어낸 합
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

	for (int i = 0; i < N; i++)					//삼각형 값 입력
		for (int j = 0; j <= i; j++)
			cin >> d[i][j];

	for (int i = N; i < N * 2 - 1; i++)			//역삼각형 값 입력
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