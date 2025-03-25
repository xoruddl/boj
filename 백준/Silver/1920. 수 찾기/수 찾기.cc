#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v1, v2;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        v1.push_back(a);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        v2.push_back(a);
    }

    sort(v1.begin(), v1.end());

    for (int i = 0; i < M; i++) {
        if (binary_search(v1.begin(),v1.end(),v2[i])) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
}

