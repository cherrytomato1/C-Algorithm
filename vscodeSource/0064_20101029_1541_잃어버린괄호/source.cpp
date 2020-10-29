/*


    잃어버린 괄호

    x + y - z


    -인 것들만 괄호를 열고 내용물은 + 하기만???


*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string str;
int temp = 0 , res = 0;

vector<int> num;
vector<char> op;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for(int i = 0 ; i < str.length() ; i++)
    {
        switch(str[i])
        {
        case '+' :
        case '-' :
            num.push_back(temp);
            temp = 0;
            op.push_back(str[i]);
            break;
        default :
            temp *= 10;
            temp += str[i] - 48;
        }
    }
    num.push_back(temp);

/*
    for (int i = 0 ; i < op.size() ; i++)
    {
        cout << num[i] << " ";
        cout << op[i] << " ";
        
        if(i + 1 == op.size())
            cout << num[i+1];
    }
*/


    //cout << "\n" << op.size() << " " << num.size() ;

    res += num[0];
    for(int i = 0; i < op.size() ; i++)
    {   
        if(op[i] == '-'){
            res -= num[i+1];
            while(++i <op.size() && op[i] == '+')
                res -= num[i+1];
            i--;
        }
        else
            res += num[i+1];
    }

    cout << res;
    
}
