def fc(diffs, times, limit, m):
    # 고른 mid 값이 유효하면 true, 아니면 false
    totalTime = 0
    time_prev = 0
    n = len(diffs)
    
    for i in range(n):
        gap = m - diffs[i]
        time_cur = times[i]
        if (gap >= 0):
            totalTime += time_cur
        else:
            # 여기에서 gap을 양수로 줬어야 했는데 계속 음수로 줘서 틀림
            totalTime += (-gap) * (time_prev + time_cur) + time_cur
        time_prev = time_cur
    
    if (totalTime <= limit):
        return True
    else:
        return False
            

def solution(diffs, times, limit):
    
    l = 0
    r = 10 ** 15 + 1
    
    # 이분탐색
    while (l + 1 < r):
        mid = (l + r) // 2
        
        # level을 낮춰도 괜찮음
        if (fc(diffs, times, limit, mid)):
            r = mid
            
        # 해당 level 보다는 높아야함
        else:
            l = mid
    
    return r