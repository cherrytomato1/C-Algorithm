/*조합 0의 개수 

1. 조합은 nCr  =  n(n-1)(n-2)(n-3).... (n-(r-1) / r(r-1)(r-2).... 3*2*1
1-2 .  nCr = n! / (n-m)!*m!
2. 끝자리 0의 개수는 결과에 5*2가 행해진 횟수 
3. 따라서 모든 식의 2 및 5의 수를 곱한 뒤 2와 5중 더 적게 곱해진 것이 0의 개수




*/


#include<iostream>
#include<string>
#include<vector>


using namespace std;

pair<long long, long long> calc(long long n)			//n!의 2의 개수와 5의 개수를 구하는 함수
{
	pair <long long, long long > res;
	long long Five= 0 , Two= 0 ;

	for (long long i = 5; i <= n; i *= 5)				// 5의 개수 
		Five += n / i;						

	for (long long i = 2; i <=n; i *= 2)		// 2의 개수 
		Two += n / i;

	res.first = Two;						
	res.second = Five;
	return res;									//2의 개수 및 5의 개수 리턴
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	pair <long long, long long> pair1, pair2, pair3;

	long long  n, m;

	int two, five;
	
	cin >> n; 
	cin >> m;

	pair1 = calc(n);				//n! 의 2 , 5 개수
	pair2 = calc(n - m);			//n!-m!
	pair3 = calc(m);				//m!

	two = pair1.first - pair2.first - pair3.first;						//최종 2의 개수 및 5의 개수 ㄴ
	five = pair1.second - pair2.second - pair3.second;			

	cout << (two > five ? five : two);						//더 작은 쌍이 0이 개수


}