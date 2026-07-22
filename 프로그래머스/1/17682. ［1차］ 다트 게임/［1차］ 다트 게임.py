def solution(dartResult):
    
    ans = []
    li = []
    idx = 0
    while (idx < len(dartResult)):
        if (dartResult[idx] != '1'):
            li.append(dartResult[idx])
        else:
            li.append(dartResult[idx])
            if (idx < len(dartResult) - 1 and dartResult[idx + 1] == '0'):
                li[-1] = li[-1] + '0'
                idx += 1
        idx += 1
        
    print(li)
    
    for i in range(len(li)):
        cur = li[i]
        if (cur.isdigit()):
            ans.append(int(cur))
        elif (cur == 'S'):
            continue
        elif (cur == 'D'):
            ans[-1] = ans[-1] ** 2
        elif (cur == 'T'):
            ans[-1] = ans[-1] ** 3
        elif (cur == '*'):
            ans[-1] = ans[-1] * 2
            n = len(ans)
            if (n >= 2):
                ans[n - 2] = ans[n - 2] * 2
        elif (cur == '#'):
            ans[-1] = ans[-1] - ans[-1] * 2
        
    
    return sum(ans)