import sys
sys.stdin = open('init.txt', 'r')
#####
import sys
input = sys.stdin.readline
sys.setrecursionlimit(int(1e5))
LIMIT = 20  # 최대 크기

# 루트 노드부터 깊이(depth)를 구하는 함수
def dfs(now, d):    # now : 현재 노드, d : 현재 깊이
    visited[now] = True
    depth[now] = d
    for child_node in adj_nodes[now]:
        if not visited[child_node]: # 이미 깊이를 구했다면 넘기기
            par[child_node][0] = now
            dfs(child_node, d + 1)


def setpar():
    dfs(1, 0)  # 루트노드부터 부모노드 설정
    for i in range(1, LIMIT):
        for j in range(1, n + 1):
            ##??????????????????????????##
            par[j][i] = par[par[j][i-1]][i-1]


# A와 B의 최소 공통 조상을 찾는 함수
def lca(a, b):
    if depth[a] > depth[b]:
        a, b = b, a

    # 먼저 깊이(depth)가 동일하도록
    ##?????????????????????????????##
    for i in range(LIMIT-1, -1, -1):
        if depth[b] - depth[a] >= (1 << i):
            b = par[b][i]
    # 부모가 같아지도록
    if a == b:
        return a
    for i in range(LIMIT-1, -1, -1):
        # 조상을 향해 거슬러 올라가기
        if par[a][i] != par[b][i]:
            a = par[a][i]
            b = par[b][i]
    # 이후에 부모가 찾고자 하는 조상
    return par[a][0]


#####
n = int(input())
par = [[0] * LIMIT for _ in range(n + 1)]     # 부모 노드 정보
depth = [0] * (n + 1)       # 깊이
visited = [0] * (n + 1)       # 방문여부
adj_nodes = [[] for _ in range(n + 1)]  # 각 노드 정보

# 노드 정보 업데이트
for _ in range(n - 1):
    n1, n2 = map(int, input().split())
    adj_nodes[n1].append(n2)
    adj_nodes[n2].append(n1)

setpar()

m = int(input())
for i in range(m):
    A, B = map(int, input().split())
    print(lca(A, B))
