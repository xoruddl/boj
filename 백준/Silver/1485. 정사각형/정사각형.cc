#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
struct PT {
    int x, y;
};

int T;
PT p[4];
int dis[4][4];

bool cmp(PT a, PT b) {
    if (a.x < b.x) return true;
    else if (a.x == b.x) {
        if (a.y < b.y) return true;
        else return false;
    }
    else return false;
}

ll GetDist(PT a, PT b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> T;
    while (T--) {
        for (int i = 0; i < 4; i++) {
            cin >> p[i].x >> p[i].y;
        }
        sort(p, p + 4, cmp);

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (i == j) continue;
                dis[i][j] = GetDist(p[i], p[j]);
            }
        }

        if (dis[0][1] == dis[0][2] && dis[3][2] == dis[3][1] &&
            dis[0][3] == dis[1][2]) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }
    return 0;
}