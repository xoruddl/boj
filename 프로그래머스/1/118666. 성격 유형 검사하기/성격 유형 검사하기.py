def solution(survey, choices):
    answer = ''
    
    di = {"R": 0, "T": 0, "C": 0, "F": 0, "J": 0, "M": 0, "A": 0, "N": 0}
    
    n = len(survey)
    for i in range(n):
        choice = choices[i]
        if (choice - 4 > 0):
            di[survey[i][1]] += choice - 4
        elif (choice - 4 < 0):
            di[survey[i][0]] += 4 - choice
    
    if (di['R'] >= di['T']):
        answer += 'R'
    else:
        answer += 'T'
        
    if (di['C'] >= di['F']):
        answer += 'C'
    else:
        answer += 'F'
    if (di['J'] >= di['M']):
        answer += 'J'
    else:
        answer += 'M'
    if (di['A'] >= di['N']):
        answer += 'A'
    else:
        answer += 'N'
    
    return answer