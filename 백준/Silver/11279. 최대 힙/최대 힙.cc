#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, x;
vector<int> result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x != 0) {
            pq.push(x);
        }
        else {
            if (pq.empty()) {
                result.push_back(0);
            }
            else {
                result.push_back(pq.top());
                pq.pop();
            }
        }
    }
    for (auto a : result) {
        cout << a << '\n';
    }
    return 0;
}