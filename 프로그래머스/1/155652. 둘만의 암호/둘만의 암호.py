def solution(s, skip, index):
    answer = ''
    
    # skip을 아스키 코드로
    skips = []
    for c in skip:
        skips.append(ord(c))
    
    for c in s:
        cnt = 0; i = 0
        while (cnt < index):
            cnt += 1;
            i += 1
            # pass인지 아닌지 판단
            nextC = (ord(c) + i - 97) % 26 + 97
            if (nextC in skips):
                cnt -= 1
        
        answer += chr(nextC)
        
    return answer