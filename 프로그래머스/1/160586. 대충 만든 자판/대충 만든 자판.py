

def solution(keymap, targets):
    di = {}
    for i in range(len(keymap)):
        cur = keymap[i]
        for j in range(len(cur)):
            c = cur[j]
            if (di.get(c, 999) == 999):
                di[c] = j + 1
            else:
                di[c] = min(di[c], j + 1)
                
    ans = []
    for i in range(len(targets)):
        cur = targets[i]
        cnt = 0
        for j in range(len(cur)):
            c = cur[j]
            if (di.get(c, 0) == 0):
                cnt = -1
                break
            else:
                cnt += di[c]
                
        ans.append(cnt)
    
    return ans