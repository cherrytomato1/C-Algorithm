/*문자열 N개가 주어진다. 이때, 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램을 작성하시오.

각 문자열은 알파벳 소문자, 대문자, 숫자, 공백으로만 이루어져 있다.

입력
첫째 줄부터 N번째 줄까지 문자열이 주어진다. (1 ≤ N ≤ 100) 문자열의 길이는 100을 넘지 않는다.

출력
첫째 줄부터 N번째 줄까지 각각의 문자열에 대해서 소문자, 대문자, 숫자, 공백의 개수를 공백으로 구분해 출력한다.




10820 문자열 분석*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int N, big, small, blank, num;

	N = 100;

	while (N--)
	{
		big = 0;
		small = 0;
		blank = 0;
		num = 0;
		
		getline(cin, str);
		if (str.length() == 0)
			break;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == 32)
				blank++;
			else if (str[i] >= 48 && str[i] <= 57)
				num++;
			else if (str[i] >= 65 && str[i] <= 90)
				big++;
			else if (str[i] >= 97 && str[i] <= 122)
				small++;
		}
		cout << small << " ";
		cout << big << " ";
		cout << num << " ";
		cout << blank << "\n";
	}
}

