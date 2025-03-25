#include <iostream>
#include <vector>

using namespace std;

long N, B, C, ans;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> B >> C;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        v.push_back(a);
    }

    if (C > B) {
        for (int i = 0; i < N; i++) {
            ans += v[i] * B;
        }
        cout << ans;
        return 0;
    }

    for (int i = 0; i < N - 2; i++) {
        if (i == N - 3) {   // 마지막 3개 남아있을때
//            while (1) { // 3개 동시에 지우기
//                if (v[i] == 0 || v[i + 1] == 0 || v[i + 2] == 0) break;
//                v[i]--, v[i + 1]--, v[i + 2]--;
//                ans += (B + 2 * C);
//            }
            long x = min(v[i], min(v[i + 1], v[i + 2]));
            v[i] -= x;
            v[i + 1] -= x;
            v[i + 2] -= x;
            ans += x * (B + 2 * C);

            if (v[i] == 0) {
//                while (1) {
//                    if (v[i + 1] == 0 || v[i + 2] == 0) break;
//                    v[i + 1]--, v[i + 2]--;
//                    ans += B + C;
//                }
                x = min(v[i + 1], v[i + 2]);
                v[i + 1] -= x;
                v[i + 2] -= x;
                ans += x * (B + C);

                ans += v[i + 1] * B;
                ans += v[i + 2] * B;
            }
            else if (v[i + 1] == 0) {
                ans += v[i] * B;
                ans += v[i + 2] * B;
            }
            else {
//                while (1) {
//                    if (v[i] == 0 || v[i + 1] == 0) break;
//                    v[i]--, v[i + 1]--;
//                    ans += B + C;
//                }
                x = min(v[i], v[i + 1]);
                v[i] -= x;
                v[i + 1] -= x;
                ans += x * (B + C);

                ans += v[i] * B;
                ans += v[i + 1] * B;
            }
        }
        else {
            if (v[i] == 0) continue;
//            while (1) { // 가운데가 더 클때 일단 앞에 두개부터 처리
//                if (v[i + 1] <= v[i + 2] || v[i] == 0) break;
//                v[i]--, v[i + 1]--;
//                ans += B + C;
//            }
            long x;
            if (v[i + 1] > v[i + 2]) {
                x = min(v[i], v[i+1] - v[i+2]);
                v[i] -= x;
                v[i+1] -= x;
                ans += x * (B + C);
            }
//            while (1) {
//                if (v[i] == 0 || v[i + 1] == 0 || v[i + 2] == 0) break;
//                v[i]--, v[i + 1]--, v[i + 2]--;
//                ans += B + 2 * C;
//            }
            x = min(v[i], min(v[i+1], v[i+2]));
            v[i] -= x;
            v[i+1] -= x;
            v[i+2] -= x;
            ans += x * (B + 2 * C);

            if (v[i] != 0) {    // 3개씩 지우다가 맨 앞에 나머지 처리
                ans = ans + v[i] * B;
            }
        }
    }
    cout << ans;
    return 0;
}