def makePrime(arr):
    arr[0] = 0; arr[1] = 0;
    for i in range(2, int(3003 ** 0.5) + 1):
        if (arr[i]):
            for j in range(i * i, 3003, i):
                arr[j] = 0

def solution(nums):
    answer = 0
    n = len(nums)
    
    
    arr = [1 for i in range(3003)]
    makePrime(arr)

    temp = 0
    for i in range(n - 2):
        for j in range(i + 1, n - 1):
            for k in range(j + 1, n):
                temp = nums[i] + nums[j] + nums[k]
                if (arr[temp]):
                    print(temp)
                    answer += 1

    return answer