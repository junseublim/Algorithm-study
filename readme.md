# 삼성 SDS 알고리즘 특강

## 학습 노트


### Priority Queue

1. 비교연산자 : struct cmp 안에 operator() 함수 만들어서 사용
```c++
struct cmp{
    bool operator()(int t, int u){
        return t < u;
    }
};

priority_queue<int, vector<int>,cmp> pq;
```

### 비트 연산자

1. a&-a : 비트 1 중에서 최하위 비트 한개만 남긴다.
    - 1 -> 1
    - 2 -> 2
    - 3 -> 1
    - 4 -> 4
    - 5 -> 1
    - 6 -> 2
    - 7 -> 1
    - 8 -> 8
이를 활용해서 인덱스 트리 연산을 효율적으로 구할 수 있다.

### 자잘한 것들

1. 스트링 printf 출력 방법: scanf("%s", str.c_str());
2. printf float은 소수점 반올림해서 출력한다.