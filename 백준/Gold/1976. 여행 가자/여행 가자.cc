#include <iostream>

using namespace std;

int N, M;
int p[203];

int find(int x) {
    if (x == p[x]) return x;
    else return p[x] = find(p[x]);
}

void uni(int x, int y) {
    x = find(x);
    y = find(y);
    p[y] = x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 203; i++) p[i] = i;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int a;
            cin >> a;
            if (a == 1) {
                uni(i + 1, j + 1);
            }
        }
    }

    int city;
    cin >> city;

    int tmp = find(city);
    bool flag = true;

    for (int i = 0; i < M - 1; i++) {
        cin >> city;
        if (tmp != find(city)) {
            flag = false;
            break;
        }
    }


    if (flag) cout << "YES";
    else cout << "NO";
}