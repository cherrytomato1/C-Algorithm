/*

	16637 괄호 추가하기

	1<=N<=19 의 수식 부여 예외 없음

	수식에 임의로 괄호를 부여하여 가장 큰 결과를 출력하는 식의 계산 결과를 출력해라

	괄호 안에는 반드시 하나의 연산자만 포함되며 중복 괄호는 없음


	1. 앞의 연산자부터 계산한다고 했을 때 경우의 수는 
		1-1. 괄호를 넣지 않는다, +a
		1-2. 괄호를 넣는다, +(a+b)
	2. 경우의 수에 따라 인덱스를 이동한다. 1-1의 경우 1개의 연산만 했으므로 index+=2, 1-2는 index+=4
	3. 위의 점화식으로 모든 경우의 수를 재귀함수를 통해 연산하고 최댓값을 구한다.
	4. 연산자가 f의 인덱스에 존재하게 구성했으므로 index==0 일때 초기값을 지정해준다(str[0]은 피연산자임)
	5. 연산 시 모든 항에 괄호를 씌워 연산하므로 +,*의 연산 우선순위는 고려하지 않는다.

	* 음수값이 답일 수 있으므로 INT_MIN으로 결과값 초기화

*/

#include<iostream>
#include<algorithm>
#include<string>
#include<climits>

using namespace std;

int N,ans=INT_MIN;	
string str;

int calc(int a, int b, char op)			//연산 함수
{
	switch (op)
	{
	case '+' :
		return a + b;
	case '-' :
		return a - b;
	case '*' :
		return a * b;
	case '/':
		return a / b;
	default :
		return 0;
	}
}

int casting(int index)					//string 형변환 함수
{
	return str[index] - '0';
}

void f(int val, int index)				//재귀함수
{

	if (index > N - 1)					//모든 인덱스에 대한 연산이 끝났을 경우
	{
		ans = max(val, ans);
		return;
	}	

	if (index == 0)						//초기 연산, 피연산자가 계산 대상이므로 예외처리
	{
		f(casting(index),index+1);
		f(calc(casting(index), casting(index + 2), str[index + 1]), index + 3);
	}
	
	else
	{
		f(calc(val, casting(index + 1), str[index]), index + 2);				//괄호 없이 바로 다음항과 연산

		if (index < N - 3)
			f(calc(val, calc(casting(index + 1), casting(index + 3), str[index + 2]), str[index]), index + 4);		
																				//다음항이 괄호가 있어 그 연산을 먼저 끝내고 연산
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> str;

	f(0, 0);

	cout << ans;

}