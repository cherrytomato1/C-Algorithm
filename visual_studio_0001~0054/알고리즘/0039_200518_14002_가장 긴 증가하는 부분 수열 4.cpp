/*
	0. 가장 긴 증가하는 부분 수열 4 은 가장 긴 증가하는 부분 수열 1에서 해당 수열을 출력하면 된다
	0-1 가장 긴 증가하는 부분 수열 1 처럼 알고리즘을 짜고 해당하는 숫자가 어떤 것인지 알기 위해 인덱스르 저장할 배열 속성을 추가함

	1.마지막으로부터 검사할 때 검사하는 해당 수보다 뒤에 해당 수보다 큰 수가 있으면 그 수의 수열 크기와 그 수가 저장되는 인덱스를 받는다
	2.해당 수 뒤의 모든 값을 비교했을 때 가장 큰 수열을 갖는 값의 인덱스와 수열 크기를 받아서 저장한다
	3. 2를 모든 수에 반복한다
	4. 결과 출력 시 인덱스를 따라가면서 출력해야 하므로 결과 값도 배열로 저장한다.
	5. 매 하나의 수를 반복할 때마다 최대 수열과 그 수의 인덱스를 저장한다.
*/

#include<iostream>
#include<algorithm>

#define NUM 0
#define CNT 1
#define NextIND 2

using namespace std;

int d[1000][3];
int res[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,temp;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> d[i][NUM];

	for (int i = N - 1; i >= 0; i--)						//마지막부터 첫번째 값까지 검사
	{
		if (i == N - 1)										//맨 마지막 값의 경우 다음으로 큰 수 index는 NULL, 수열 크기는 1
		{
			d[i][CNT]++;
			d[i][NextIND] = NULL;
		}
		else
		{
			for (int j = i; j < N; j++)						// i 부터 마지막 인덱스까지 반복
			{
				if (d[i][NUM] < d[j][NUM] && d[i][CNT] < d[j][CNT])			//숫자가 크면서, 수열크기도 클 경우
				{
					d[i][CNT] = d[j][CNT];									//최대 수열 크기를 받는다.

					d[i][NextIND] = j;										//받아온 수의 인덱스를 저장한다
				}
			}
			d[i][CNT] ++;									//자기 자신을 포함하므로 +1
		}

		if (res[CNT] < d[i][CNT])							//매 반복마다 최대 수열 크기를 비교 , 검사한 수가 최대 수열일 경우
		{
			res[CNT] = d[i][CNT];							//최대 수열 크기 갱신
			res[NextIND] = i;								//받아온 수의 인덱스를 갱신
		}
	}

	cout << res[CNT]<< "\n";								//최대 수열 크기 출력

	for (int i = 0, temp = res[NextIND]; i < res[CNT]; i++)	//결과 값에 저장된 인덱스부터 수열 크기만큼 인덱스를 넘어가면서 출력
	{
		cout << d[temp][NUM] << " ";
		temp = d[temp][NextIND];
	}
}