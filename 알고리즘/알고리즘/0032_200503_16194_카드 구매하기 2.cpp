/*
	1.카드를 가장 낮은 가격으로 구매해야할 때 카드를 구매할 경우의 수를 구해야함
	2. 카드 구매 경우의 수 = d(N) = d(N), d(N-1)+d(1), d(N-2) +d(2) ... d(N-i)+d(i)
	3. 위의 모든 경우의 수 중 가장 작은 값이 d(N)으로 구매할 수 있는 최저 가격


*/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int cost[1001];
int minCost[1001];

int pay(int N)					//재귀함수
{
	if (N == 0) return 0;					//pay(N)일 경우 0 반환
	if (N == 1)	return cost[1];				//pay(1)일 경우 1장을 구매하는 값 반환

	if (minCost[N] == 0)					//해당 카드를 구매할 수 있는 최저 가격이 책정이 안된경우
		minCost[N] = cost[N];				//비교를 시작하기 위해 해당 카드를 그냥 구매할 경우의 값 입력
	else									//이미 책정된 경우 추가연산 방지용 리턴
		return minCost[N];


	for (int i = 1; i < N; i++)				//d(N)=min(d(N),d(N-1)+d(1),d(N-2)+d(2) ..... d(N-i), d(i))
		minCost[N] = min(minCost[N], pay(N - i) + pay(i));
	return minCost[N];						//해당 카드를 구매하는데 필요한 가장 작은 값 리턴
}

int main()
{
	/*ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);
	*/
	//아래 구문에서 getc(C의 입력함수)를 사용 했기 때문에 sync_with_stdio 사용불가능

	int N, T = 1;

	cin >> N;

	do {

		cin >> cost[T++];
	} while (getc(stdin) == ' ');

	cout << pay(N);
}