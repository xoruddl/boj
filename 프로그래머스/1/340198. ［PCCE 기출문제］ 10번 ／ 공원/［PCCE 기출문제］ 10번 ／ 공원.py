def solution(mats, park):
    answer = -1
    n = len(park)
    m = len(park[0])
    mats.sort(reverse = True)
    
    for num in mats:
        if (answer != -1):
            break
        for i in range(n):
            for j in range(m):
                if (park[i][j] == '-1'):
                    flag = True
                    for ii in range(i, i + num):
                        for jj in range(j, j + num):
                            if (flag == False):
                                break
                            if (ii < 0 or ii >= n or jj < 0 or jj >= m or park[ii][jj] != '-1'):
                                flag = False
                                break
                        if (flag == False):
                            break
                    if (flag  == True):
                        answer = num
    return answer