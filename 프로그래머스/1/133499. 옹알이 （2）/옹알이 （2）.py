def solution(babbling):
    answer = 0

    for word in babbling: 
        flag = True;
        prevIdx = -1
        while word:
            if (word[:3] == "aya" and prevIdx != 1):
                word = word[3:]
                prevIdx = 1
            elif (word[:2] == "ye" and prevIdx != 2):
                word = word[2:]
                prevIdx = 2
            elif (word[:3] == "woo" and prevIdx != 3):
                word = word[3:]
                prevIdx = 3
            elif (word[:2] == "ma" and prevIdx != 4):
                word = word[2:]
                prevIdx = 4
            else:
                flag = False
                break
            print(word)
        
        if (flag):
            answer += 1
        prevIdx = -1  
                
        
    return answer