def solution(clothes):
    answer = 1
    
    di = {}
    for i in range(len(clothes)):
        kind = clothes[i][1]
        di[kind] = di.get(kind, 0) + 1
    
    # print(di)
    for num in di.values():
        answer *= (num + 1)
    
    return answer - 1