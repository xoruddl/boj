#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef pair<int, int> Node;

int N, L;
vector<int> v;
deque<Node> dq;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> L;
    v.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }

    dq.push_front({1, v[1]});
    cout << v[1] << " ";
    for (int i = 2; i <= N; i++) {
        Node now = {i, v[i]};

        while (!dq.empty()) {
            Node tmp = dq.back();

            if (tmp.second >= now.second) {
                dq.pop_back();
            } else {
                break;
            }
        }

        dq.push_back(now);

        if (now.first - dq.front().first >= L) {
            dq.pop_front();
        }
        cout << dq.front().second << " ";
    }
}