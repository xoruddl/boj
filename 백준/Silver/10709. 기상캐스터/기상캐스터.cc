#include <iostream>
#include <algorithm>

using namespace std;

int H, W;
char MAP[103][103];
int ans[103][103];

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> MAP[i][j];
        }
    }


    int cnt = 0;
    for (int i = 0; i < H; i++) {
        cnt = 0;
        bool flag = false;
        for (int j = 0; j < W; j++) {
            if (flag == false) {
                ans[i][j] = -1;
            }
            if (MAP[i][j] == 'c') {
                cnt = 0;
                ans[i][j] = 0;
                flag = true;
                cnt++;
            }
            if (flag && MAP[i][j] == '.') {
                ans[i][j] = cnt;
                cnt++;
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}