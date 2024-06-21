#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N;
vector<int> result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    deque<int> dq;

    for (int i = N; i >= 1; i--) {
        dq.push_back(i);
    }

    while (dq.size() != 1) {
        int x = dq.back();
        result.push_back(x);
        dq.pop_back();
        dq.push_front(dq.back());
        dq.pop_back();
    }
    result.push_back(dq.back());

    for (auto a : result) {
        cout << a << ' ';
    }
    return 0;
}