#include <iostream>
#include <algorithm>

#define MAX 8

using namespace std;

int N, M;
int arr[MAX];
int ans[MAX];
bool visited[MAX];

void fc(int k) {
    if (k == M) {
        for (int i = 0; i < M; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    else {
        for (int i = 0; i < N; i++) {
            ans[k] = arr[i];
            fc(k + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    fc(0);
}