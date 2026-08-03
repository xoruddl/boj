def fc(diffs, times, limit, m):
    # 이분 탐색: 고른 mid 값이 유효하면 true, 아니면 false
    totalTime = 0
    time_prev = 0
    n = len(diffs)
    
    for i in range(n):
        gap = m - diffs[i]
        time_cur = times[i]
        if (gap >= 0):
            totalTime += time_cur
        else:
            totalTime += (-gap) * (time_prev + time_cur) + time_cur
        time_prev = time_cur
    
    # print(totalTime)
    if (totalTime <= limit):
        return True
    else:
        return False
            

def solution(diffs, times, limit):
    
    
    
    l = 0
    r = 10 ** 15 + 1
    # mid = (l + r) // 2
    # fc(diffs, times, limit, mid)
    
    while (l + 1 < r):
        mid = (l + r) // 2
        
        # level을 낮춰도 괜찮음
        if (fc(diffs, times, limit, mid)):
            r = mid
            
        # 해당 level 보다는 높아야함
        else:
            l = mid
    
    return r