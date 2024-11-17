#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int> Max;    // 작은 것들의 max값이 top
priority_queue<int, vector<int>, greater<int>> Min;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    while (N--) {
        int x;
        cin >> x;
        if (Max.empty()) {
            Max.push(x);
        }
        else if (Max.size() == Min.size()) {
            Max.push(x);
        }
        else {
            Min.push(x);
        }

        if (!Max.empty() && !Min.empty() && (Max.top() > Min.top())) {
            int a = Max.top();
            int b = Min.top();

            Max.pop();
            Min.pop();

            Max.push(b);
            Min.push(a);
        }
        cout << Max.top() << '\n';
    }
    return 0;
}