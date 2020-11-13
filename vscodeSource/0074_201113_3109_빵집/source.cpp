/*

    각 row의 접점에서 연결될 수 있는 가장 작은 값이 최대 설치 개수

    접점의 기준 -> 위, 아래 대각선, 바로 옆
    접점이 가장 큰 경우의 접점의 개수
    
    row = 10000
    col = 500

    0 0 
    0 1 
    1 0 
    0 1 
    1 0 
    0 0 
    접점 3

    3개의 반복??

    2개의 col씩 검사?

    재귀함수???

3 4
..x.
..x.
.x..

*/

#include<iostream>
#include<algorithm>
#include<vector>

#define rMAX 10000
#define cMAX 500

#define BLANK 0
#define WALL 1
#define CHECKED 2
#define NOTCHK -1

using namespace std;

vector< vector <int> > map;
int R,C;


void getMap()
{
    char in; 
    for(int row = 0 ; row < R ; row++)
    {
        vector<int> colmap;
        for(int col = 0; col < C ; col++)
        {
            cin >> in; 
            if(in == 'x')
                colmap.push_back(WALL);
            else if(in == '.')
                colmap.push_back(BLANK);
        }
        //for(int i = 0 ; i < C ; i ++)
        //    cout << colmap[i] << " ";
        map.push_back(colmap);
    }
    /*
    for(int row = 0 ; row < R ; row++)
    {
        for(int col = 0 ; col < C ; col++)
            cout << map[row][col] << " ";
        cout << "\n";
    }
    */
}

int checkContact(bool rowmap1[rMAX], bool rowmap2[rMAX], int idx, int preidx1, int preidx2)
{
    int contact = 0;

    if(idx == R)
        return 0;

    //cout << idx << "\n";

    if(preidx1 != NOTCHK)
        rowmap1[preidx1] = WALL;
    if(preidx2 != NOTCHK)
        rowmap2[preidx2] = WALL;

    if(idx == 0)
    {
        if(rowmap1[idx] == BLANK && rowmap2[idx] == BLANK)
        {
            contact = max(contact, checkContact(rowmap1, rowmap2, idx + 1, idx, idx) + 1);
            //cout << contact <<" = contact , idx = " << idx << ",  preidx = " << preidx1 << ", " << preidx2 <<"\n";
        }

        if(rowmap1[idx] == BLANK && rowmap2[idx + 1] == BLANK)
        {
            contact = max(contact, checkContact(rowmap1, rowmap2, idx + 1, idx, idx + 1) + 1);
            //cout << contact <<" = contact , idx = " << idx << ",  preidx = " << preidx1 << ", " << preidx2 <<"\n";
        }

        else return max(contact, checkContact(rowmap1, rowmap2, idx + 1, NOTCHK, NOTCHK)) ;

        return contact;
    }

    else if(idx == R - 1)
    {
        if(rowmap1[idx] == BLANK && rowmap2[idx - 1] == BLANK)
        {
            //cout << contact <<" = contact , idx = " << idx << ", " << idx - 1  <<"\n";
            contact = max(contact, checkContact(rowmap1, rowmap2, idx + 1, idx, idx - 1) + 1);
        }
        if(rowmap1[idx] == BLANK && rowmap2[idx] == BLANK)
        {
            //cout << contact <<" = contact , idx = " << idx << ", " << idx  <<"\n";
            contact = max(contact, checkContact(rowmap1, rowmap2, idx + 1, idx, idx) + 1);
            
        }
        else return max(contact, checkContact(rowmap1, rowmap2, idx + 1, NOTCHK, NOTCHK)) ;

        return contact;
    }
    
    else 
    {
        if(rowmap1[idx] == BLANK && rowmap2[idx - 1] == BLANK)
        {
            contact = max(contact, checkContact(rowmap1, rowmap2, idx + 1, idx, idx - 1) + 1);
            //cout << contact <<" = contact , idx = " << idx << ",  preidx = " << preidx1 << ", " << preidx2 <<"\n";
        }

        if(rowmap1[idx] == BLANK && rowmap2[idx] == BLANK)
        {
            contact = max(contact, checkContact(rowmap1, rowmap2, idx + 1, idx, idx) + 1);
            //cout << contact <<" = contact , idx = " << idx << ",  preidx = " << preidx1 << ", " << preidx2 <<"\n";
        }

        if(rowmap1[idx] == BLANK && rowmap2[idx + 1] == BLANK)
        {
            contact = max(contact, checkContact(rowmap1, rowmap2, idx + 1, idx, idx + 1) + 1);
            //cout << contact <<" = contact , idx = " << idx << ",  preidx = " << preidx1 << ", " << preidx2 <<"\n";
        }

        else return max(contact, checkContact(rowmap1, rowmap2, idx + 1, NOTCHK, NOTCHK)) ;

        return contact;
    }
    

}

    
int solution()
{
    int answer = C;
    //int answer = 0;
    bool rowmap1[rMAX];
    bool rowmap2[rMAX];

    for(int col = 1 ; col < C-2  ; col++)
    {
        for(int row = 0 ; row < R ; row++)
            rowmap1[row] = map[row][col];

        for(int row = 0 ; row < R ; row++)
            rowmap2[row] = map[row][col+1];

        //cout << rowmap1.size() << " is size \n";
        answer = min(answer, checkContact(rowmap1,rowmap2, 0, NOTCHK, NOTCHK));
        //cout << col << " line checked \n";
    }

    return answer;

}


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R ;
    cin >> C ;

    getMap();
    cout << solution();

}