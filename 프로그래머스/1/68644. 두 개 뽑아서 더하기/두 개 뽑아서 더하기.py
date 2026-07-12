def solution(numbers):
    answer = []
    n = len(numbers)
    
    for i in range(n - 1):
        for j in range(i + 1, n):
            answer.append(numbers[i] + numbers[j])
    s = set(answer)
    ans = list(s)
    ans.sort()
    return ans