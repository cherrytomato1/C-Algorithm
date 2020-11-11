#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	double tmp1,tmp2;

	stack<double> stk;
	vector<double> V;
	string str;

	cin >> N;
	cin.ignore();

	getline(cin, str);

	while (N--)
	{
		cin >> tmp1;
		V.push_back(tmp1);
	}


	for (int i = 0; i < str.length(); i++)
	{
		switch (str[i])
		{
		case '+' :
			tmp1=stk.top();
			stk.pop();
			tmp2 = stk.top();
			stk.pop();
			stk.push(tmp2 +tmp1);
			break;

		case '-':
			tmp1 = stk.top();
			stk.pop();
			tmp2 = stk.top();
			stk.pop();
			stk.push(tmp2 - tmp1);
			break;

		case '*':
			tmp1 = stk.top();
			stk.pop();
			tmp2 = stk.top();
			stk.pop();
			stk.push(tmp2 * tmp1);
			break;

		case '/':
			tmp1 = stk.top();
			stk.pop();
			tmp2 = stk.top();
			stk.pop();
			stk.push(tmp2/ tmp1);
			break;

		default:
			stk.push(V[(int)str[i]-65]);
			break;

		}
	}
	printf("%.2f", stk.top());

}