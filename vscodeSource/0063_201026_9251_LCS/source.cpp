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

void d(int idx1, int idx2, int val)
{
    if(idx1 == str1.length() || idx2 == str2.length())
    {
        cnt = max(cnt, val);
        return ;
    }    

    for (int i = idx1; i < str1.length(); i++)
    {
        for (int j = idx2; j< str2.length(); j++)
        {
            if(str1[i] == str2[j])
            {
                //cout << str1[i] << " == " << str2[j] << " , val ==" << val << "\n";
                d(i + 1, j + 1, val+1);
                return ;

            }
        }
    }
    
    //cnt = max(cnt, val);
}

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
            d(i,j,0);
    
    cout << cnt;   
}