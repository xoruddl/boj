#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[1003][5];
bool visited[1001];
int ans;
int maxFriend = -1;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {   //학생 반복
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for (int j = 0; j < 5; j++) {   // 학년 반복
            int cls = arr[i][j];
            for (int k = 0; k < N; k++) {   // 다른학생이랑 비교
                if (i == k) continue;
                if (cls == arr[k][j]) {
                    if (!visited[k]) {
                        visited[k] = 1;
                        cnt++;
                    }
                }
            }
        }

        if (maxFriend < cnt) {
            maxFriend = cnt;
            ans = i + 1;
        }
    }
    cout << ans;
}