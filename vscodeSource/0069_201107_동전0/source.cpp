#include <iostream>
#include <vector>

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

    //cout << "good" ;
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