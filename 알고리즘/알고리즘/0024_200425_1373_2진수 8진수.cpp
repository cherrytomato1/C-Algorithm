/*

입력이 100만 자리까지 가능하므로

결과 출력이나 임시저장 temp에서 overflow가 발생하여 결과값이 틀리게 나옴

unsigned long long으로 했을 경우도 마찬가지

결과값을 한자리씩 따로 저장하여 해결


*/






#include<iostream>
#include<string>
#include<stack>
#include<cmath>


using namespace std;

int main()
{

	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt=0, temp = 0;
	string input;
	stack<int> N,oStk;

	cin >> input;

	for (int i = 0; i < input.size(); i++)
		N.push((int)input[i]-'0');

	for (;; N.pop(),cnt++)				//012 반복 cnt
	{
		if (N.empty())									//모든 숫자 다 확인했으면
		{
			if (temp != 0)
				oStk.push(temp);						//남은 숫자 더해주기
			break;
		}
		temp += N.top() * pow(2, cnt);					//현재 숫자 *2^cnt 

		if (cnt == 2)									//3자리씩 끊어서 검사하기
		{
			oStk.push(temp);							//스택에 푸시
			temp = 0;
			cnt = -1;
		}
	}

	if (oStk.empty())
		cout << "0";
	else
		while (!oStk.empty())
		{
			cout << oStk.top();
			oStk.pop();
		}
}