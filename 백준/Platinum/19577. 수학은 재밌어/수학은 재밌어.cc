#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int pfx(int n) {
    if (n == 1) return 1;

    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result = ((double)result / i) * (i - 1);
        }
    }
    if (n != 1) result = ((double)result / n) * (n - 1);
    return (int)result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    // 약수 저장
    for (int i = 1; i * i <= N; i++) {
        if (N % i == 0) {
            v.push_back(i);
            if (i != (N / i)) v.push_back(N / i);
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        if (v[i] * pfx(v[i]) == N) {
            cout << v[i] << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
    return 0;
}