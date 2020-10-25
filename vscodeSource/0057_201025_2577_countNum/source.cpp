#include<iostream>
#include<string>

using namespace std;

int n[10] = {0,};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A,B,C,res;
    string str;

    cin >> A;
    cin >> B;
    cin >> C;

    str = to_string(A*B*C);

    for(int i = 0; i<str.length(); i++)
        n[str[i]-48]++;
    
    cout << n[0];
    for(int i = 1; i<=9; i++)
        cout <<"\n" << n[i];

    return 0;
    

}