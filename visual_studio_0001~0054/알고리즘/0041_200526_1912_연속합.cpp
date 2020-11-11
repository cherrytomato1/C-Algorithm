/*
	연속합
	1. 가장 합이 큰 연속된 숫자들의 수열, 그 수의 합을 구하여라~!!
	2. 연속된 수를 더할 때마다 그 값을 기록하여 합과 그 다음 인덱스 값을 더함
	3. 더했을 때 인덱스에 저장된 수보다 합이 작을 경우 그 합은 지금 계산하는 값의 인덱스 값으로 저장
	4. 매 합을 구할때마다 크기를 비교하여 최종 출력 시 가장 큰 값을 출력
*/




#include<iostream>
#include<algorithm>

#define MAX 100000
#define num 0
#define sum 1

using namespace std;

int d[MAX][2];					//값, 합을 저장하기 위한 이중배열

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, res;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> d[i][num];




	for (int i = 0; i < N; i++)
	{
		if (!i)				//0번째 인덱스, 비교할 값이 없는 경우
		{
			d[i][sum] = d[i][num];
			res = d[i][num];
		}
		if (d[i][num] > (d[i - 1][sum]+d[i][num]))			//더해지는 값이 현재까지 더한값+더해지는 값보다 클 경우(ex음수)
			d[i][sum] = d[i][num];							//합은 더해지는 값으로 지정
		else
			d[i][sum] = d[i - 1][sum] + d[i][num];			//아닐경우 합산
		res = max(res, d[i][sum]);							//결과를 매번 비교
	}

	cout<< res;
}/*
	연속합
	1. 가장 합이 큰 연속된 숫자들의 수열, 그 수의 합을 구하여라~!!
	2. 연속된 수를 더할 때마다 그 값을 기록하여 합과 그 다음 인덱스 값을 더함
	3. 더했을 때 인덱스에 저장된 수보다 합이 작을 경우 그 합은 지금 계산하는 값의 인덱스 값으로 저장
	4. 매 합을 구할때마다 크기를 비교하여 최종 출력 시 가장 큰 값을 출력
*/




#include<iostream>
#include<algorithm>

#define MAX 100000
#define num 0
#define sum 1

using namespace std;

int d[MAX][2];					//값, 합을 저장하기 위한 이중배열

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, res;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> d[i][num];




	for (int i = 0; i < N; i++)
	{
		if (!i)				//0번째 인덱스, 비교할 값이 없는 경우
		{
			d[i][sum] = d[i][num];
			res = d[i][num];
		}
		if (d[i][num] > (d[i - 1][sum]+d[i][num]))			//더해지는 값이 현재까지 더한값+더해지는 값보다 클 경우(ex음수)
			d[i][sum] = d[i][num];							//합은 더해지는 값으로 지정
		else
			d[i][sum] = d[i - 1][sum] + d[i][num];			//아닐경우 합산
		res = max(res, d[i][sum]);							//결과를 매번 비교
	}

	cout<< res;
}