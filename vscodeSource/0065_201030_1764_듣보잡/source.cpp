#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define max 500000

using namespace std;

vector<string> vtr;
vector<string> vtr2;

string d[max];
string b[max];


int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, cnt = 0;

    string temp;
    cin >> N;
    cin >> M;

    for (int i = 0 ; i < N ; i++)
    {    //cin >> d[i];
        cin >> temp;
        vtr.push_back(temp);
    }

    for (int i = 0 ; i < M ; i++)
    {
        //cin >> b[i];
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