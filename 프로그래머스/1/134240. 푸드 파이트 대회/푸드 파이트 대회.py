def solution(food):
    answer = '0'
    for i in range(len(food) - 1, 0, -1):
        n = food[i] // 2
        while (n):
            answer = str(i) + answer + str(i)
            n -= 1
    return answer