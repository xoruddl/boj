#include <iostream>
#include <vector>

using namespace std;

int N, S;
vector<int> v, target;
int ans, sum;
bool visited[22];

void fc(int c, int idx, int targetSize) {
    if (c == targetSize) {
//        for (auto a : target) {
//            cout << a << " ";
//        }
//        cout << '\n';
        if (sum == S) {
            ans++;
        }
        return;
    }
    for (int i = idx; i < N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            sum += v[i];
            target.push_back(v[i]);
            fc(c + 1, i + 1,targetSize);
            sum -= v[i];
            visited[i] = 0;
            target.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v.push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        fc(0, 0, i);
    }
//    fc(0, 0, 2);
    cout << ans;
}