def solution(data, ext, val_ext, sort_by):
    answer = []
    n = len(data);
    targetIdx = 0;
    
    columns = ["code", "date", "maximum", "remain"]
    
    for i in range(len(columns)):
        if (columns[i] == sort_by):
            targetIdx = i;
    
    for i in range(n):
        for j in range(4):
            cur = data[i][j];
            col = columns[j];
            if (col == ext):
                if (cur < val_ext):
                    answer.append(data[i])
    
    answer.sort(key= lambda x: x[targetIdx])
    return answer