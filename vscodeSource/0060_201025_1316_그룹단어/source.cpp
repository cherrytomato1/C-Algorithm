#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int N,res = 0;
    int chk[26]= {0};       //알파뱃 총 26개

    cin >> N;
    getline(cin,str);

    while(N--)
    {
        getline(cin,str);
        memset(chk, 0, sizeof(chk));

        for(int i = 0; i < str.length(); i++)
        {
            chk[str[i] - 97]++;
            if(i!=0&&str[i]==str[i-1])
                chk[str[i]-97]--;
        }


        for(int i = 0 ; i<26;i++)
        {
            if(chk[i]>=2)
                break;
            if(i==25)
                res++;
        }
    }

    cout << res;

}