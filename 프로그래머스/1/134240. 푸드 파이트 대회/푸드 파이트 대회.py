from collections import deque

def solution(food):
    answer = ''
    dq = deque()
    dq.append(0)
    
    for i in range(len(food) - 1, -1, -1):
        n = food[i] // 2
        while (n):
            dq.append(i)
            dq.appendleft(i)
            n -= 1
    
    print(dq)
    ans = [str(i) for i in dq]
    return "".join(ans)
