def solution(s):
    answer = []
    n = len(s)
    di = {}
    for i in range(n):
        cur = s[i]
        if (cur not in di):
            di[cur] = i
            answer.append(-1);
        else:
            answer.append(i - di[cur])
            di[cur] = i
    
    return answer