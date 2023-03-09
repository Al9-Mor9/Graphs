import sys
sys.stdin = open("input.txt", "r")
n, m = map(int, sys.stdin.readline().split())
distance = [5e6] * (n + 1)
distance[1] = 0

q = []
for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    q.append([a, b, c])

for v in range(1, n + 1):
    print("------------")
    print("v is...", v)
    for e in q:
        cur, next, cost = e[0], e[1], e[2]
        if distance[cur] != 5e6 and\
            distance[next] > distance[cur] + cost :
            print(distance)
            distance[next] = distance[cur] + cost
            if v == n:
                print(-1)
                sys.exit()

for v in range(2, n + 1):
    if distance[v] == 5e6:
        print(-1)
    else:
        print(distance[v])