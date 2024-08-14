#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    // 영식 요금제
    int Y = 0;
    for (int i = 0; i < N; i++) {
        Y += (v[i] / 30 + 1) * 10;
    }

    // 민식 요금제
    int M = 0;
    for (int i = 0; i < N; i++) {
        M += (v[i] / 60 + 1) * 15;
    }

    if (Y < M) {
        cout << "Y" << " " << Y;
    } else if (Y == M) {
        cout << "Y " << "M" << " " << Y;
    } else {
        cout << "M" << " " << M;
    }
    return 0;
}