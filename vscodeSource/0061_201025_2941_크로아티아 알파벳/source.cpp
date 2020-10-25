#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int cnt = 1;
    cin >> str; 

    for(int i =1; i<str.length();i++)
    {
        cnt++;
        switch(str[i])
        {
            case '=' :
                if(str[i - 1] == 'c' || str[i - 1] == 's')
                    cnt--;
                if(str[i - 1] == 'z')
                {
                    if(i > 1 && str[i - 2] == 'd')
                        cnt -= 2;
                    else
                        cnt --;
                }
                break;
            case '-' :
                if(str[i - 1] == 'c' || str[i - 1] == 'd')
                    cnt--;
                break;
            case 'j' :
                if(str[i - 1] == 'n' || str[i - 1] == 'l')
                    cnt--;
                break;
        }
    }
    cout << cnt ;
}