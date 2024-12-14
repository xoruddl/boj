#include <iostream>
#include <vector>

using namespace std;

vector<int> v1;
vector<int> v2;
int N, M;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        v1.insert(v1.begin() + (a - 1), i);
    }

    while (v1.size() > M) {
        v1.pop_back();
    }

    for (int i = M - 1; i >= 0; i--) {
        int a;
        cin >> a;
        v2.insert(v2.begin() + (a - 1), v1[i]);
    }

    for (int i = 0; i < 3; i++) {
        cout << v2[i] << '\n';
    }
}
