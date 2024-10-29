#include <iostream>

using namespace std;

int N, M;
int arr[10];
bool visited[10];

void fc(int x) {
    if (x == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            arr[x] = i;
            visited[i] = true;
            fc(x + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    fc(0);
}