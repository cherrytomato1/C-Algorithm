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
    //cout << "roll " << idx << " , ord =  " << ord << ", preidx = " << preIdx << "\n";

    if(idx != 0 && T[idx][6] != T[idx - 1][2] && preIdx != idx - 1)
        roll(idx - 1, idx, ord * -1);
    if(idx != 3 && T[idx][2] != T[idx + 1][6] && preIdx != idx + 1)
        roll(idx + 1, idx, ord * -1);

    //cout << "starting roll..." << "\n";

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
    //cout << "fin roll : " << idx << ", ord = " << ord << "\n";

}

void check(int idx)
{

}

int main()
{
    /*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    */


    int K, idx, ord, score = 0;

    for(int i = 0 ; i < 4 ; i++)
        for(int j = 0 ; j < 8 ; j++)
            scanf("%1d",&T[i][j]);

    cin >> K;
    while(K--)
    {
        cin >> idx;
        cin >> ord;

        roll(idx - 1, -1, ord);       
        /*
        for(int i = 0 ; i < 4 ; i++)
        {
            for(int j = 0 ; j < 8 ; j++)
                cout << T[i][j];
            cout << "\n";
        }
        */
    }

    for(int i = 0 ; i < 4 ; i++)
        if(T[i][0] == 1)
            score += pow(2, i);

    cout << score;

}