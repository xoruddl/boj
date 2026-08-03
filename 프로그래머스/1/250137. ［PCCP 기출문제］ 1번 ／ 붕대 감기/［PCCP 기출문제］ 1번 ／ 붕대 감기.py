def solution(bandage, health, attacks):
    answer = 0
    maxHp = health
    
    n = len(attacks)
    lastTime = attacks[-1][0]
    attackIdx = 0 # 공격의 인덱스
    
    healCnt = 0 # 회복 누적 시간
    for i in range(lastTime + 1):
        if (i == attacks[attackIdx][0]):
            health -= attacks[attackIdx][1]
            if (health <= 0):
                return -1
            attackIdx += 1
            healCnt = 0
        else:
            # 회복하는 경우
            if (health == maxHp):
                healCnt += 1
                continue
            health += bandage[1]
            healCnt += 1
            if (healCnt == bandage[0]):
                health += bandage[2]
                healCnt = 0
            if (maxHp <= health):
                health = maxHp
            
    return health