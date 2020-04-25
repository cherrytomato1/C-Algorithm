/*

1. 수빈이와 동생들 사이의 거리에서 최대 공약수를 구하는 문제
2. 수빈이의 좌표와 동생 좌표로 수빈이와 동생들의 자연수 거리를 구함
3. 모든 동생들의 거리의 최대공약수를 구함 ( 유클리드 호제법)




*/








#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

using namespace std;

int getGCD(int a, int b)			//유클리드 호제법 재귀형식
{
	if (b == 0)						//최대 공약수 (나누어 떨어짐)을 구하면 리턴
		return a;
	else							//두 수가 약수가 아닐 경우 작은값(나누어 남은 나머지 값)을 반복하여 나눔
		return getGCD(b, a % b);
}

int arrGCD(vector <int>V)			//벡터에서의 최대공약수 구하기
{
	int GCD;

	if (V.size() == 1)				//1개일 경우 자기 자신
		return V[0];

	GCD= getGCD(V[1], V[0]);		//첫 번째와 두 번째 원소의 최대공약수를 구함

	for (int i = 2; i < V.size(); i++)
	{
		if (GCD < V[i])
			swap(GCD, V[i]);
		GCD = getGCD(GCD, V[i]);
	}
	return GCD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> br;

	int N, S;

	cin >> N;
	cin >> S;

	while (N--)
	{
		int i;
		cin >> i;
		br.push_back(i);
	}
	

	for (int i = 0; i < br.size(); i++)
		br[i] = abs(br[i] - S);				//거리를 절대값으로 저장

	sort(br.begin(), br.end());				//정렬
	cout << arrGCD(br);
}
