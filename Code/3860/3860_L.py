import sys
sys.stdin = open("input_3860.txt", "r")

# 3860386038603860386038603860386038603860386038603860386038603860
# 오늘은 할로윈. 상근이와 친두글은 한 명씩 묘지로 들어감. 탈출해야됨.
# 탈출 최단 거리를 구해라
# 묘지는 WxH 크기의 그리드. 입구는 0, 0 출구는 W-1, H-1
# 잔디, 묘비(벽), 귀신 구멍으로 구성됨.
# 귀신 구멍? -> 묘지의 다른 장소로 들어감 + 시간이 바뀜.
# ----------------------------------------------------------------
# 여러 테스트 케이스, w, h 를 받다가 0, 0이 들어오면 멈추면 돼

"""

"""

import sys

def escape():
    global w, h
    for cnt in range(w*h):
        for r in range(w):
            for c in range(h):
                if r == w - 1 and c == h - 1 or arr[r][c] == "g":
                    continue
                elif hole[r][c]:
                    r_, c_, t = hole[r][c]
                    if arr[r_][c_] > arr[r][c] + t:
                        arr[r_][c_] = arr[r][c] + t
                        if cnt == w * h - 1: return "Never"
                else:
                    for dx, dy in dr:
                        r_ = r + dx
                        c_ = c + dy
                        if 0 <= r_ < w and 0 <= c_ < h:
                            if arr[r_][c_] != "g" :
                                if arr[r_][c_] > arr[r][c] + 1:
                                    arr[r_][c_] = arr[r][c] + 1

                                    if cnt == w * h - 1: return "Never"

    if arr[w-1][h-1] == 1e9:
        return "Impossible"
    else:
        return arr[w-1][h-1]
    
dr = [[-1, 0], [1, 0], [0, -1], [0, 1]]
while True:
    w, h = map(int, sys.stdin.readline().split())   # 너비, 높이
    if not w and not h: sys.exit()
    arr = [[1e9 for _ in range(h)] for _ in range(w)]         # 거리 저장용
    hole = [[0 for _ in range(h)] for _ in range(w)]          # 귀신 구멍 정보

    arr[0][0] = 0
    g = int(sys.stdin.readline())               # 묘비 수, 묘비의 위치
    for _ in range(g):
        x, y = map(int, sys.stdin.readline().split())
        arr[x][y] = "g"                        
    
    ghost = int(sys.stdin.readline())
    for _ in range(ghost):
        x1, y1, x2, y2, t =  map(int, sys.stdin.readline().split())
        hole[x1][y1] = [x2, y2, t]
    
    print(escape())
