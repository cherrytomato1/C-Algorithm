/*
    그리디 저울

    1 1 4 5

    1 = 1
    2 = 1 + 1
    3

    재려는 무게     K   1000k
    추 개수        N      1k 

    재려는 무게보다 작으면서 가장 큰 추부터 시작해서 무게를 빼나간다, 그 과정을 반복해서 저울이 0이되면 성공?

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> vtr;

void getInput()
{
    int N, temp;

    cin >> N;

    while(N--)
    {
        cin >> temp;
        vtr.push_back(temp);
    }

    sort(vtr.begin(), vtr.end());

}

int weightSearch()                  //현재 시간복잡도 n^2k
{
    int answer = vtr[0] ,idx = 0 ,temp ;
    while (answer++)
    {
        temp = answer;
        for(int i = idx ; i < vtr.size() ; i++ )
            if(temp < vtr[i] && i == vtr.size() - 1)
            {
                idx = i;
                for(int j = i - 1; j >= 0 ; j --)
                {
                    if(temp >= vtr[j])
                        temp -= vtr[j];
                    if(temp == 0)
                        break;
                }
                if(temp != 0)
                    return answer;
                else
                    break;
            }
    }
    return 0;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getInput();

    cout << weightSearch();
}