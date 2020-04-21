/*
요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 5,000)

1158 2초 요세푸스
*/

#include<iostream>
#include<string>
#include<queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,K,temp;
	queue<int> Q;

	cin >> N;
	cin >> K;

	for (int i = 1; i <= N; i++)
		Q.push(i);

	cout << "<";
	for (int i = 1; !Q.empty(); i++)
	{
		temp = Q.front();
		Q.pop();
		if (i % K != 0)
			Q.push(temp);
		else if (Q.empty())
			cout << temp;
		else
			cout << temp << ", ";
	}
	cout << ">";
}