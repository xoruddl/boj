from collections import deque

answer = []

def bin_insert(x, k):
    global answer
    l = -1
    r = len(answer)
    
    while (l + 1 < r):
        mid = (l + r) // 2
        
        if (answer[mid] < x):
            l = mid
        elif (answer[mid] > x):
            r = mid
        else:
            r = mid
            break
        
    answer.insert(r, x)
    
    if (len(answer) > k):
        answer = answer[1:]
    
    # print(answer)
    

def solution(k, score):
    global answer
    answer.append(score[0])

    n = len(score)
    # li = [0, 300]
    # li.insert(4, 400)
    # print(li)
    ans = [score[0]]
    for i in range(1, n):
        bin_insert(score[i], k)
        ans.append(answer[0])
    
    return ans