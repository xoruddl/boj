def solution(n, m, section):
    answer = 0
    cur = 0
    
    for num in section:
        if (num > cur):
            cur = num + m - 1
            answer += 1
    return answer