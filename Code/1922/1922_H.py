import sys
sys.stdin = open('init.txt', 'r')
##### kruskal

# 특정 원소가 속한 집합의 root 찾기
def find(par, x):
    if par[x] == x:
        return x
    return find(par, par[x])


# 두 원소가 속한 집합을 합치기(간선 연결)
def union(par, a, b):
    rootA = find(par, a)
    rootB = find(par, b)
    if rootA < rootB:
        par[rootB] = rootA
    else:
        par[rootA] = rootB


v = int(input())
e = int(input())

parent = [0] * (v + 1)
edges = []
result = 0

# 부모 테이블상에서, 부모를 자기 자신으로 초기화
for i in range(1, v + 1):
    parent[i] = i

# 모든 간선에 대한 정보를 입력받기
for _ in range(e):
    a, b, cost = map(int, input().split())
    # 튜플의 첫 번째 원소를 비용으로 설정
    edges.append((cost, a, b))

edges.sort()

for edge in edges:
    cost, a, b = edge
    # 사이클이 발생하지 않는 경우에만 집합에 포함
    if find(parent, a) != find(parent, b):
        union(parent, a, b)
        result += cost
print(result)
