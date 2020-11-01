/*
    단순 이중 반복문으로 비교할 경우 시간초과 발생

    ->모든 문자열을 하나의 벡터에 넣은 다음 사전순으로 정렬하여
    바로 옆에 있는 문자열과 비교할 경우 같은 것을 식별 가능
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define max 500000

using namespace std;

vector<string> vtr;
vector<string> vtr2;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    string temp;
    cin >> N;
    cin >> M;

    for (int i = 0 ; i < N ; i++)
    {    
        cin >> temp;
        vtr.push_back(temp);
    }

    for (int i = 0 ; i < M ; i++)
    {
        cin >> temp;
        vtr.push_back(temp);
    }
    sort(vtr.begin(), vtr.end());

    for (int i = 0 ; i < vtr.size()-1; i++)
        if(vtr[i] == vtr[i+1])
            vtr2.push_back(vtr[i]);

    cout << vtr2.size();
    
    for(int i = 0 ; i < vtr2.size(); i ++ )
        cout << "\n" << vtr2[i] ;
}
