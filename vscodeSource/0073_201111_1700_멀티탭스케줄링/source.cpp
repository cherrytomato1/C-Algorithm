/*

    스케줄링 : 이미 작업 중인 프로세스 중 다음에 가장 나중에 사용될 요소를 제거

    n = 100
    k = 100

    다음에 쓰일 때 가장 나중에 쓰이는 요소만 찾아 검사하고 이외의 경우는 생각하지 않으므로
    그리디 알고리즘임

    1. 플러그가 비어있을 경우
        - 모든 작업 요청에 대해 반복(k)
        1. 1 -> 작업목록을 검사하여 이미 해당작업이 있을 경우 넣지 않는다 n*k
        1. 2 -> 처음으로 들어오는 작업일 경우 해당 작업을 push 

    2. 플러그가 가득찼을 경우, 빼야하는 경우 (k)
        2. 1 -> 작업목록을 검사하여 해당 작업이 이미 있을 경우 break (n*k)
        2. 2 -> 작업목록에 해당 작업이 없을 경우
            2.2.3 -> 작업목록에 있는 작업이 작업요청 목록에 몇 번째 인덱스에 있는 지 검사 (n* k^2)
            2.2.4 -> 작업요청목록에 인덱스가 가장 큰 작업요청을 작업목록에서 뺀다
            2.2.5 -> 해당 작업목록이 작업 요청목록에 없을경우(다음에 쓰이지 않을 경우) 우선순위 부여
    

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vtr;
vector<int> prcss;

void getOrder(int K)            //작업요청명령 받기
{
    int a;
    while(K--)
    {
        cin >> a;
        vtr.push_back(a);
    }
}

int solution(int N, int K)
{
    int answer = 0;
    int index = 1, waiting, next = -1;
    
    prcss.push_back(vtr[0]);          //첫 번쨰 작업요청은 바로 작업목록에 넣는다

    for(; index < K; index++)         //모든 작업요청에 대해 반복
    {
        if(prcss.size() < N)          //플러그가 가득 차지 않았을 경우
        {
            for(int i = 0 ; i < prcss.size() ; i++)     //작업중인 목록 검사
            {
                if(prcss[i] == vtr[index])              //넣으려는 작업이 이미 작업목록에 존재하는 경우
                    break;
                if(i == prcss.size() - 1)               //검사가 끝났음에도 동일 작업이 검출되지 않았을 경우
                {
                    prcss.push_back(vtr[index]);
                    break;
                }
            }
            continue;
        }
        
        waiting = 0;                //작업요청목록에서의 인덱스 저장
        for(int i = 0; i < N ; i ++)            //현재 작업중인 목록 검사
        {
            if(prcss[i] == vtr[index])          //이미 존재할 경우 break;
            {
                next = -1;
                break;
            }
            
            for(int j = index ; j < K ; j++)    //작업 요청목록 검사
            {
                if(vtr[j] == prcss[i])          //작업요청목록에서 작업을 발견했을 경우
                {
                    if(waiting <= j)            //가장 높은 인덱스를 갖는 경우
                    {
                        waiting = j;            //다음 교체 작업 갱신
                        next = i;
                    }
                    break;
                }
                if(j == K - 1)                  //검사가 끝났음에도 검출되지 않은 경우, 해당 작업이 다음에 쓰이지 않을 경우
                {
                    waiting = K+1;              //우선 순위 부여
                    next = i;
                }
            }
        }

        if(next != -1)                          //작업이 이미 있는 경우가 아닐 때
        {
            prcss[next] = vtr[index];           //작업 교체
            answer++;
        }
    }
    return answer;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;

    cin >> N;
    cin >> K;

    getOrder(K);
    cout << solution(N,K);
}