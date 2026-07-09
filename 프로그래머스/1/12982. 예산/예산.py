def solution(d, budget):
    answer = 0
    d.sort()
    s = 0
    for i in d:
        if (s + i <= budget):
            s += i
            answer += 1
        else:
            break
    return answer