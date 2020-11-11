/*

    추의 무게를 오름차순으로 정렬했을 때

    추가 1 하나일 경우 최대 측정 가능한 수는 1이며, 측정 불가능한 수는 2이다

    추의 누적합 + 1이 다음에 올 추의 크기보다 작다면 그 것이 측정 불가능한 해

    누적합 20일 때 다음 추가 21 보다 크면 21은 측정 불가능함

    ex

    1, 1, 4 -> 
        a0 = 1 , s0 = 0 ,     a0 == s0 + 1 
        a1 = 1 , s1 = 1 ,     a1 == s1 + 1
        a2 = 4 , s2 = 2 ,     a2 > s2 + 1
        따라서 3은 측정할 수 없음.

    누적합을 다 측정할 수 있다고 가정하는 이유 :
        1부터 모든 추의 누적합을 조건 계산하므로 1, 3의 추만 있을 때 2는 측정할 수 없고 2가 있으면 
        1, 2가 있으면 누적합이 3이므로 3까지는 다 측정 가능함, 3+1에 해당하는 추가 없을 경우 해라고 판단
        1, 2, 4의 경우 1,2,3 까지 2의 누적합으로 구함, 4 는 4로 만들 수 있으므로 가능 따라서 누적합 7까지는 
        3까지 만들 수 있는 1,2의 추와 4까지 만들 수 있는 4의 추가 있어서 모두 가능

    더이상 누적합과 비교할 수 있는 추가 없을 경우 현재의 누적합 +1 은 만들 수 없으므로 그것이 해가 됨.

*/



#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> vtr;

void getWeight()
{
    int N;
    int temp;

    cin >> N;

    while(N--)
    {
        cin >> temp; 
        vtr.push_back(temp);
    }

    sort(vtr.begin(), vtr.end());
}

int solve()
{
    int sum = 0;

    for (int i = 0; i < vtr.size() ; i++)           //벡터의 인덱스 증감, 더이상 비교할 추가 없으면 반복 종료
    {
        if( vtr[i] > sum + 1)                       //현재의 추와 누적합 비교, 누적합+1보다 추가 크다면 거기서 종료
            return sum + 1;

        sum += vtr[i];                              //비교가 끝났다면 추를 누적합에 더함.
    }
    return sum + 1;                                 //비교할 추가 없으면 현재 누적합+1이 해임
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    getWeight();
    cout << solve();
}