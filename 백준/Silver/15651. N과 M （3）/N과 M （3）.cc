#include <iostream>
#include <vector>

using namespace std;

int N, M;
bool visited[10];
vector<int> v;

void fc(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
            v.push_back(i);
            fc(cnt + 1);
            v.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    fc(0);
}