#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,cnt=0,tmp;
	vector<int> number;

	cin >> N;
	
	cin.ignore();

	while (N--)
	{
		cin >> tmp;
		number.push_back(tmp);
	}

	for (int i = 0; i < number.size(); i++)
		for (int j = 2; j <= number[i]; j++)
		{
			if (number[i] == j)
				cnt++;
			else if (number[i] % j == 0)
				break;
		}

	cout << cnt;
}