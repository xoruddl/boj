#include <iostream>
#include <vector>
using namespace std;

int parent[53];
int N, M;
int tNum;
vector<int> trueMan;
vector<vector<int>> party;

int find(int x) {
    if (parent[x] == x) {
        return x;
    } else return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
    int px = find(x);
    int py = find(y);

    if (px > py) {
        parent[px] = parent[py];
    }
    else {
        parent[py] = parent[px];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    for (int i = 1; i < 51; i++) {
        parent[i] = i;
    }

    cin >> N >> M;

    party.resize(M);

    cin >> tNum;
    for (int i = 0; i < tNum; i++) {
        int a;
        cin >> a;
        trueMan.push_back(a);
        parent[a] = 0;
    }

    for (int i = 0; i < M; i++) {
        int n;
        cin >> n;

        int a1;
        cin >> a1;
        party[i].push_back(a1);

        for (int j = 1; j < n; j++) {
            int a;
            cin >> a;
            party[i].push_back(a);
            uni(find(a1), find(a));
        }
    }

    int ans = M;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < party[i].size(); j++) {
            int temp = find(party[i][j]);
            if (temp == 0) {
                ans--;
                break;
            }
        }
    }
    
    cout << ans;
    return 0;
}