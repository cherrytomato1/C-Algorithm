#include<iostream>
#include<string>
#include<vector>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	int first=0;

	cin >> N;

	first += ((N[0] - '0') / 4) * 100;
	first += ((N[0] - '0') % 4) / 2 * 10;
	first += ((N[0] - '0') % 4) % 2;
	
	cout << first;

	for (int i = 1; i < N.length(); i++)
	{
		cout << (N[i] - '0') / 4;
		cout << ((N[i] - '0') % 4) / 2;
		cout << ((N[i] - '0') % 4) % 2;
	}
}