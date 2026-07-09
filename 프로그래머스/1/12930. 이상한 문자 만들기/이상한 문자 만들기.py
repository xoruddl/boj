def solution(s):
    answer = ''
    l = list(s)
    
    cnt = 0;
    for i in range(len(l)):
        if (l[i] == ' '):
            answer += " "
            cnt = 0
            continue
        
        if (cnt & 1):
            answer += l[i].lower()
        else:
            answer += l[i].upper()
            
        cnt += 1
    return answer