#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
int ans[12];
bool isFilled[12];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
    }

    ans[v[0]] = 1;
    isFilled[v[0]] = true;

    int cnt = 0;
    for (int i = 1; i < N; i++) {
        int num = v[i];
        for (int j = 0; j < N; j++) {
            if (isFilled[j]) continue;
            if (cnt == num) {
                ans[j] = i + 1;
                isFilled[j] = true;
                break;
            }
            cnt++;
        }
        cnt = 0;
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
}