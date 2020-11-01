/*
    뱀은 매 초 이동

    사과위치의 첫 번째는 행, 두 번째는 열

    맵은 n*n 정사각형

    L = 명령회수

    x 초 후 L 명령의 방향 전환

    행 col 열 row x y


    뱀의 몸을 큐로 표현하여 사과를 안 먹을 시 pop
*/

#include <iostream>
#include <queue>
#include <vector>

#define nMAX 100 + 1
#define oMAX 10000 + 1

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

#define APPLE 1
#define BODY 2

typedef struct
{
    int row;
    int col;
} snake;

using namespace std;

int N, L, K, row, col, T, sec = 0;

int dir = RIGHT;
char O;
char ord[oMAX] = {0};

int map[nMAX][nMAX] = {0};

queue<snake> snk;
snake temp;

void mv()
{
    while (1)
    {
        sec++;
        temp.row = snk.back().row;
        temp.col = snk.back().col;

        switch (dir)
        {
        case RIGHT:
            temp.row++;
            break;
        case LEFT:
            temp.row--;
            break;
        case UP:
            temp.col--;
            break;
        case DOWN:
            temp.col++;
        }

        snk.push(temp);

        if (snk.back().row < 1 || snk.back().row == N + 1 || snk.back().col < 1 || snk.back().col == N + 1 || map[snk.back().row][snk.back().col] == BODY)
            break;

        else if (map[snk.back().row][snk.back().col] != APPLE)
        {
            map[snk.front().row][snk.front().col] = 0;
            snk.pop();
        }

        map[snk.back().row][snk.back().col] = BODY;

        if (ord[sec] == 'L')
            dir = (dir + 4 - 1) % 4;
        else if (ord[sec] == 'D')
            dir = (dir + 1) % 4;
    }
    snk.pop(); //마지막에 pop 없음

    cout << sec << "\n";
    return;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> K;

    while (K--)
    {
        cin >> col;
        cin >> row;

        map[row][col] = APPLE;
    }

    cin >> L;
    for (int i = 0; i < L; i++)
    {
        cin >> T;
        cin >> O;

        ord[T] = O;
    }

    temp.row = 1;
    temp.col = 1;

    snk.push(temp);

    mv();
}