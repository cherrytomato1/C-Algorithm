#include <iostream>
#include <string>
#include <vector>

#define rMAX 10000
#define cMAX 500

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
    bool answer = false;

    map[row][col] = '-';

    if(col == C-1)
        return true;

    if(row != 0 && map[row - 1][col + 1] == '.')
        if(solve(row - 1, col + 1))
            return true;

    if(map[row][col + 1] == '.')
        if(solve(row, col + 1))
            return true;

    if(row != R-1 && map[row + 1][col + 1] == '.')
        if(solve(row + 1, col + 1))
            return true;

    return false;
    
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

