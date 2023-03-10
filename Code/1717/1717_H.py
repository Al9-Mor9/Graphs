import sys
sys.stdin = open('input.txt', 'r')
##### union-find
import sys
sys.setrecursionlimit(1000000)
input = sys.stdin.readline

def find(node):     # root node 찾을 때 까지 재귀 반복
    if node == parent[node]:
        return node
    root = find(parent[node])   # node의 root 노드 찾기
    parent[node] = root         # 부모 갱신
    return root


def union_root(x, y):   # x, y 의 루트 찾아와서
    x = find(x)
    y = find(y)
    if x == y:
        return
    elif x < y:     # y가 더 크면 y 밑에 x 연결
        parent[y] = x
    else:
        parent[x] = y


n, m = map(int, input().split())
parent = [i for i in range(n + 1)]
# print(parent)
# print()
for _ in range(m):
    a, b, c = map(int, input().split())
    if a:
        if find(b) == find(c):
            print('YES')
        else:
            print('NO')
    else:
        union_root(b, c)
        # print(parent)