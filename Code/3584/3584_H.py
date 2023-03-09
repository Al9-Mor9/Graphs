import sys
sys.stdin = open('input.txt', 'r')
#####
T = int(input())
for _ in range(T):
    n = int(input())
    # 부모 노드 저장
    par = [0] * (n + 1)
    for _ in range(n - 1):
        p, c = map(int, input().split())
        par[c] = p
    # 두 노드와 해당 노드들의 부모 노드를 루트까지 다 append
    a, b = map(int, input().split())
    a_lst = [a]
    b_lst = [b]
    while par[a]:
        a_lst.append(par[a])
        a = par[a]
    while par[b]:
        b_lst.append(par[b])
        b = par[b]
    # 찾기
    for i in range(len(a_lst)):
        if a_lst[i] in b_lst:
            print(a_lst[i])
            break
