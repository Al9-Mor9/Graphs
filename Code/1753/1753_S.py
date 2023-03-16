import sys
import heapq
input = sys.stdin.readline
INF = 100000000

V,E = map(int, input().split())         # 정점, 간선
start = int(input())                    # 시작 정점
data = [[] for _ in range(V+1)]         # 이동 경로 저장
for _ in range(E):
    u, v, w = map(int, input().split()) # u에서 v로 가는 가중치가 w이다
    data[u].append((v, w))
# data라는 리스트는 아래와 같이 정리된다
# [[], [(2, 2), (3, 3)], [(3, 4), (4, 5)], [(4, 6)], [], [(1, 1)]]

#==============================================================================

distance = [INF]*(V+1)                      # 최단거리테이블 초기화
q = []
def dijkstra(start):
    distance[start] = 0                     # 시작 값 방문 처리
    heapq.heappush(q,(0,start))             # 리스트 q에 튜플 값 추가 
    while q:
        dist, now_node = heapq.heappop(q)   # dist에 0, now_node에 start, 1
        for connected_node, weight in data[now_node]:   # 해당 노드와 연결된 노드 확인
            cost = dist + weight                        # 이전 값과 현재 값 더하기
            if cost < distance[connected_node]:         # 이 값이 기존의 값보다 작다면
                distance[connected_node] = cost         # 더 작은 값으로 갱신
                heapq.heappush(q,(cost,connected_node)) # 리스트 q에 현재 노드와 비용 추가

#==============================================================================

dijkstra(start)

# 결과값 출력
for i in distance[1:]:
    if i != INF:        # INF가 아니면 해당 값을 출력하고
        print(i)
    else:               # INF라면 INF 출력
        print("INF")