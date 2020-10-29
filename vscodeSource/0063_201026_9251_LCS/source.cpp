/*

    다음과 같은 동적 계획법으로 해결함

    CAPCAK와 ACAYKP를 비교할 때
    다음과 같은 테이블로 LCS를 구할 수 있음

    비교하는 문자가 같은 경우 table에 1을 더하고 
    그 이후 등장하는 모든 하위 문자열에도 1을 더한다.
    이런 식으로 가장 큰 값을 가진 테이블의 인덱스의 값이  lcs가 된다.

    
        |   | # | C | A | P | C | A | K |
        |---|---|---|---|---|---|---|---|
        | # | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
        | A | 0 | 0 | 1 | 1 | 1 | 1 | 1 |
        | C | 0 | 1 | 1 | 1 | 2 | 2 | 2 |
        | A | 0 | 1 | 2 | 2 | 2 | 3 | 3 |
        | Y | 0 | 1 | 2 | 2 | 2 | 3 | 3 |
        | K | 0 | 1 | 2 | 2 | 2 | 3 | 4 |
        | P | 0 | 1 | 2 | 3 | 3 | 3 | 4 |

    비교할 때 두 문자가 같으면 그 문자들을 포함한 이전문자열 즉  row-1, col-1의 값에 1을 더한값을 테이블에 넣게된다.
    아닐 경우 두 문자가 포함된 이전 문자열 row-1 col-1의 문자열 중 더 큰 값을 갖는 문자열의 값이 테이블에 들어간다.

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