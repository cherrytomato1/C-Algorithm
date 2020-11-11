/*


	로봇청소기

	1. 현재 위치를 청소한다.
	2. 현재 위치에서 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색을 진행한다.
		2-1. 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
		2-2. 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전하고 2번으로 돌아간다.
		2-3. 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
		2-4. 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.

		첫째 줄에 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 50)


*/

#include<iostream>
#include<algorithm>

#define MAX 50

#define Nth 0
#define Est 1
#define Sth 2
#define Wst 3

typedef struct _robot {
	int d;
	int x, y;
}robot;

using namespace std;

int map[MAX][MAX];
int cnt = 0,turnCnt=0;
robot rbt;
int n, m; // n = y, m = x

void setMap(int n, int m)
{
	int temp;
	for(int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> temp;
			map[j][i]= temp;
		}
}

void turnLeft()
{
	if (rbt.d == 0)
		rbt.d = 4;
	rbt.d--;
	turnCnt++;
}

int chkFwrd(int tempX,int tempY,int dir)
{
	switch (dir)
	{
	case 0:
		tempY--;
		break;
	case 1:
		tempX++;
		break;
	case 2 :
		tempY++;
		break;
	case 3 :
		tempX--;
		break;
	}
	return map[tempX][tempY];
}

void mvFwrd()
{
	switch (rbt.d)
	{
	case 0:
		rbt.y--;
		break;
	case 1:
		rbt.x++;
		break;
	case 2:
		rbt.y++;
		break;
	case 3:
		rbt.x--;
		break;
	}
}

void move()
{
	if (map[rbt.x][rbt.y] == 0)
	{
		map[rbt.x][rbt.y] = 2;
		cnt++;

		return;
	}
	turnLeft();
	while (chkFwrd(rbt.x, rbt.y, rbt.d) != 0)
	{
		if (turnCnt == 4)
		{
			if (chkFwrd(rbt.x, rbt.y, (rbt.d + 2) % 4) == 1)
			{
				cout << cnt;
				exit(0);

			}
			else
			{
				rbt.d = (rbt.d + 2) % 4;
				mvFwrd();
				rbt.d = (rbt.d + 2) % 4;
				turnCnt = 0;
				return;
			}
		}
		turnLeft();
	}
	mvFwrd();
	turnCnt = 0;
	

}


int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	cin >> rbt.y;
	cin >> rbt.x;
	cin >> rbt.d;

	setMap(n, m);
	while (1)
		move();
	
	return 0;

}