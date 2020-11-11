/*

 1. 1,2,3 으로 수를 분할하되, 연속된 수가 위치할 수 없음 . 
 2. 연속된 수 조건이 없을 때 d[n]= d[n-3]+ d[n-2] + d[n-1]
 3. 연속된 수가 존재하지 않으려면 이전 값을 더할 때 같은 수를 더한 경우의 수가 더해지지 않게 해야함
 4. 따라서 각 n 별로 끝나는 값에 따라서 경우의 수를 따로 저장해야함
 5. 점화식	d[i][1] = (d[i - 1][2] + d[i - 1][3]);						//뒤에 1을 붙이는 경우의 수는 n-1이 2로 끝난 값과 3으로 끝난 값을 더해주는 값
			d[i][2] = (d[i - 2][1] + d[i - 2][3]);
			d[i][3] = (d[i - 3][1] + d[i - 3][2]);
 6. 재귀함수 사용시 n<100000 이므로 스택 오버플로우 발생할 수 있으므로 사용 불가
 7. mod값이 10000009 이므로 더하는 과정에서 오버플로우 발생할 수 있으므로 unsigned longlong 사용



*/




#include<iostream>

#define mod 1000000009
#define max 100000

using namespace std;


unsigned long long d[max + 1][3+1];				//문제에서 값을 % mod로 출력해야하기 때문에 더하는 과정에서 오버플로우가 발생할 수 있음

/*						재귀함수 사용의 stack overflow ( 너무 많은 함수 호출)
int f(int N,int a)
{
	if (N == 0)		return 0;

	if (d[N][a])		return d[N][a];

	switch (N)
	{
	case 1 :
		if (a == 1 || a == 0)	return 1;
		else					return 0;
	case 2:
		if (a == 2 || a == 0)	return 1;
		else					return 0;
	case 3:
		if (a == 0)				return 3;
		else					return 1;
	}

	d[N][1] = (f(N - 1, 2) + f(N - 1, 3)) % mod;
	d[N][2] = (f(N - 2, 1) + f(N - 2, 3)) % mod;
	d[N][3] = (f(N - 3, 1) + f(N - 3, 2)) % mod;

	if (!a)		return (d[N][1] + d[N][2] + d[N][3]) % mod;

	return d[N][a] % mod;

}
*/
int main()
{
	ios_base::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int N, T;

	cin >> T;
	
	d[1][1] = d[2][2] = d[3][1] = d[3][2] = d[3][3] = 1;					//계산을 위한 초기값 설정

	for (int i = 4; i <= max; i++)
	{
		d[i][1] = (d[i - 1][2] + d[i - 1][3]) % mod;						//뒤에 1을 붙이는 경우의 수는 n-1이 2로 끝난 값과 3으로 끝난 값을 더해주는 값
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % mod;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % mod;
	}

	while(T--)
	{
		cin >> N;

		//cout << f(N,0) ;

		cout << ( d[N][1] + d[N][2] + d[N][3] ) % mod <<"\n";				//결과는 1,2,3으로 끝난 모든 값을 더해서 출력

	}
}