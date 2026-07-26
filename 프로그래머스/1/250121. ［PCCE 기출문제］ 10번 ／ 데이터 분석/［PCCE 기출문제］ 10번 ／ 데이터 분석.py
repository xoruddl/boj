def solution(data, ext, val_ext, sort_by):
    answer = []
    columns = ["code", "date", "maximum", "remain"];
    idx = columns.index(ext);
    
    for i in range(len(data)):
        if (data[i][idx] < val_ext):
            answer.append(data[i]);
    
    
    answer.sort(key= lambda x: x[columns.index(sort_by)])
    return answer