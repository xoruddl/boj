#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> need;

void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        need.push_back(a);
    }
    cin >> M;
    sort(need.begin(), need.end());
}

void fc() {
    int start = 0;
    int end = need[N - 1];
    int sum, result;

    while (start <= end) {
        sum = 0;
        int mid = (start + end) / 2;

        for (int i = 0; i < N; i++) {
            sum += min(need[i], mid);
        }
        if (M >= sum) {
            start = mid + 1;
            result = mid;
        }
        else {
            end = mid - 1;
        }
    }
    cout << result << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    fc();
    return 0;
}