#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int res = 0;
    string str;

    getline(cin,str);

    for(int i = 1 ; i<str.length()-1; i++)
        if(str[i] == ' ')
            res++;

    if(str.length()==1&& str[0]==' ')
        res--;
    cout << ++res;

}