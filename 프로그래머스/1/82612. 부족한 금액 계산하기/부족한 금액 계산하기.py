def solution(price, money, count):
    answer = 0
    val = price * (count / 2 * (count + 1))

    return val - money if val - money > 0 else 0