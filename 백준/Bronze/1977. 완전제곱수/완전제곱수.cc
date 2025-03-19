#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int M, N;
vector<int> v;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> M >> N;
    
    for (int i = sqrt(M); i <= sqrt(N); i++) {
        if (i * i >= M && i * i <= N) {
            v.push_back(i * i);
        }
    }
    int sum = 0;
    for (auto n : v) {
        sum += n;
    }

    if (v.size() == 0) {
        cout << -1;
    }
    else {
        cout << sum << '\n' << v[0];
    }
}