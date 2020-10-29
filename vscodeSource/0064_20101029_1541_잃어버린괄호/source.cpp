/*


    잃어버린 괄호

    x + y - z

    먼저 연산자와 수를 구분하여 저장한다.

    연산자를 순서대로 검사하며 - 일 경우 다음 -가 나올 때까지 모든 +연산을 -로 대치하면 된다.

    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;

    ios_base :: sync_with_stdio(false)
    cin.tie(NULL);
    cout.tie(NULL);



*/


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

string str;
int temp = 0 , res = 0;

vector<int> num;
vector<char> op;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;

    for(int i = 0 ; i < str.length() ; i++)     //연산자 구분과정
    {
        switch(str[i])
        {
        case '+' :
        case '-' :
            num.push_back(temp);
            temp = 0;
            op.push_back(str[i]);
            break;
        default :
            temp *= 10;
            temp += str[i] - 48;
        }
    }
    num.push_back(temp);                        //맨 마지막 수는 따로 추가한다.


    res += num[0];                              //맨 첫번째 수는 더하고 시작한다.
    for(int i = 0; i < op.size() ; i++)         //연산자 끝까지 검사
    {   
        if(op[i] == '-')                        // - 일 경우 다음 - 연산이 나올때까지 모두 뺀다(괄호로 취급)
        {
            res -= num[i+1];                    //num의 index에 +1을 함으로 다음 숫자를 연산
            while(++i <op.size() && op[i] == '+')       //범위를 초과하지 않는 이내에서 +연산일 경우 반복
                res -= num[i+1];
            i--;                                //+ 검사를 위해 ++했기 때문에 index 값을 다시 맞추어준다
        }
        else
            res += num[i+1];                    //ㄷㅓ하기면 그냥 더함
    }

    cout << res;
    
}
