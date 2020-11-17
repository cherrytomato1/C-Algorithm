/*


    들어오는 비행기가 들어갈 수 있는 가장 큰 수 부터 채워넣는다면?

    10만 * 10만 = 100억 g^2는 시간초과

    g
    

*/
#include<iostream>
#include<vector>

#define MAX 100000

using namespace std;


int G, P;
int gate[MAX+1];

int solve()
{
    int input;
    for (int i = 0 ; i < P ; i++)
    {
        cin >> input; 
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> G;
    cin >> P;

    cout << solve();
}