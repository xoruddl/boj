def solution(n, arr1, arr2):
    answer = []
    
    li = [a | b for a,b in zip(arr1, arr2)]
    
    for i in li:
        s = str(bin(i))
        s = s[2:].zfill(n)
        s = s.replace('1', '#')
        s = s.replace('0', ' ')
        answer.append(s)
        
    return answer