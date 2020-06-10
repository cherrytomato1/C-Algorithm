#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

#define MAX 50

using namespace std;

int N;
char brd[MAX][MAX];

int chkrow(int row)
{
	int cnt = 1,temp= 1;
	for (int col = 1; col < N; col++)
	{
		if (brd[row][col - 1] == brd[row][col])
			temp++;
		else
		{
			cnt = max(temp, cnt);
			temp = 1;
		}
	}
	return max(cnt,temp);
}

int chkcol(int col)
{
	int cnt = 1,temp=1;
	for (int row = 1; row < N; row++)
	{
		if (brd[row - 1][col] == brd[row][col])
			temp++;
		else
		{
			cnt = max(temp, cnt);
			temp = 1;
		}
	}
	return max(cnt,temp);
}

int chkall()
{
	int cnt = 1;
	for (int col = 0; col < N; col++)
		cnt = max(chkcol(col), cnt);
	for (int row = 0; row < N; row++)
		cnt = max(chkrow(row), cnt);

	return cnt;

}

int leftChk(int row, int col)
{
	int cnt = 1;
	if (row != 0 && brd[row][col] != brd[row - 1][col])
	{
		swap(brd[row][col], brd[row - 1][col]);
		/*
		cnt = max(chkrow(row - 1), cnt);
		cnt = max(chkrow(row), cnt);
		cnt = max(chkcol(col), cnt);
		*/
		cnt = max(chkall(), cnt);
		swap(brd[row][col], brd[row - 1][col]);
	} 
	return cnt;
}

int rightChk(int row, int col)
{
	int cnt = 1;
	if (row != N-1 && brd[row][col] != brd[row + 1][col])
	{
		swap(brd[row][col], brd[row + 1][col]);

		/*
		cnt = max(chkrow(row + 1), cnt);
		cnt = max(chkrow(row), cnt);
		cnt = max(chkcol(col), cnt);
		*/

		cnt = max(chkall(), cnt);

		swap(brd[row][col], brd[row + 1][col]);
	}
	return cnt;
}

int upChk(int row, int col)
{
	int cnt = 1;
	if (col != 0 && brd[row][col] != brd[row][col - 1])
	{
		swap(brd[row][col], brd[row][col - 1]);
		/*
		cnt = max(chkrow(row), cnt);
		cnt = max(chkcol(col - 1), cnt);
		cnt = max(chkcol(col), cnt);
		*/
		cnt = max(chkall(), cnt);
		swap(brd[row][col], brd[row][col - 1]);
	}
	return cnt;
}

int downChk(int row, int col)
{
	int cnt = 1;
	if (col != N - 1 && brd[row][col] != brd[row][col+1])
	{
		swap(brd[row][col], brd[row][col+1]);
		/*
		cnt = max(chkrow(row), cnt);
		cnt = max(chkcol(col + 1), cnt);
		cnt = max(chkcol(col), cnt);
		*/
		cnt = max(chkall(), cnt);

		swap(brd[row][col], brd[row][col+1]);
	}
	return cnt;
}

int main()
{
	string input;
	int cnt=0;


	cin >>N;
	cin.ignore();

	for (int col = 0; col < N; col++)
	{
		getline(cin, input);
		for (int row = 0; row < N; row++)
			brd[row][col] = input[row];
	}

	/*
	for (int col = 0; col < N; col++)
	{
		for (int row = 0; row < N; row++)
			cout << brd[row][col];
		cout << "\n";
	}
	cout << chkall() << "\n";
	*/

	for (int col = 0; col < N; col++)
	{
		for (int row = 0; row < N; row++)
		{
			cnt = max(leftChk(row, col), cnt);
			cnt = max(rightChk(row, col), cnt);
			cnt = max(upChk(row, col), cnt);
			cnt = max(downChk(row, col), cnt);
		}
	}
	cout << cnt;
}