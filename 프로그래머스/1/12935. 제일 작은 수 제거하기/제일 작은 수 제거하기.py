def solution(arr):
    if (len(arr) == 1):
        return [-1]
    
    target = min(arr)
    
    return [v for v in arr if v != target]