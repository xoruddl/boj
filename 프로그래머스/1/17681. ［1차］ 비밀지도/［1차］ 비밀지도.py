def solution(n, arr1, arr2):
    answer = []
    
    # 두 배열을 OR연산해서 하나의 배열로 만든다.
    # 그 배열을 이진수로 바꾼다. 
    # 각 이진수 별로 1이면 #, 0이면 공백을 넣는다.
    li = [a | b for a, b in zip(arr1, arr2)]
    
    li = [bin(i) for i in li]
    print(li)
    
    ans = [[] * i for i in range(n)]
    for i in range(n):
        for j in range(len(li[i]) - 1, 1, -1):
            if (li[i][j] == '1'):
                ans[i].append('#')
            elif(li[i][j] == '0'):
                ans[i].append(' ')
                
        if (n > len(li[i]) - 2):
            for j in range(n - (len(li[i]) - 2)):
                ans[i].append(' ')
                
    # print(ans)
    for i in range(n):
        ans[i].reverse()
        ans[i] = "".join(ans[i])
    print(ans)
    
                
    return ans