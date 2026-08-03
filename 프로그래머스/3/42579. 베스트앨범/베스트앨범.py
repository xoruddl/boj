def solution(genres, plays):
    answer = []
    d1 = {} # 장르별 총합
    d2 = {} # 각 장르별 재생횟수
    n = len(genres)
    
    for i in range(n):
        g = genres[i]
        p = plays[i]
        d1[g] = d1.get(g, 0) + p;
        if (g not in d2):
            d2[g] = [(p, i)]
        else:
            d2[g].append((p, i))
        
    for (k, v) in sorted(d1.items(), key= lambda x: x[1], reverse = True):
        for (p, i) in sorted(d2[k], key = lambda x: (-x[0], x[1]))[:2]:
            answer.append(i)
    

    return answer