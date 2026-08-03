def solution(video_len, pos, op_start, op_end, commands):
    answer = ''
    
    vl = int(video_len[:2]) * 60 + int(video_len[3:5])
    ps = int(pos[:2]) * 60 + int(pos[3:5])
    os = int(op_start[:2]) * 60 + int(op_start[3:5])
    oe = int(op_end[:2]) * 60 + int(op_end[3:5])
    
    if (ps >= os and ps <= oe):
        ps = oe
    
    for com in commands:
        if (com == "next"):
            ps += 10
        elif (com == "prev"):
            ps -= 10
        
        if (ps < 0):
            ps = 0
        if (ps > vl):
            ps = vl
        if (ps >= os and ps <= oe):
            ps = oe
    
    m = ps // 60
    if (m == 0):
        Min = "00"
    elif (m < 10):
        Min = "0" + str(m)
    else:
        Min = str(m)
        
    s = ps % 60
    if (s == 0):
        Sec = '00'
    elif (s < 10):
        Sec = '0' + str(s)
    else:
        Sec = str(s)
    
    answer = Min + ":" + Sec
    
    return answer