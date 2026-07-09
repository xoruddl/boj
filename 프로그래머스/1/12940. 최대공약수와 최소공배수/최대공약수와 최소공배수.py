def gcd(a, b):
    if (b == 0):
        return a
    return gcd(b, a % b)

def solution(n, m):
    ans = []
    g = gcd(n, m)
    ans.append(g)
    # print(ans)
    ans.append(n * m / g)
    
    return ans