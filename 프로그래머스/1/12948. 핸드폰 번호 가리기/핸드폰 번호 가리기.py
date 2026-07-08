def solution(phone_number):
    answer = ''
    li = list(phone_number)
    for i in range(len(phone_number) - 4):
        li[i] = '*'
    # print(li)
    
    return "".join(li)