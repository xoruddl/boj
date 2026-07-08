def solution(n):
    answer = ''
    t = "수박"
    tt = "수"
    
    if (n % 2 == 1):
        answer = t * (n // 2) + tt
    else:
        answer = t * (n // 2)
    return answer