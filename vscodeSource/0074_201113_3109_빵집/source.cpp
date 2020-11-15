/*


    처음에 틀린 이유 : 모든 row와 row +1을 비교해가면서 최소 접점의 개수를 구하려고 했음
                    -> 따라서 매 row를 비교하기 위헤 재할당을 반복하여 메모리 초과 혹은 시간 초과 에러가 발생했음

    풀이 : 

    row = 0 부터 시작하여 가능한 경로의 수를 구함.
    이동시킬 때 이미 지나간 자리를 표시한다. 
    -> 가능한 경로일 경우 이미 그 경로를 지나가면서 사용하여 다시 사용할 수 없음
    -> 불가능한 경로일 경우 그 자리를 다시 지나가도 가능한 경로가 없음

    -> 오른쪽 위, 오른쪽, 오른쪽 아래 순으로 시행하여 가능한 위로 이동할 수 있는 경로를 찾는다.
    col = C-1 까지 이동할 수 있으면 true 반환, 모든 row에서 반복하여 true의 개수를 출력한다. 



*/






#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> map;

int R,C;

void getMap()
{
    string temp;
    for(int row = 0 ; row < R ; row++)
    {
        cin >> temp; 
        map.push_back(temp);
    }
}

int solve(int row, int col)
{
    map[row][col] = '-';                            //이미 이동한 경로 표시

    if(col == C-1)                                  //도착하면 true 반환
        return true;

    if(row != 0 && map[row - 1][col + 1] == '.')    //다음 좌표로 이동하고 그 좌표애서 true 반환시 true 반환, 최종 도착지에서 true를 받아야 true를 받을 수 있음
        if(solve(row - 1, col + 1))
            return true;

    if(map[row][col + 1] == '.')
        if(solve(row, col + 1))
            return true;

    if(row != R-1 && map[row + 1][col + 1] == '.')
        if(solve(row + 1, col + 1))
            return true;

    return false;                                    //오른쪽 위, 오른쪽, 오른쪽 아래까지 모두 가볼 수 있는 경로를 지났으나, true인 경우의 수가 없으면 false 반환
    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int answer = 0;

    cin >> R;
    cin >> C;

    getMap();

    for(int row = 0 ; row < R ; row ++ )
        answer += solve(row, 0);
    cout << answer ;


}

