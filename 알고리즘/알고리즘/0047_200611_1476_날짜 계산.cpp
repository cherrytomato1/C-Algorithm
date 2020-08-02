/*
	1. e = e% 15 + 1,  s% 28 +1, m%19 +1
*/

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int E, S, M;
	int et=1, st=1, mt=1,ans=1;
	cin >> E;
	cin >> S;
	cin >> M;

	while (E!=et || S!=st || M!=mt)
	{
		et = et%15 +1;
		st = st%28 +1;
		mt = mt%19 +1;
		ans++;
	}

	
	cout << ans;
}