def solution(new_id):
    answer = ''
    skips = "~!@#$%^&*()=+[{]}:?,<>/"
    # 1단계
    new_id = new_id.lower()
    
    # 2단계
    li = list(new_id)
    li = [x for x in li if x not in skips]
    
    # 3단계
    li2 = []
    for i in range(len(li)):
        if (li[i] == '.'):
            if (i == 0):
                li2.append(li[i])
            else:
                if (li2[-1] != '.'):
                    li2.append(li[i])
        else:
            li2.append(li[i])
    
    # 4단계
    if (li2 and li2[0] == '.'):
        li2 = li2[1:]
    if (li2 and li2[-1] == '.'):
        li2 = li2[:-1]
    
    # 5단계
    if (len(li2) == 0):
        li2.append('a')
        
    # 6
    if (len(li2) >= 16):
        li2 = li2[:15]
    if (li2[-1] == '.'):
        li2 = li2[:-1]
        
    # 7
    if (len(li2) <= 2):
        a = li2[-1]
        while (len(li2) <= 2):
            li2.append(a)
    
    answer = "".join(li2)
    
    return answer