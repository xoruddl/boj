def solution(friends, gifts):
    di = {}
    
    n = len(friends)
    table = [[ 0 for _ in range(n)] for _ in range(n)]
    
    for i in range(len(friends)):
        di[friends[i]] = i
        
    jisu = [0 for _ in range(n)]
    
    for i in range(len(gifts)):
        line = gifts[i]
        a, b = line.split()
        ii = di[a]
        jj = di[b]
        jisu[ii] += 1
        jisu[jj] -= 1
        table[ii][jj] += 1

    answer = [0 for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            # table[i][j] vs table[j][i]
            if (table[i][j] > table[j][i]):
                answer[i] += 1
            elif (table[i][j] < table[j][i]):
                answer[j] += 1
            else:
                # 둘이 같으면 지수 비교
                if (jisu[i] > jisu[j]):
                    answer[i] += 1
                elif (jisu[i] < jisu[j]):
                    answer[j] += 1
    
    return max(answer)