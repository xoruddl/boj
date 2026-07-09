def gcd(a, b):
    for i in range(min(a, b), 0, -1):
        if (a % i == 0 and b % i == 0):
            return i

def solution(n, m):
    ans = []
    g = gcd(n, m)
    ans.append(g)
    # print(ans)
    ans.append(n * m / g)
    
    return ans