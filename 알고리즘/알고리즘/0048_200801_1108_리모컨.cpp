/*
	1. 채널의 수는 1 이상의 무한한 정수
	2. 초기 채널은 100, 바꾸고 싶은 채널 N <=500,000
	3. 고장난 버튼의 수 0<=M<=10, 버튼의 값 0~9

	풀이
	1. 목표 채널 N으로부터 위로 제일 가까운 채널, 아래로 제일 가까운 채널
	 1-1. 가까우면서 고장난 버튼을 포함하지 않는 채널이어야함
	    - 고장난 버튼은 벡터로 저장하여 자릿수 별로 비교하여 포함하지 않을 경우만 확인
		- 모든 버튼이 고장난 경우(M=10) 연산할 수 없음( 예외처리 및 생략 )
		- 자릿수 비교 연산 시 현재 검사 채널이 0번일 경우의 예외처리
		- N=0이고 B에 0이 포함되지 않을 경우 cnt == 0으로 나오는 경우의 예외처리

	 1-2. 가까운 채널로부터 몇 만큼 떨어져 있는지와 채널의 자릿수를 포함하여 클릭 횟수 연산
	    - 아래로 구할 경우 채널이 0 미만으로 떨어질 경우 연산하지 않음 (예외처리)
		- 위로 구할 경우 남은 버튼이 0번만 있을 시에 조건에 해당하는 채널을 구하지 못해 무한루프이므로 예외처리(M=9, B:1~9)
	2. 시작채널(100)으로부터 +-의 연산처리
	 2-1. 모든 버튼이 고장난 경우(M=10)
	 2-2. 100으로부터의 +- 연산이 더 가까운 경우

	3. 1,2번의 연산결과 중 최소 값을 갖는 cnt를 해로 구함


*/



#include<iostream>
#include<vector>
#include<algorithm>


#define MAX 500000							//N의 최대 채널 MAX(예외처리를 위해 사용)

using namespace std;

vector<int> B;								//고장난 버튼 저장 벡터(0~9)[10]
int N, M, temp;

bool chkBtn(int num)						//현재 검사 값과 고장난 버튼 검사
{
	if(num==0)								//현재 검사 값이 0일경우의 예외처리
		for (int j = 0; j < M; j++)
			if (num % 10 == B[j])
				return false;

	while (num)								//현재 검사 값을 한자리로 나누어 고장난 버튼 벡터와 비교
	{
		for (int j=0; j < M; j++)			//0~M
			if (num % 10 == B[j])			//고장 버튼의 수를 포함한 경우 false 리턴
				return false;
		num /= 10;							//자리수 옮김
	}
	return true;							//검사 통과 시 true 리턴
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt1=0, cnt2=0;
	cin >> N;
	cin >> M;

	for(int i =0; i<M;i++)
	{
		cin >> temp;
		B.push_back(temp);
	}
	
	if (M != 10)						//모든 버튼이 고장난 경우 버튼으로 채널 이동 검사 안함
	{

		for (int i = N; i <= MAX * 2; i++, cnt1++)			//목표 채널로부터 위로 검사, 남은 버튼이 0인 경우의 무한루프 방지 예외처리
			if (chkBtn(i))
			{
				if (!i)										//목표 채널이 0인 경우 자릿수 0으로 환산되는 경우의 예외처리
					cnt1++;
				while (i)									//자릿수 cnt에 추가
				{
					i /= 10;
					cnt1++;
				}
				break;
			}

		for (int i = N;; i--, cnt2++)						//목표 채널로부터 아래로 검사
		{
			if (i < 0)										//검사중 채널이 0 미만으로 갈 경우 예외처리
			{
				cnt2 = MAX;
				break;
			}
			if (chkBtn(i))
			{
				if (!i)										//목표 채널 및 검사채널이 0인경우 예외
					cnt2++;
				while (i)
				{
					i /= 10;
					cnt2++;
				}
				break;
			}

		}
	}
	else if (M == 10)										//모든 버튼이 고장난 경우 예외
	{
		cnt1 = MAX;
		cnt2 = MAX;
	}

	if (N < 100)											//목표채널이 현재채널보다 큰지 작은지에 따라 검사 방향 결정
		temp = 1;
	else
		temp = -1;

	//for (int i = N; i != 100; i += temp)					//하나씩 검사하여 목표채널로부터 버튼 수 출력
	//	cnt3++;

		
	//cout << cnt1 << ", " << cnt2 << ", " <<cnt3 << "\n";

	cout << min(cnt1, min(cnt2, abs(N-100)));
}