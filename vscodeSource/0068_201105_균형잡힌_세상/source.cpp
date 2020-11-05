#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    stack<char> stk;

    getline(cin, str);
    
    while(str[0]!='.')
    {
        for(int i = 0 ; i < str.length(); i++)
        {
            switch(str[i])
            {
            case '(' :
            case '[' :
                stk.push(str[i]);
                break;
            case ')' :
                if(stk.empty() || stk.top() != '(')
                {
                    stk.push(str[i]);
                    break;
                }
                else
                    stk.pop();
                break;
            case ']' :
                if(stk.empty() || stk.top() != '[')
                {
                    stk.push(str[i]);
                    break;
                }
                else
                    stk.pop();
            }
        }

        if(stk.empty())
            cout << "yes" << "\n";
        else
        {
            cout << "no" << "\n";
            while(!stk.empty())
                stk.pop();
        }

        getline(cin, str);
    }
}