/*
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.


10845 큐 0.5초
*/

#include <iostream>
#include <string>

using namespace std;


struct listNode {
	listNode* nNode;
	int var;
};
struct listHead {
	int index;
	listNode* hNode;
};

listHead* createHead()
{
	listHead * L;
	L = (listHead*)malloc(sizeof(listHead));
	L->hNode = NULL;

	return L;
}

listNode* addNode(listHead* L,listNode* preNode)
{
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));

	if (L->hNode == NULL)
		L->hNode = newNode;
	else
		preNode->nNode = newNode;
	newNode->nNode = NULL;

	return newNode;
}

void delHeadNode(listHead* L, listNode* node)
{
	L->hNode = node->nNode;

	free(node);
}

void push(listHead* L,int param)
{
	listNode* temp;

	if (L->hNode != NULL)
	{
		for (temp = L->hNode; temp->nNode != NULL; temp = temp->nNode);
		temp = addNode(L, temp);
	}
	else
		temp = addNode(L, NULL);

	temp->var = param;
}

void pop(listHead* L)
{
	listNode* temp;

	if (L->hNode == NULL)
	{
		cout << "-1"<<"\n";
		return ;
	}
	temp = L->hNode;
	L->hNode = temp->nNode;
	cout << temp->var << "\n";
	free(temp);
}

void lSize(listHead* L)
{
	listNode* temp;
	int size=1;

	if (L->hNode == NULL)
		cout << "0" << "\n";
	else
	{
		for (temp = L->hNode; temp->nNode != NULL; temp = temp->nNode)
			size++;
		cout << size << "\n";
	}
}

void empty(listHead* L) {
	if (L->hNode == NULL)
		cout << "1" << "\n";
	else
		cout << "0" << "\n";
}

void back(listHead* L)
{
	listNode* temp;

	if (L->hNode == NULL)
		cout << "-1" << "\n";
	else
	{
		for (temp = L->hNode; temp->nNode != NULL; temp = temp->nNode);
		cout << temp->var << "\n";
	}
}

void front(listHead* L)
{
	if (L->hNode == NULL)
		cout << "-1" << "\n";
	else
		cout << L->hNode->var << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int T,param;
	string cmd;
	listHead* L;

	cin >> T;
	cin.ignore();

	L = createHead();

	while (T--)
	{
		cin >> cmd;
		
		if (cmd == "push")
		{
			cin >> param;
			push(L, param);
		}
		else if (cmd == "pop")
			pop(L);
		else if (cmd == "size")
			lSize(L);
		else if (cmd == "empty")
			empty(L);
		else if (cmd == "front")
			front(L);
		else if (cmd == "back")
			back(L);
		
	}
}