def solution(s, n):
    answer = []
    
    l = list(s)
    for c in l:
        C = ord(c)
        if (C >= 65 and C <= 90):
            answer.append(chr((C - 65 + n) % 26 + 65))
        elif (C >= 97 and C <= 122):
            answer.append(chr((C - 97 + n) % 26 + 97))
        else:
            answer.append(c)
    
    return "".join(answer)