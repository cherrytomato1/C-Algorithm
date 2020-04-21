/*팩토리얼 0의 개수는 뒷자리에 10이 몇번만큼 곱해져있는지 구하는 것
  10은 5*2이므로 팩토리얼에 곱하지는 5와 2의 곱의 개수를 구하면 된다.
  팩토리얼의 소인수를 구할 때 항상 2가 5의 개수보다 많으므로 
  5가 몇번 곱해지는지 구하면된다.*/


#include<iostream>
#include<string>
#include<vector>


using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, five=0, j;			
	//N, 5의 개수

	cin >> N; 

	for (int i = 2; i <= N; i++)		//i가 2~N 반복
	{
		j = i;
		while (j % 5 == 0)				//i가 인수 5를 포함할 경우 포함하는 갯수 구함
		{
			j /= 5;
			five++;
		}
	}

	cout << five;
}

