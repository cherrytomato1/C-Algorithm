# 알고리즘 공부

- Baekjoon Online judge
  - https://www.acmicpc.net/user/terec


- Solved.ac
  - https://solved.ac/profile/terec


## 시간복잡도
- 시간복잡도
  - 시간복잡도는 입력에 따라 프로그램이 동작하는 연산속도를 정의
  - 시간복잡도를 지정할 때 최악의 경우(worst case)를 기준으로 작성함
  - 각각의 연산 하나를 1로 보며 ```for(i =0 ; i< n ; i++)``` 와 같은 연산은 시간 복잡도를 n이라고 표현할 수 있음

- Big-O 표기법
  - 시간복잡도를 수식으로 표현
  - 상수는 식에서 제외, 최고차항의 계수를 갖도록 표현 (예 : n^3 + 50n^2 + 100n + 1000 -> O(n^3)
  - 시간복잡도를 고려한 알고리즘 작성이 필요
  


![complexity](https://github.com/cherrytomato1/Algorithm/blob/master/images/time_complexity.png)


## 개념

### 클래스와 구조체

- 클래스와 구조체의 차이
  - 멤버 메소드 존재의 차이
  - 상속의 유무
  - 접근 지정자 사용의 유무
  
- 구조체를 사용할 때
  - 자료형만의 정의
  - 접근 지정자를 사용할 필요가 없을 때(모든 멤버가 public으로 사용되어도 충분할 때)

## C++

### input/output

 - ```using namespace std```;
    - iostream에 정의되어있는 std namespace를 사용한다는 뜻 cin, cout등의 namespace에서 std를 생략하여 활용하기 위함
    
 - ```ios_base :: sync_with_stdio(false)```
    - c stream과 c++ stream의 동기화를 끊음, 따라서 독립적인 버퍼를 갖게되어 실행속도는 상승
    - c 와 c++의 stream을 혼용할 수 없음(scanf, cin 등) 
    
 - ```cin.tie(NULL), cout.tie(NULL)```
    - cin과 cout의 동기화를 해제(null)로 지정.
    - cin, cout은 각각의 동작에서 동기화됨으로써 buffer 및 flush를 동작 이를 해제하여 동작속도를 향상시킬 수 있음
    - 동기화 해제 시 자동으로 flush하지 않으므로 in/out stream에 버퍼가 남아 있을 수 있음
    
 https://su-m.tistory.com/7
 
 https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull
 
 
 ### STL
 
 #### Sort
 - algorithm 헤더에 포함
 
```
template <typename T>
void sort(T start, T end);

template <typename T>
void sort(T start, T end, Compare comp);
```
 - sort를 하고자하는 데이터의 시작주소와 끝 주소를 매개변수로 받음
 - quick sort 기반으로 O(nlogn)의 시간복잡도
 - 기본적으로 오름차순으로 정렬, comp 매개변수 입력으로 사용자 정의 크기 비교 알고리즘 적용가능
 
## 자료구조

### 트리
- 트리의 정의
  - 트리는 하나의 루트 노드를 가짐
  - 루트 노드를 포함한 모든 노드에서 0개의 노드를 갖고, 이것이 반복적으로 정의되는 구조
  - 트리는 사이클이 존재할 수 없는 비선형, 계층적 자료구조
  - 방향성이 있는 비순환 그래프의 한 종류

- 트리의 특징
  - 노드 N을 갖는 트리의 간선의 개수는 항상 N-1개이다( 간선의 개수는 항상 정점의 수 - 1 이다)
  - 임의의 두 노드 간의 경로의 수는 유일함 ( 정점 간 1개의 경로만 존재 )
  - 모든 노드는 단 하나의 부모 노드만을 갖는다
  - 순회는 전위 순회(pre-order), 중위 순회(in-order), 후위 순회(post-order)의 방법을 갖는다
  
  


![tree](https://github.com/cherrytomato1/Algorithm/blob/master/images/tree-terms.png)
- 트리 용어

  - 루트 노드(root node): 부모가 없는 노드, 트리는 하나의 루트 노드만을 가진다.
  - 단말 노드(leaf node): 자식이 없는 노드, 또는 ‘잎 노드’라고도 부른다.
  - 내부(internal) 노드: 단말 노드가 아닌 노드
  - 간선(edge): 노드를 연결하는 선 (link, branch 라고도 부름)
  - 형제(sibling): 같은 부모를 가지는 노드
  - 노드의 크기(size): 자신을 포함한 모든 자손 노드의 개수
  - 노드의 깊이(depth): 루트에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 수
  - 노드의 레벨(level): 트리의 특정 깊이를 가지는 노드의 집합
  - 노드의 차수(degree): 하위 트리 개수 / 간선 수 (degree) = 각 노드가 지닌 가지의 수
  - 트리의 차수(degree of tree): 트리의 최대 차수
  - 트리의 높이(height): 루트 노드에서 가장 깊숙히 있는 노드의 깊이

