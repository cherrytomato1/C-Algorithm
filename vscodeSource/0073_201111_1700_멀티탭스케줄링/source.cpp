/*


    스케줄링 => 남은 리스트에서 가장 사용이 늦은 요소를 제외?

    2 3 4 2 3 3 3 3

    2구

    2 3 4 3 4 3 2 2 2 4
    사용횟수
    2 = 4, 3 = 3 , 4 = 3

    0. 2 0 <- 2             
    1. 2 3 <- 3 
    2. 4 3 <- 4 / +1        남은 2 =3, 3 =2 , 4=3    
    3. 4 3 <- 3
    4. 4 3 <- 4
    5. 4 3 <- 3
    6. 4 2 <- 2 / +1
    7. 4 2 <- 2 
    8. 4 2 <- 2
    9. 4 2 <- 2

    2회  


    

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vtr;
vector<int> prcss;

void getOrder(int K)
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
    
    prcss.push_back(vtr[0]);

    for(; index < K; index++)
    {
        if(prcss.size() < N)
        {
            //cout << prcss.size() << " , " << vtr[index] <<   "!!!!\n";
            for(int i = 0 ; i < prcss.size() ; i++)
            {
                if(prcss[i] == vtr[index])
                {
                    //cout << "breaK1!! : " << prcss[i] << " = " << vtr[index] << ", " << i <<index << "\n";
                    break;
                }
                if(i == prcss.size() - 1)
                {
                    //cout << "push !!! : " << vtr[index] << "\n" ;
                    prcss.push_back(vtr[index]);
                    break;
                }
//                cout << index << "! " << i << "\n";
            }
            //for(int i = 0 ; i < prcss.size(); i++)
                //cout <<prcss[i] << " " ;
            //cout << "\n";
            continue;
        }
        
        waiting = 0;
        for(int i = 0; i < N ; i ++)
        {
            if(prcss[i] == vtr[index])
            {
                next = -1;
                //cout << prcss[i] << " = " << vtr[index] << " ; break! , index = " << index << "\n";
                break;
            }
            
            for(int j = index ; j < K ; j++)
            {
                if(vtr[j] == prcss[i])
                {
                    if(waiting <= j)
                    {
                        waiting = j;
                        next = i;
                    }
                    break;
                }
                if(j == K - 1)
                {
                    waiting = K+1;
                    next = i;
                }
            }
        }

        if(next != -1)
        {
            prcss[next] = vtr[index];
            answer++;
        }

        //for(int i = 0 ; i < N; i++)
            //cout <<prcss[i] << " " ;

        //cout << "next = " << next ;
        //cout << ", vtr[index] =  " << vtr[index]  <<"\n";
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