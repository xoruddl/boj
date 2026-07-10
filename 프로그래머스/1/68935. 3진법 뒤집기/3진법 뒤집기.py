def solution(n):
    answer = 0
    tempList = []
    while (n):
        tempList.append(n % 3)
        n = n // 3
        
    tempList.reverse() 
    
    for i in range(len(tempList)):
        answer += tempList[i] * (3 ** i)
    
    return answer