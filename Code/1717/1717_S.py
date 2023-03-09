n,m = map(int, input().split())         # 집합 개수, 계산 횟수
parent_lst = [i for i in range(n+1)]    # 처음 입력 되는 배열 받기

def Union(x,y):                         # 합집합 만드는 함수
    x = Find(x)
    y = Find(y)                         # x,y 루트 노드 찾기
    if x > y:                           
        parent_lst[x] = y               # x의 부모를 y로 만들어 합치기
    else:
        parent_lst[y] = x

def Find(z):                            # 포함관계 확인하는 함수
    if parent_lst[z] == z:              # 해당 값이 루트면 해당 값 리턴
        return z

    # 아니라면, 루트 노드를 찾아야 한다
    parent_lst[z] = Find(parent_lst[z]) # 해당 값의 부모를 find(parent_lst[z])로 바꾸어 주기
    return parent_lst[z]

for i in range(m):
    a, b, c = map(int, input().split()) # 값들 입력 받기
    # a는 union, find 중 하나/ b,c 는 집합 
    if a == 0:                  # 합치는 연산
        Union(b,c)
    else:                       # b,c가 같은 집합에 포함되어 있는지 확인하는 연산
        if Find(b) == Find(c):
            print('yes')
        else:
            print('no')
