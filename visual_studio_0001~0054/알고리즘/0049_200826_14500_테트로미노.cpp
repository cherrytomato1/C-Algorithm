/*

	1. 주어진 가로세로 최대값 max 500
	2. ㅗ 모양을 제외한 모든 테트로미노는 4방향으로 한칸 씩 전진할 시 모양을 완성할 수 있음
	 2-1. 전진 할 때마다 그 좌표에 있는 값을 더함
	  2-1-1. 이전에 접근했던 블록에 다시 접근하지 않게 예외처리
	  2-1-2. 좌표가 0과 N,M을 초과하지 않도록 예외처리
	  2-1-3. 계산한 블록의 수가 4개가 될 때까지 반복(재귀연산)
	 2-2. ㅗ 모양은 예외처리하여 계산
	  2-2-1. 계산하는 블록의 좌표로 부터 위 아래 양 옆의 값을 모두 더함 ( + 모양으로 더함)
	  2-2-2. + 연산된 값에서 위 아래 양 옆 한 개씩 값 뺀 값을 비교 연산하여 가장 큰 값을 갖는 블록으로 계산
	  2-2-3. 가장자리에 붙어 있는 좌표는 한 개씩 뺄 필요 없으므로 그대로 계산

*/




#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>

#define MAX 500


using namespace std;

int map[MAX][MAX];
int N,M,ans=0;						//n,m 결과값 초기화


void f2(int col, int row)				// ㅗ ㅓ ㅜ ㅏ 모양 예외처리용 함수
{
	int val=0,f2ans=0;
	val += map[col][row];				//현재 계산 좌표의 값을 더함
	if (col != 0)						// 최대값 및 최소값을 초과하지 않는 선에서 +모양으로 연산
		val += map[col - 1][row];
	if (col < N-1)
		val += map[col + 1][row];
	if (row != 0)
		val += map[col][row - 1];
	if (row < M - 1)
		val += map[col][row + 1];


	if (col != 0)						//각각 하나의 좌표를 빼 되, 가장자리에 걸려있어 연산이 불가능한 값을 갖는 좌표는 계산 하지 않음
		f2ans = max(val - map[col - 1][row], f2ans);
	else
		f2ans = val;

	if (col <N-1)
		f2ans = max(val - map[col + 1][row], f2ans);
	else
		f2ans = val;

	if (row != 0)
		f2ans = max(val - map[col][row - 1], f2ans);
	else
		f2ans = val;

	if (row < M - 1)
		f2ans = max(val - map[col][row + 1], f2ans);
	else
		f2ans = val;
	
	ans = max(f2ans, ans);				//최대값 비교

}
void f(int col, int row, int pcol, int prow, int cnt,int val)	//현재 검사 좌표, 방금 전에 검사했던 좌표, 반복한 회수, 더해진 값
{
	val += map[col][row];

	if (cnt == 3)												//4개의 블록 연산이 모두 끝났을 경우
	{
		ans = max(val, ans);
		return ;
	}
	if (cnt == 0)												//한 번도 연산을 안했을 경우 ㅗ ㅏ ㅜ ㅓ 예외처리 연산 먼저함
		f2(col, row);
	if (col != 0)												//최대 좌표를 벗어나지 않는 선, 이전에 들렸던 좌표가 아닌 경우에 한하여 상하좌우 블록 연산
		if (col - 1 != pcol)
			f(col-1, row, col, row, cnt + 1, val);
	if (col < N - 1)
		if (col + 1 != pcol)
			f(col+1, row, col, row, cnt + 1, val);
	if (row != 0)
		if (row - 1 != prow)
			f(col, row-1, col, row, cnt + 1, val);
	if (row < M - 1)
		if (row + 1 != prow)
			f(col, row+1, col, row, cnt + 1, val);

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	srand(time(NULL));

	
	cin >> N;				//col
	cin >> M;				//row

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
			//map[i][j] = rand() % 2;

	/*
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << map[i][j]<< " ";
		cout << "\n";
	}
	*/

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			f(i, j, -1, -1, 0, 0);					//모든 좌표의 연산 진행

	cout << ans;
}