#include <string>
#include <vector>
#include <iostream>
using namespace std;

#define MAX 987654321987654321

typedef long long ll;

bool fc(ll num, int n, const vector<int>& times) {
    // 모든 인원을 다 처리 가능하면 true, 아니면 false
    ll cnt = 0;
    for (auto t: times) {
        cnt += num / t;
    }
    return cnt >= n;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    ll l = 0, r = MAX;
    
    ll mid = 0;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        
        if (fc(mid, n, times)) {
            // 다음 범위를 더 작은 쪽으로
            r = mid;
        } else {
            // 다음 범위를 더 큰 쪽으로
            l = mid;
        }
    }
    return r;
}