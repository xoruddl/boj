#include <iostream>
#include <algorithm>

using namespace std;

bool visited[27] = {false,};
int R, C;
char alphabet[21][21];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans;

void Input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> alphabet[i][j];
        }
    }
}

void dfs(int x, int y, int cnt) {
    ans = max(ans, cnt);

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
            if (visited[alphabet[nx][ny] - 'A'] == false) {
                visited[alphabet[nx][ny] - 'A'] = true;
                dfs(nx, ny, cnt + 1);
                visited[alphabet[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main()
{
    Input();

    visited[alphabet[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    cout << ans;
    return 0;
}