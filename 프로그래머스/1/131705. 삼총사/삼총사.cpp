#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> number) {
    int n = number.size();
    int bit = 7;
    int ans = 0;

    // bit를 하나씩 늘리면서 부분집합을 만들고 그 부분집합의 각 비트를 확인하면서 
    // & i == 1 이면 해당 index의 값은 포함
    int sum = 0;
    for (bit = 7; bit < pow(2, n); bit++) {
        int cnt = 0;

        // 해당 비트가 1이 3개인지 확인
        int t = 0;
        while (t <= n) {
            if (bit & (1 << t)) {
                cnt++;
            }
            t++;
        }

        if (cnt != 3) {
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                sum += number[i];
            }
        }
        if (sum == 0) {
            ans++;
        }
        sum = 0;
    }

    return ans;
}