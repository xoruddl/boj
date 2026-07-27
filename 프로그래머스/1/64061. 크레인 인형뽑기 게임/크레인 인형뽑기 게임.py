from collections import deque

def solution(board, moves):
    answer = 0
    n = len(board)
    dq = deque()
    
    for move in moves:
        pick = 0
        for i in range(n):
            if (board[i][move - 1] != 0):
                pick = board[i][move - 1]
                board[i][move - 1] = 0
                break
                
        if (pick != 0):
            if (len(dq) == 0):
                dq.append(pick)
            elif (dq[-1] == pick):
                dq.pop()
                answer += 2
            else:
                dq.append(pick)
                
    return answer