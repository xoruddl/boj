def getCount(n):
    cnt = 0
    for i in range(1, (n // 2) + 1):
        if (n % i == 0):
            cnt += 1
    return cnt + 1 # n본인 포함

def solution(left, right):
    answer = 0
    for i in range(left, right + 1):
        if (getCount(i) % 2 == 1):
            answer -= i
        else:
            answer += i
    
    return answer