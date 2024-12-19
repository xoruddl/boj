#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N, M, Q;
vector<int> e;
string c;
int x, y;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        e.push_back(a);
    }
    for (int i = 0; i < Q; i++) {
        cin >> c;
        if (c == "reset") {
            cin >> x;
        }
        else {
            cin >> x >> y;
        }

        if (c == "assign") {
            e[x - 1] = e[y - 1];
        }
        else if (c == "swap") {
            int temp = e[x - 1];
            e[x - 1] = e[y - 1];
            e[y - 1] = temp;
        }
        else if (c == "reset") {
            e[x - 1] = 0;
        }
    }

    set<int> s;
    for (int i = 0; i < M; i++) {
        if (e[i] != 0) {
            s.insert(e[i]);
        }
    }

    cout << s.size() << '\n';
    for (auto p : s) {
        cout << p << '\n';
    }
}
