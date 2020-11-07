/*

    단어수학

    각 알파벳을 pair로 알파벳, 점수로 저장
    점수는 자릿수에 따라 10^n임
    점수에 따라 알파벳을 정렬하고 순서대로 9~0의 수 할당

    할당된 수를 알파뱃과 치환하여 덧셈 계산


*/



#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

string str;
vector <pair <int, char> > vtr;
vector <string> strVtr;

bool compare(pair<int, char> p1, pair<int, char> p2)
{
    return p1.first > p2.first;
}

void getstr(int N)
{
    int score;
    while(N--)
    {
        cin >> str;
        strVtr.push_back(str);

        score = 1;
        for(int i = str.length()-1 ; i >= 0; i--, score *= 10)
        {
            if(vtr.empty())
            {
                vtr.push_back(make_pair(score, str[i]));    //초기에 벡터가 비어있으므로 하나 넣어주기
                continue;
            }

            for(int j = 0 ; j < vtr.size(); j ++)           //알파벳 벡터에 이미 알파벳이 있는지 검사
            {
                if(vtr[j].second == str[i])                 // 있으면 점수 더해서 다시 넣기
                {
                    vtr[j] = make_pair(vtr[j].first + score, str[i]);
                    break;
                }
                else if( j == vtr.size()-1)
                {
                    vtr.push_back(make_pair(score, str[i]));
                    break;                              //push_back하면 size()를 늘려주니까 반복문이 한 번 더 도는 에러가 있음
                }
            }
        }
    }
}

void setScr()
{
    sort(vtr.begin(),vtr.end(), compare);               //내림차순 정렬

    int score = 9;
    for(int i = 0 ; i < vtr.size() ; i ++, score --)
        vtr[i] = make_pair(score, vtr[i].second);       //9~0 수 할당
}

void replaceStr(int N)
{
    for(int i = 0 ; i < N; i++)                         //string들
        for(int j = 0 ; j < strVtr[i].size() ; j++)     //string의 문자들
            for(int k = 0 ; k < vtr.size() ; k++)       //알파벳 벡터랑 비교
                if(vtr[k].second == strVtr[i][j])       //점수랑 바꾸기
                    strVtr[i][j] = (char)(vtr[k].first + '0');
}

int sum()
{
    int answer = 0 ;

    for(int i = 0 ; i < strVtr.size(); i++)
        answer += stoi(strVtr[i]);

    return answer;
    
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    getstr(N);
    setScr();
    replaceStr(N);

    cout << sum();
    
}