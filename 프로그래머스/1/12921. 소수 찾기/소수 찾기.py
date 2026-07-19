def makePrime(arr):
    arr[0] = 0; arr[1] = 0;
    for i in range(2, int(1000003 ** 0.5) + 1):
        if (arr[i]):
            for j in range(i * i, 1000003, i):
                arr[j] = 0

def solution(n):
    answer = 0
    arr = [1 for i in range(1000003)]
    makePrime(arr)
    
    for i in range(1, n + 1):
        if (arr[i]):
            answer += 1
    return answer