#include <iostream>
#include <vector>

using namespace std;

int N, ans;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        v.push_back(a);
    }

    for (int i = 0; i < N - 2; i++) {
        if (i == N - 3) {   // 마지막 3개 남아있을때
            while (1) { // 3개 동시에 지우기
                if (v[i] == 0 || v[i + 1] == 0 || v[i + 2] == 0) break;
                v[i]--, v[i + 1]--, v[i + 2]--;
                ans += 7;
            }
            if (v[i] == 0) {
                while (1) {
                    if (v[i + 1] == 0 || v[i + 2] == 0) break;
                    v[i + 1]--, v[i + 2]--;
                    ans += 5;
                }
                ans += v[i + 1] * 3;
                ans += v[i + 2] * 3;
            }
            else if (v[i + 1] == 0) {
                ans += v[i] * 3;
                ans += v[i + 2] * 3;
            }
            else {
                while (1) {
                    if (v[i] == 0 || v[i + 1] == 0) break;
                    v[i]--, v[i + 1]--;
                    ans += 5;
                }
                ans += v[i] * 3;
                ans += v[i + 1] * 3;
            }
        }
        else {
            if (v[i] == 0) continue;
            while (1) { // 가운데가 더 클때 일단 앞에 두개부터 처리
                if (v[i + 1] <= v[i + 2] || v[i] == 0) break;
                v[i]--, v[i + 1]--;
                ans += 5;
            }
            while (1) {
                if (v[i] == 0 || v[i + 1] == 0 || v[i + 2] == 0) break;
                v[i]--, v[i + 1]--, v[i + 2]--;
                ans += 7;
            }
            if (v[i] != 0) {    // 3개씩 지우다가 맨 앞에 나머지 처리
                ans = ans + v[i] * 3;
            }
        }
    }
    cout << ans;
    return 0;
}
