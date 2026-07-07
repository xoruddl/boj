def solution(x):
    answer = True
    
    li = [int(i) for i in str(x)]
    if (x % sum(li) == 0):
        answer = True
    else:
        answer = False
    return answer