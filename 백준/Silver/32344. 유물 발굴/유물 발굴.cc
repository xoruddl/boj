#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int R, C, N;
long long arr[100003][4];
long long maxArea;
int maxN = 987654321;

int main() {
    cin >> R >> C >> N;

    for (int i = 1; i <= 100000; i++) {
        arr[i][0] = INT_MAX;
        arr[i][1] = INT_MIN;
        arr[i][2] = INT_MIN;
        arr[i][3] = INT_MAX;
    }

    int NN = N;
    while (NN--) {
        long long a, v, h;
        cin >> a >> v >> h;

        if (arr[a][0] == INT_MAX) {
            arr[a][0] = v;
            arr[a][1] = h;
            arr[a][2] = v;
            arr[a][3] = h;
        }
        else {
            arr[a][0] = min(arr[a][0], v);
            arr[a][1] = max(arr[a][1], h);
            arr[a][2] = max(arr[a][2], v);
            arr[a][3] = min(arr[a][3], h);
        }
    }

    for (int i = 1; i <= 100000; i++) {
        if (arr[i][0] == INT_MAX) continue;

        long long area = (arr[i][2] - arr[i][0] + 1) * (arr[i][1] - arr[i][3] + 1);

        if (maxArea < area || (maxArea == area && i < maxN)) {
            maxArea = area;
            maxN = i;
        }
    }
    cout << maxN << " " << maxArea;
}