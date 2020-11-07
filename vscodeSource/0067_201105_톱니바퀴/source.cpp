/*

    RIGHT = 2
    LEFT  = 6



                    0
               7         1
            6                2
                5        3
                    4
*/


#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int T[4][8] = {0};

void roll(int idx, int preIdx, int ord) 
{
    int temp ;
    
    //현재 톱니바퀴와 왼쪽과 오른쪽의 톱니바퀴가 마주보는 극이 다르면서 비교하는 톱니들이 이미 영향을 준 톱니가 아닐경우
    //그 톱니바퀴도 돌리지만 영향을 준 현재의 톱니바퀴의 인덱스를 넘겨주어 다시 비교하지 않게함

    if(idx != 0 && T[idx][6] != T[idx - 1][2] && preIdx != idx - 1)       
        roll(idx - 1, idx, ord * -1);
    if(idx != 3 && T[idx][2] != T[idx + 1][6] && preIdx != idx + 1)
        roll(idx + 1, idx, ord * -1);


    // 톱니 돌리기
    if(ord == -1)
    {
        temp = T[idx][0];
        for(int i = 0 ; i < 7 ; i++)
            T[idx][i] = T[idx][i+1];
        T[idx][7] = temp;
    }
    else if(ord == 1)
    {
        temp = T[idx][7];
        for(int i = 7 ; i > 0 ; i--)
            T[idx][i] = T[idx][i-1];
        T[idx][0] = temp;
    }

}
int main()
{
    int K, idx, ord, score = 0;

    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < 8 ; j++)
            scanf("%1d",&T[i][j]);

    cin >> K;
    while(K--)
    {
        cin >> idx;
        cin >> ord;

        roll(idx - 1, -1, ord);       //preIdx를 처음엔 -1로 함
    }

    for(int i = 0 ; i < 4 ; i++)
        if(T[i][0] == 1)
            score += pow(2, i);     //점수 계산

    cout << score;

}