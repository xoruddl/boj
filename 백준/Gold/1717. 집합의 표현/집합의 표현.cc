#include <iostream>

using namespace std;

int n, m;
int p[1000003];

int find(int x) {
    if (x == p[x]) return x;
    else return find(p[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    p[y] = x;
}

bool IsSameParent(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 1000003; i++) {
        p[i] = i;
    }
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 0) {
            uni(a, b);
        }
        else {
            if (IsSameParent(a, b)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
}