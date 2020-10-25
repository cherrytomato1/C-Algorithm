#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,sum = 0, score = 0;
    string str;

    cin >> T;
    
    while(T--)
    {
        cin >> str;
        for(int i = 0 ; i <str.length(); i++)
        {
            if(str[i] == 'O')
                sum +=++score;
            else if(str[i] == 'X')
                score = 0;
        }

        cout << sum << "\n";

        sum = 0;
        score = 0;
    }
}