#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int first[9];
int arr[9];
bool visited[9];

void fc(int x, int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }

    for (int i = x; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            arr[k] = first[i - 1];
            fc(i + 1, k + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> first[i];
    }

    sort(first, first + N);
    fc(1, 0);
}