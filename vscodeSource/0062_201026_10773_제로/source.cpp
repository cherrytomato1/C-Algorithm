#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N,sum = 0;
    stack<int> stk;

    cin >> K;

    while(K--)
    {
        cin >> N;
        if(N!=0)
            stk.push(N);
        else
            stk.pop();
    }
    while(!stk.empty())
    {
        sum += stk.top();
        stk.pop();
    }
    cout << sum;
}