def make(li):
    if (li[0] < li[1]):
        t = li[0]
        li[0] = li[1]
        li[1] = t

def solution(wallet, bill):
    answer = 0
    make(wallet)
    make(bill)
    
    while (1):
        wx = wallet[0]
        wy = wallet[1]
        bx = bill[0]
        by = bill[1]
        
        if (wx >= bx and wy >= by):
            break
            
        bill[0] = bx // 2
        make(bill)
        answer += 1
        
    return answer