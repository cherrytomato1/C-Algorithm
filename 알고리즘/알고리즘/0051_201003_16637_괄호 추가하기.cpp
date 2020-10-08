/*

	주어진 수식에 임의의 괄호를 추가하여 최댓값을 구하여라

	연산자는 +과 *만 사용됨

	주어지는 수는 0~9

	수식은 항상 홀수이며 1<=N<=19임


	3+3*2

	332+*
	3+3*2
	-> (3+3)*2


*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	stack<char> stk;
	string input;

	cin >> input;

}