/*
    그리디 알고리즘 ,
    오름차순으로 주어지는 동전 크기를 배열에 큰 숫자부터 담아서
    동전크기가 남은 돈을 초과할 경우에만 다음 동전과 비교함(인덱스++)


*/

#include <iostream>

#define aMAX 10

int arr[10] = {0};

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, idx = 0, cnt = 0;
    int temp;

    cin >> N;
    cin >> K;

    for(int i = N-1 ; i >= 0 ; i-- )
        cin >> arr[i];

    while(K!=0)
    {
        if(K < arr[idx])
            idx++;
        else
        {
            K -= arr[idx];
            cnt++;
        }
    }

    cout << cnt;

}