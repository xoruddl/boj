def solution(numbers, hand):
    answer = ''
    d = {1: [1, 1], 2: [2, 1], 3: [3, 1],
          4: [1, 2], 5: [2, 2], 6: [3, 2],
          7: [1, 3], 8: [2, 3], 9: [3, 3],
          '*': [1, 4],  0: [2, 4], '#': [3, 4]}
    
    L = '*'
    R = '#'
    for num in numbers:
        if (num == 1 or num == 4 or num == 7):
            answer += 'L'
            L = num
        elif (num == 3 or num == 6 or num == 9):
            answer += 'R'
            R = num
        else:
            # 왼, 오른 중에 거리 비교
            li1 = [abs(a - b) for a, b in zip(d[num], d[L])]
            dist1 = sum(li1)
            li2 = [abs(a - b) for a, b in zip(d[num], d[R])]
            dist2 = sum(li2)
            # print(dist1, dist2)
            
            if (dist1 > dist2):
                answer += 'R'
                R = num
            elif(dist1 < dist2):
                answer += 'L'
                L = num
            else:
                if (hand == "right"):
                    answer += 'R'
                    R = num
                else:
                    answer += 'L'
                    L = num
            
    return answer