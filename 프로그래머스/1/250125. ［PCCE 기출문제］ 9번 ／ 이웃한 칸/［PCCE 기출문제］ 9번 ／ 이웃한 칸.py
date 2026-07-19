dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def solution(board, h, w):
    answer = 0
    n = len(board)
    curColor = board[h][w]
    
    for i in range(4):
        nx = dx[i] + w
        ny = dy[i] + h
        
        if (nx >= 0 and nx < n and ny >= 0 and ny < n):
            nColor = board[ny][nx]
            if (curColor == nColor):
                answer += 1
            
    return answer