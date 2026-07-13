def solution(k, score):
    answer = []
    temp = []
    
    for i in range(len(score)):
        temp.append(score[i])
        
        if (len(temp) > k):
            temp.remove(min(temp))
        answer.append(min(temp))
    return answer