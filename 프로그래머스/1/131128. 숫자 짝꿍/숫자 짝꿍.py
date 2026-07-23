def solution(X, Y):
    answer = ''
    
    X = list(X)
    Y = list(Y)
    
    X.sort(reverse = True)
    Y.sort(reverse = True)
    
    i1 = 0; i2 = 0
    while (i1 < len(X) and i2 < len(Y)):
        if (X[i1] > Y[i2]):
            i1 += 1
        elif (X[i1] < Y[i2]):
            i2 += 1
        else:
            answer += X[i1]
            i1 += 1
            i2 += 1
            
    if (answer == ''):
        return "-1"
    if (answer[0] == '0'):
        return "0"
    return answer