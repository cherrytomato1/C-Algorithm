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

void f(stack<char>* stk,vector<char>* vctr, char x)
{
	switch (x)
	{
	case '+' :
	case '-' :
		if (!stk->empty())
			switch (stk->top())
			{
			case '+':
			case '-':
			case '*':
			case '/':
				vctr->push_back(stk->top());
				stk->pop();

			case '(':
				stk->push(x);
				break;

			default:
				printf("op push error1");
				return;
			}
		else
			stk->push(x);
		break;
	case '*' :
	case '/' :
		if (!stk->empty())
			switch (stk->top())
			{
			case '*':
			case '/':
				vctr->push_back(stk->top());
				stk->pop();
			case '+':
			case '-':
			case '(':
				stk->push(x);
				break;
			default:
				printf("op push error 2");
				return;
			}
		else
			stk->push(x);
		break;
	case '(' :
		stk->push(x);
		break;
	case ')' :
		while (stk->top()!='(')
		{
			vctr->push_back(stk->top());
			stk->pop();
			//printf(") test..\n");
		}
		stk->pop();
		break;


	default :
		vctr->push_back(x);
		break;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<char> op_stk;
	int length;
	string str;
	vector<char> postfix;
	cin >> str;

	for (int i = 0; i < str.length(); i++)
		f(&op_stk, &postfix, str[i]);

	while (!op_stk.empty())
	{
		postfix.push_back(op_stk.top());
		op_stk.pop();
	}

	for (int i = 0; i < postfix.size(); i++)
		cout << postfix[i];
}