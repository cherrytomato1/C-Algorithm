/*
    그리디, 가장 큰 수끼리 묶어서 곱하면 가장 큰 값이 나온다

    음수의 경우는 가장 작은 두 값끼리 곱하면 가장 큰 값이 나온다.
    
    양수와 음수를 따로 검사한다. 음수는 가장 작은 수부터 검사하기 위해

    i와 i+1 (음수는 i-1)을 곱한 게 i+i+1보다 크면 묶어서 더함, 아니면 그냥 하나만 더함
    
    양수는 더할 때 1까지만 커지므로 1까지만 연산, 음수는 0을 곱해도 커지므로 0까지 계산



*/




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> vtr;

int f()     //음수.,..,
{
    int answer = 0;
    for(int i = 0 ; i < vtr.size() && vtr[i]>= 1; i++)
    {
        if(i + 1 != vtr.size() && vtr[i] * vtr[i+1] > vtr[i]+vtr[i+1] )
            answer += (vtr[i] * vtr[++i]);
        else
            answer += vtr[i];
    }
    
    for (int i = vtr.size()-1; i >=0 && vtr[i] <= 0 ; i--)
    {
        if(i - 1 >= 0 && vtr[i] * vtr[i-1] > vtr[i] + vtr[i-1])
            answer += (vtr[i] * vtr[--i]);
        else
            answer += vtr[i];
        
    }
    return answer ;

}

bool cal(int a, int b)      //내림차순
{
    return a > b;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N ,num;

    cin >> N;

    while(N--)
    {
        cin >> num;
        vtr.push_back(num);
    }

    sort(vtr.begin(),vtr.end(),cal);


    cout << f();
}