def solution(lottos, win_nums):
    answer = []
    prize = [6, 6, 5, 4, 3 ,2, 1]
    
    cnt = 0; zeroCnt = 0
    for num in lottos:
        if (num in win_nums):
            cnt += 1
        elif (num == 0):
            zeroCnt += 1
            
    answer.append(prize[cnt + zeroCnt])
    answer.append(prize[cnt])
    
    return answer