#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int G, P;
int cnt;
int parent[100001];

int find(int u) {
    if (parent[u] == u) {
        return u;
    }
    return parent[u] = find(parent[u]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    if (x != y) {
        parent[x] = y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> G >> P;
    for (int i = 0; i < 100001; i++) {
        parent[i] = i;
    }

    while (P--) {
        int num;
        cin >> num;

        if (find(num) == 0) break;
        else {
            cnt++;
            uni(find(num), find(num) - 1);
        }
    }
    cout << cnt;
    return 0;
}