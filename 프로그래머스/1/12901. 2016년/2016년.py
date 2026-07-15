def solution(a, b):
    answer = ''
    
    months = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30]
    days = ["FRI","SAT", "SUN","MON","TUE","WED","THU"]
    
    cnt = 0
    for i in range(a - 1):
        cnt += months[i]
    cnt += b
    cnt -= 1
    
    answer = days[cnt % 7]
    
    return answer