/*

	지도를 옮겨가면서 예외처리 하고 지도의 상단을 출력해야함

	-->>링크드 리스트로 주사위 면 연결


*/

#include<iostream>
#include<vector>

#define MAX 20
#define kMAX 1000

using namespace std;

typedef struct dice {
	int val;
	dice* up;
	dice* right;
	dice* left;
	dice* down;
	dice* back;

}dice;

dice D[6];
int map[MAX][MAX];


void setDice()
{
	for (int i = 0; i < 6; i++)
		D[i].val = 0;

	D[0].up = &D[1];
	D[0].right = &D[2];
	D[0].left = &D[3];
	D[0].down = &D[4];
	D[0].back = &D[5];

	D[1].up = &D[5];
	D[1].right = &D[2];
	D[1].left = &D[3];
	D[1].down = &D[0];
	D[1].back = &D[4];
	
	D[2].up = &D[1];
	D[2].right = &D[2];
	D[2].left = &D[3];
	D[2].down = &D[4];
	D[2].back = &D[5];

	D[3].up = &D[1];
	D[3].right = &D[2];
	D[3].left = &D[3];
	D[3].down = &D[4];
	D[3].back = &D[5];

	D[4].up = &D[1];
	D[4].right = &D[2];
	D[4].left = &D[3];
	D[4].down = &D[4];
	D[4].back = &D[5];

	D[5].up = &D[1];
	D[5].right = &D[2];
	D[5].left = &D[3];
	D[5].down = &D[4];
	D[5].back = &D[5];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, x, y, K, order;

	cin >> N;
	cin >> M;
	cin >> x;
	cin >> y;
	cin >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];


	setDice();
	

	while (K--)
	{
		cin >> order;

	}

}


