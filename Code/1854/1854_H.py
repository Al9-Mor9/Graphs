import sys
sys.stdin = open('init.txt')
#####
import sys
import heapq

input = sys.stdin.readline
INF = int(1e8)


def dijkstra(start):
    # 시작점의 비용은 0
    dp[start][0] = 0
    q = []
    heapq.heappush(q, [0, start])
    while q:
        cost, now = heapq.heappop(q)
        for nx_node, c in arr[now]:
            nx_cost = cost + c
            # dp에 특정 노드까지 거리가 저장된 리스트 중 제일 마지막 값은 가장 큼
            if nx_cost < dp[nx_node][K-1]:
                dp[nx_node][K-1] = nx_cost
                dp[nx_node].sort()
                heapq.heappush(q, [nx_cost, nx_node])


V, E, K = map(int, input().split())
# 간선정보 저장용 arr
arr = [[] for _ in range(V + 1)]
# K번째 최단경로 저장할 2차원 리스트
dp = [[INF] * K for _ in range(V + 1)]

for _ in range(E):
    a, b, c = map(int, input().split())
    arr[a].append([b, c])

dijkstra(1)

# 출력
for i in range(1, V+1):
    if dp[i][K-1] == INF:
        print(-1)
    else:
        print(dp[i][K-1])
