def getCount(x):
    
    cnt = 0;
    for i in range(1, int(x ** 0.5) + 1):
        if (x % i == 0):
            if (i == x // i):
                cnt += 1
            else:
                cnt += 2
    
    return cnt

def solution(number, limit, power):
    answer = 0
    
    for n in range(1, number + 1):
        c = getCount(n)
        # print(c)
        answer += c if (c <= limit) else power
    
    return answer