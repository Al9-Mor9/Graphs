# 게리맨더링
import sys
sys.stdin = open('input.txt', 'r')
from collections import deque

def dfs(cnt, s, end):
    global mn
    # 종료조건
    if cnt == end:  # 재귀횟수가 목표횟수에 도달
        group1, group2 = deque(), deque()   # 그룹1, 2로 나누기
        
        # 방문 한 지점 group1, # 방문 안 한 지점 group2
        for i in range(1, N+1):
            if visited[i]:
                group1.append(i)
            else:
                group2.append(i)
        
        # 연결되어 있는지 확인
        ans1 = bfs(group1)
        if not ans1:
            return
        ans2 = bfs(group2)
        if not ans2:
            return
        
        mn = min(mn, abs(ans1-ans2))
        return
    
    # end개수에 도달하지 못 했을 때는 그 다음 구역부터 조합 더하기
    for i in range(s, N+1):
        if not visited[i]:  # 방문하지 않은 지점
            visited[i] = 1
            dfs(cnt+1, i, end)
            visited[i] = 0

def bfs(group):
    q = deque([group[0]])   # 첫 지점 enqueue
    check = [0] * (N+1)
    check[group[0]] = 1     # 방문 표시

    cnt, answer = 1, 0      # cnt: 방문 지점 수, answer: 인구 수 합
    while q:
        t = q.popleft()
        answer += nums[t]
        for i in adjL[t]:
            # 인접하고 group 안에 속하며 방문한 적이 없으면 계속 진행
            if i in group and not check[i]:
                check[i] = 1
                cnt += 1
                q.append(i)

    if cnt == len(group):
        return answer
    else:
        return 0


N = int(input())
nums = [0] + list(map(int, input().split()))    # 인구수 배열
visited = [0] * (N+1)
adjL = [[] for _ in range(N+1)]     # 인접 리스트
for i in range(1, N+1):
    x, *lst = map(int, input().split())
    for c in lst:
        adjL[i].append(c)

mn = 1000
for i in range(1, N//2 + 1):    # 1개/N-1개, 2개/N-2개, ... N//2개/N//2개 -> 조합
    visited = [0] * (N+1)
    dfs(0, 1, i)                # 현재까지 재귀 횟수, 시작지점, target 재귀횟수 

if mn == 1000:
    print(-1)
else:
    print(mn)