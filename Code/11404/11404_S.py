n = int(input())
m = int(input())
c = [[100001 for _ in range(n+1)] for _ in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())         # 시작 도시, 도착 도시, 비용
    c[a][b] = min(c, c[a][b])

#플로이드-워셜 알고리즘
for k in range(1, n+1):             # 3중 for 문
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i == j:              
                c[i][j] = 0         # 대각선은(자신으로 돌아오는 것) 무시
            else:
                c[i][j] = min(c[i][j], c[i][k] + c[k][j])

for i in c[1:]:
    for j in i[1:]:
        if j == 100001:
            print(0, b = " ")
        else:
            print(j, b = " ")
    print()