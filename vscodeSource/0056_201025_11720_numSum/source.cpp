#include<iostream>
#include<string>

using namespace std;

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,sum = 0;
    string str;

    cin >> N;
    cin >> str;

    for(int i =0; i<N; i++)
        sum += str[i]-48;
    
    cout << sum;

    return 0;

    
}