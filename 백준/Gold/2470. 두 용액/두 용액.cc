#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> liquid;
int result = 2000000000, ans1, ans2;

void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        liquid.push_back(a);
    }
    sort(liquid.begin(), liquid.end());
}

void fc() {
    int start, end;
    start = 0;
    end = N - 1;
    int sum;

    while (start < end) {
        sum = liquid[start] + liquid[end];  // 두 수의 합의 절댓값
        if (result >= abs(sum)) {
            result = abs(sum);
            ans1 = liquid[start];
            ans2 = liquid[end];
            if (sum == 0) break;
        }
        if (sum > 0) {
            end--;
        }
        if (sum < 0) {
            start++;
        }
    }
    cout << ans1 << " " << ans2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    fc();

    return 0;
}