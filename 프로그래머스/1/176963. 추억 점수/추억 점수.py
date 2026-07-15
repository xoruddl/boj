def solution(name, yearning, photo):
    answer = []
    
    di = {name1: score for name1,score in zip(name, yearning)}
    print(di)
    
    for i in range(len(photo)):
        ans = 0
        for j in range(len(photo[i])):
            cur = photo[i][j]
            ans += di.get(cur, 0)
        answer.append(ans)
    return answer