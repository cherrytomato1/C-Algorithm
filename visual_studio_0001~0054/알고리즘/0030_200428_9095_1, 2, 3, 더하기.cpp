/*

1. N을 1, 2, 3 더하기로 표현하는 방법은 각각 N-1 +1 , N-2 +2 , N-3 +3 의 경우의 수가 있다
2. 1,2,3 은 각각 자기 자신만으로 식이 완성될 수 있으므로 +1한다
3. 점화식 A[N] = A[N-1] +A[N-2] A+[N-3]


*/


#include<iostream>

using namespace std;

int a[12];
int sum;


int makeSum(int N)
{
	if (N == 0)		return 0;				//특수한 경우 값 리턴
	if (N == 1)		return 1;
	if (N == 2)		return 2;
	if (N == 3)		return 4;

	if (a[N] != 0)							//저장된 값이면 배열을 사용
		return a[N];

	return a[N] = makeSum(N - 3) + makeSum(N - 2) + makeSum(N - 1);			//점화식을 이용한 재귀함수 사용
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;

	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << makeSum(N)<<"\n";
	}
}/*

1. N을 1, 2, 3 더하기로 표현하는 방법은 각각 N-1 +1 , N-2 +2 , N-3 +3 의 경우의 수가 있다
2. 1,2,3 은 각각 자기 자신만으로 식이 완성될 수 있으므로 +1한다
3. 점화식 A[N] = A[N-1] +A[N-2] A+[N-3]


*/


#include<iostream>

using namespace std;

int a[12];
int sum;


int makeSum(int N)
{
	if (N == 0)		return 0;				//특수한 경우 값 리턴
	if (N == 1)		return 1;
	if (N == 2)		return 2;
	if (N == 3)		return 4;

	if (a[N] != 0)							//저장된 값이면 배열을 사용
		return a[N];

	return a[N] = makeSum(N - 3) + makeSum(N - 2) + makeSum(N - 1);			//점화식을 이용한 재귀함수 사용
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;

	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << makeSum(N)<<"\n";
	}
}