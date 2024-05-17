#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int Parent[1010];
vector<pair<int, pair<int,int>>> Edge;

void Input() {
    cin >> N;

    int num;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> num;
            if (i < j) {
                Edge.push_back({num, {i, j}});
            }
        }
    }
    sort(Edge.begin(), Edge.end());
}

int find(int x) {
    if (x == Parent[x]) return x;
    else return Parent[x] = find(Parent[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    Parent[y] = x;
}

bool SameParent(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return true;
    else return false;
}

void fc() {
    for (int i = 1; i <= N; i++) {
        Parent[i] = i;
    }

    long long ans = 0;

    for (int i = 0; i < Edge.size(); i++) {
        if (!SameParent(Edge[i].second.first, Edge[i].second.second)) {
            uni(Edge[i].second.first, Edge[i].second.second);
            ans += Edge[i].first;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Input();
    if (N == 1) {
        cout << 0 << '\n';
        return 0;
    }
    fc();
    return 0;
}