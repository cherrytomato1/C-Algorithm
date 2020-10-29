/*


    0, 0 -> 0, 1 -> 0, 2 ... 0, length

    0, 0 -> 0, 1 -> 1, 2,

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str1, str2;
int cnt = 0;
int d[1000+1][1000 + 1] = {0, };

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str1;
    cin >> str2;

    int val = 0, k, l;

    for(int i  = 0; i < str1.length(); i ++)
        for(int j = 0; j < str2.length(); j ++)
        {
            if(str1[i] == str2[j])
                d[i+1][j+1] = d[i][j] + 1;
            else
                d[i+1][j+1] = max(d[i][j+1], d[i+1][j]);
        }
    
    for (int i = 0 ; i < 1000+1 ; i++)
        for(int j = 0; j < 1000 + 1 ; j++ )
            cnt = max(cnt , d[i][j]);

    cout << cnt;   
}