#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define max 500000

using namespace std;

vector<string> vtr;

string d[max];
string b[max];


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, cnt = 0;

    cin >> N;
    cin >> M;

    for (int i = 0 ; i < N ; i++)
        cin >> d[i];

    for (int i = 0 ; i < M ; i++)
        cin >> b[i];
           
    for (int i = 0 ; i < N ; i++)
        for (int j = 0; j < M ; j++)
            if(d[i] == b[j])
            {
                cnt++;
                vtr.push_back(d[i]);
                break;
            }

    sort(vtr.begin(), vtr.end());
    cout << cnt;
    
    for(int i = 0 ; i < vtr.size(); i ++ )
        cout << "\n" << vtr[i] ;
}
/*            if(d[i].length() == b[j].length())
            {    
                for(k = 0; k < d[i].length() && k < b[j].length(); k ++)
                    if(d[i][k]!=b[j][k])
                        break;
                if( k == d[i].length() )
                {
                    cnt++;
                    break;
                }
            }
*/