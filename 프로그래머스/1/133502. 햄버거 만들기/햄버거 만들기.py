def solution(ingredient):
    answer = 0
    
    li = []
    
    for num in ingredient:
        li.append(num)
        if (li[-4:] == [1, 2, 3, 1]):
            answer += 1
            for i in range(4):
                li.pop()
    
    return answer