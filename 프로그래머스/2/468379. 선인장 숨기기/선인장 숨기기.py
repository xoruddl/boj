from collections import deque

def solution(m, n, h, w, drops):
    answer = []
    MAX = 987654321
    table = [[MAX] * n for _ in range(m)]
    
    for i in range(len(drops)):
        y = drops[i][0]
        x = drops[i][1]
        table[y][x] = i + 1

    row_min = [[0] * (n - w + 1) for _ in range(m)]
    for i in range(m):
        dq = deque()
        for j in range(n):
            while (dq and table[i][dq[-1]] >= table[i][j]):
                dq.pop()
            dq.append(j)
            if (dq[0] <= j - w):
                dq.popleft()
            if (j >= w - 1):
                row_min[i][j - w + 1] = table[i][dq[0]]
    
    # print(row_min)
    result = [[0] * (n - w + 1) for _ in range(m - h + 1)]
    for j in range(n - w + 1):
        dq = deque()
        for i in range(m):
            while (dq and row_min[dq[-1]][j] >= row_min[i][j]):
                dq.pop()
            dq.append(i)
            if (dq[0] <= i - h):
                dq.popleft()
            if (h - 1 <= i):
                result[i - h + 1][j] = row_min[dq[0]][j]
    
    # print(result)
    
    tmp = [0, 0]
    tmpVal = 0
    for i in range(m - h + 1):
        for j in range(n - w + 1):
            if (result[i][j] == MAX):
                return [i, j]
            else:
                if (tmpVal < result[i][j]):
                    tmpVal = result[i][j]
                    tmp = [i, j]
    
    return tmp