def solution(arr):
    arr.remove(min(arr))
    # print(arr)
    return arr if len(arr) > 0 else [-1]