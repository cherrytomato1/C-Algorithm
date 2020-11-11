#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N[9], sum=0,temp;

	for (int i = 0; i < 9; i++)
	{
		cin >> N[i];
		sum += N[i];
	}
	sort(N,&N[9]);


	for (int i = 0; i < 9; i++)
		for (int j = i + 1; j < 9; j++)
			if (sum - N[i] - N[j] == 100)
			{
				for (int k = 0; k < 9; k++)
					if (k != i && k != j)
						cout << N[k] << "\n";
				return 0;
			}
}