#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // INT_MAX와 INT_MIN을 사용하기 위해 필요

using namespace std;

int R, C, N;
long long maxArea = 0;
int maxN = INT_MAX;
long long arr[100003][4]; // 0: min_row, 1: max_col, 2: max_row, 3: min_col

int main() {
    cin >> R >> C >> N;

    // 모든 유물의 배열 초기화
    for (int i = 1; i <= 100000; i++) {
        arr[i][0] = INT_MAX; // min_row
        arr[i][1] = INT_MIN; // max_col
        arr[i][2] = INT_MIN; // max_row
        arr[i][3] = INT_MAX; // min_col
    }

    for (int i = 0; i < N; i++) {
        long long a, v, h;
        cin >> a >> v >> h;

        arr[a][0] = min(arr[a][0], v); // 최소 행
        arr[a][1] = max(arr[a][1], h); // 최대 열
        arr[a][2] = max(arr[a][2], v); // 최대 행
        arr[a][3] = min(arr[a][3], h); // 최소 열
    }

    for (int i = 1; i <= 100000; i++) {
        if (arr[i][0] == INT_MAX) continue; // 해당 유물이 존재하지 않는 경우 건너뛰기

        // 유물의 면적 계산
        long long area = (arr[i][2] - arr[i][0] + 1) * (arr[i][1] - arr[i][3] + 1);

        // 더 큰 면적을 가진 유물이 있거나, 면적이 동일할 때 번호가 더 작은 유물을 선택
        if (area > maxArea || (area == maxArea && i < maxN)) {
            maxArea = area;
            maxN = i;
        }
    }

    cout << maxN << " " << maxArea << '\n';

    return 0;
}