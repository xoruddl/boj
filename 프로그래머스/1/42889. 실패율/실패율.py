def solution(N, stages):
    answer = []
    di = {}
    
    for i in stages:
        di[i] = di.get(i, 0) + 1
    
    total = len(stages)
    result = []
    for i in range(1, N + 1):
        if total == 0:
            result.append([0, i])
        else:
            result.append([di.get(i, 0) / total, i])
            total -= di.get(i, 0)
    
    result.sort(key = lambda x: (-x[0], x[1]))

    answer = [x[1] for x in result]
    
    return answer